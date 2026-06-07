/**
 * Basic DSA - Minimum Weighted Subgraph With the Required Paths II
 * (LeetCode 3553)
 * LCA with binary lifting; answer is half the sum of three pairwise distances.
 */

#include <iostream>
#include <utility>
#include <vector>

class WeightedTreePathSolver {
public:
    explicit WeightedTreePathSolver(const std::vector<std::vector<int>>& edges) {
        const int nodeCount = static_cast<int>(edges.size()) + 1;
        int maxLevel = 1;
        while ((1 << maxLevel) < nodeCount)
            ++maxLevel;

        graph.assign(nodeCount, {});
        ancestorJump.assign(nodeCount, std::vector<int>(maxLevel, 0));
        nodeDepth.assign(nodeCount, 0);
        rootDistance.assign(nodeCount, 0);

        for (const std::vector<int>& edge : edges) {
            const int firstNode = edge[0];
            const int secondNode = edge[1];
            const int weight = edge[2];
            graph[firstNode].emplace_back(secondNode, weight);
            graph[secondNode].emplace_back(firstNode, weight);
        }

        buildTreeData(0, -1);

        for (int level = 1; level < maxLevel; ++level) {
            for (int node = 0; node < nodeCount; ++node)
                ancestorJump[node][level] =
                    ancestorJump[ancestorJump[node][level - 1]][level - 1];
        }
    }

    int minimumSubgraphWeight(int sourceOne, int sourceTwo, int destination) const {
        return (treeDistance(sourceOne, sourceTwo) +
                treeDistance(sourceOne, destination) +
                treeDistance(sourceTwo, destination)) /
               2;
    }

    std::vector<int> answerQueries(
        const std::vector<std::vector<int>>& queries) const {
        std::vector<int> answers;
        answers.reserve(queries.size());

        for (const std::vector<int>& query : queries) {
            answers.push_back(
                minimumSubgraphWeight(query[0], query[1], query[2]));
        }

        return answers;
    }

private:
    std::vector<std::vector<std::pair<int, int>>> graph;
    std::vector<std::vector<int>> ancestorJump;
    std::vector<int> nodeDepth;
    std::vector<int> rootDistance;

    void buildTreeData(int node, int parentNode) {
        for (const std::pair<int, int>& edge : graph[node]) {
            const int neighbor = edge.first;
            const int weight = edge.second;
            if (neighbor == parentNode)
                continue;

            ancestorJump[neighbor][0] = node;
            nodeDepth[neighbor] = nodeDepth[node] + 1;
            rootDistance[neighbor] = rootDistance[node] + weight;
            buildTreeData(neighbor, node);
        }
    }

    int lowestCommonAncestor(int firstNode, int secondNode) const {
        int upperNode = firstNode;
        int lowerNode = secondNode;

        if (nodeDepth[upperNode] > nodeDepth[lowerNode])
            std::swap(upperNode, lowerNode);

        const int levelCount = static_cast<int>(ancestorJump[0].size());
        for (int level = 0; level < levelCount; ++level) {
            if (((nodeDepth[lowerNode] - nodeDepth[upperNode]) >> level) & 1)
                lowerNode = ancestorJump[lowerNode][level];
        }

        if (upperNode == lowerNode)
            return upperNode;

        for (int level = levelCount - 1; level >= 0; --level) {
            if (ancestorJump[upperNode][level] != ancestorJump[lowerNode][level]) {
                upperNode = ancestorJump[upperNode][level];
                lowerNode = ancestorJump[lowerNode][level];
            }
        }

        return ancestorJump[upperNode][0];
    }

    int treeDistance(int firstNode, int secondNode) const {
        const int commonAncestor = lowestCommonAncestor(firstNode, secondNode);
        return rootDistance[firstNode] + rootDistance[secondNode] -
               2 * rootDistance[commonAncestor];
    }
};

void printAnswers(const std::vector<int>& answers) {
    std::cout << "[";
    for (int index = 0; index < static_cast<int>(answers.size()); ++index) {
        if (index > 0)
            std::cout << ",";
        std::cout << answers[index];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Weighted Subgraph With the Required Paths II\n";
    std::cout << std::string(60, '=') << "\n";

    WeightedTreePathSolver solverOne(
        {{0, 1, 2}, {1, 2, 3}, {1, 3, 5}, {1, 4, 4}, {2, 5, 6}});

    std::cout << "sample 1 -> ";
    printAnswers(solverOne.answerQueries({{2, 3, 4}, {0, 2, 5}}));
    std::cout << "\n";

    WeightedTreePathSolver solverTwo({{1, 0, 8}, {0, 2, 7}});

    std::cout << "sample 2 -> ";
    printAnswers(solverTwo.answerQueries({{0, 1, 2}}));
    std::cout << "\n";
}
