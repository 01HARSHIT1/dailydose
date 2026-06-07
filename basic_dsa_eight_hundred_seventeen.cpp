/**
 * Basic DSA - Number of Ways to Assign Edge Weights II (LeetCode 3559)
 * Binary lifting LCA; path with d edges has 2^(d-1) odd-weight assignments.
 */

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

namespace {
constexpr int kMod = 1'000'000'007;
constexpr int kMaxLevels = 17;

long long modPow(long long base, long long exponent) {
    long long result = 1;
    base %= kMod;
    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = result * base % kMod;
        base = base * base % kMod;
        exponent /= 2;
    }
    return result;
}
}  // namespace

class EdgeWeightAssignmentSolver {
public:
    explicit EdgeWeightAssignmentSolver(const std::vector<std::vector<int>>& edges) {
        const int nodeCount = static_cast<int>(edges.size()) + 1;
        graph.assign(nodeCount + 1, {});
        nodeDepth.assign(nodeCount + 1, 0);
        ancestorJump.assign(kMaxLevels, std::vector<int>(nodeCount + 1, -1));

        for (const std::vector<int>& edge : edges) {
            const int firstNode = edge[0];
            const int secondNode = edge[1];
            graph[firstNode].push_back(secondNode);
            graph[secondNode].push_back(firstNode);
        }

        buildTreeData(1, -1);

        for (int level = 1; level < kMaxLevels; ++level) {
            for (int node = 1; node <= nodeCount; ++node) {
                const int midAncestor = ancestorJump[level - 1][node];
                if (midAncestor != -1)
                    ancestorJump[level][node] = ancestorJump[level - 1][midAncestor];
            }
        }
    }

    std::vector<int> answerQueries(
        const std::vector<std::vector<int>>& queries) const {
        std::vector<int> answers;
        answers.reserve(queries.size());

        for (const std::vector<int>& query : queries) {
            const int source = query[0];
            const int destination = query[1];
            if (source == destination) {
                answers.push_back(0);
                continue;
            }

            const int lowestCommonAncestor = findLowestCommonAncestor(source, destination);
            const int edgeCount =
                nodeDepth[source] + nodeDepth[destination] -
                2 * nodeDepth[lowestCommonAncestor];
            answers.push_back(static_cast<int>(modPow(2, edgeCount - 1)));
        }

        return answers;
    }

private:
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> ancestorJump;
    std::vector<int> nodeDepth;

    void buildTreeData(int node, int parentNode) {
        ancestorJump[0][node] = parentNode;
        for (const int neighbor : graph[node]) {
            if (neighbor == parentNode)
                continue;
            nodeDepth[neighbor] = nodeDepth[node] + 1;
            buildTreeData(neighbor, node);
        }
    }

    int findLowestCommonAncestor(int firstNode, int secondNode) const {
        int upperNode = firstNode;
        int lowerNode = secondNode;
        if (nodeDepth[upperNode] < nodeDepth[lowerNode])
            std::swap(upperNode, lowerNode);

        for (int level = kMaxLevels - 1; level >= 0; --level) {
            const int ancestor = ancestorJump[level][upperNode];
            if (ancestor != -1 && nodeDepth[ancestor] >= nodeDepth[lowerNode])
                upperNode = ancestor;
        }

        if (upperNode == lowerNode)
            return upperNode;

        for (int level = kMaxLevels - 1; level >= 0; --level) {
            const int firstAncestor = ancestorJump[level][upperNode];
            const int secondAncestor = ancestorJump[level][lowerNode];
            if (firstAncestor != -1 && firstAncestor != secondAncestor) {
                upperNode = firstAncestor;
                lowerNode = secondAncestor;
            }
        }

        return ancestorJump[0][upperNode];
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
    std::cout << "Problem: Number of Ways to Assign Edge Weights II\n";
    std::cout << std::string(60, '=') << "\n";

    EdgeWeightAssignmentSolver solverOne({{1, 2}});

    std::cout << "sample 1 -> ";
    printAnswers(solverOne.answerQueries({{1, 1}, {1, 2}}));
    std::cout << "\n";

    EdgeWeightAssignmentSolver solverTwo(
        {{1, 2}, {1, 3}, {3, 4}, {3, 5}});

    std::cout << "sample 2 -> ";
    printAnswers(solverTwo.answerQueries({{1, 4}, {3, 4}, {2, 5}}));
    std::cout << "\n";
}
