/**
 * Basic DSA - Shortest Path in a Weighted Tree (LeetCode 3515)
 * Euler tour with lazy segment tree for subtree edge-weight updates.
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

class LazySegmentTree {
public:
    explicit LazySegmentTree(int size) : size(size), tree(4 * size, 0), lazy(4 * size, 0) {}

    void addRange(int left, int right, int value) {
        addRange(0, 0, size - 1, left, right, value);
    }

    int query(int index) { return query(0, 0, size - 1, index); }

private:
    int size;
    std::vector<int> tree;
    std::vector<int> lazy;

    void push(int nodeIndex, int left, int right) {
        if (lazy[nodeIndex] == 0)
            return;

        tree[nodeIndex] += lazy[nodeIndex];
        if (left != right) {
            lazy[nodeIndex * 2 + 1] += lazy[nodeIndex];
            lazy[nodeIndex * 2 + 2] += lazy[nodeIndex];
        }
        lazy[nodeIndex] = 0;
    }

    void addRange(int nodeIndex, int left, int right, int rangeLeft, int rangeRight,
                  int value) {
        push(nodeIndex, left, right);
        if (rangeRight < left || rangeLeft > right)
            return;

        if (rangeLeft <= left && right <= rangeRight) {
            lazy[nodeIndex] += value;
            push(nodeIndex, left, right);
            return;
        }

        const int middle = (left + right) / 2;
        addRange(nodeIndex * 2 + 1, left, middle, rangeLeft, rangeRight, value);
        addRange(nodeIndex * 2 + 2, middle + 1, right, rangeLeft, rangeRight, value);
    }

    int query(int nodeIndex, int left, int right, int targetIndex) {
        push(nodeIndex, left, right);
        if (left == right)
            return tree[nodeIndex];

        const int middle = (left + right) / 2;
        if (targetIndex <= middle)
            return query(nodeIndex * 2 + 1, left, middle, targetIndex);
        return query(nodeIndex * 2 + 2, middle + 1, right, targetIndex);
    }
};

void depthFirstSearch(const std::vector<std::vector<std::pair<int, int>>>& graph,
                      int node, int previousNode, int& timer,
                      std::vector<int>& inTime, std::vector<int>& outTime,
                      std::vector<int>& distance, std::vector<int>& parent) {
    inTime[node] = timer++;

    for (const std::pair<int, int>& edge : graph[node]) {
        const int neighbor = edge.first;
        const int weight = edge.second;
        if (neighbor == previousNode)
            continue;

        parent[neighbor] = node;
        distance[neighbor] = distance[node] + weight;
        depthFirstSearch(graph, neighbor, node, timer, inTime, outTime, distance,
                         parent);
    }

    outTime[node] = timer - 1;
}

std::vector<int> treeQueries(int nodeCount,
                             const std::vector<std::vector<int>>& edges,
                             const std::vector<std::vector<int>>& queries) {
    LazySegmentTree segmentTree(nodeCount);
    std::vector<int> answers;
    std::vector<std::vector<std::pair<int, int>>> graph(nodeCount + 1);
    std::map<std::pair<int, int>, int> edgeWeights;

    for (const std::vector<int>& edge : edges) {
        const int firstNode = edge[0];
        const int secondNode = edge[1];
        const int weight = edge[2];
        graph[firstNode].emplace_back(secondNode, weight);
        graph[secondNode].emplace_back(firstNode, weight);
        edgeWeights[{std::min(firstNode, secondNode), std::max(firstNode, secondNode)}] =
            weight;
    }

    std::vector<int> inTime(nodeCount + 1);
    std::vector<int> outTime(nodeCount + 1);
    std::vector<int> distance(nodeCount + 1);
    std::vector<int> parent(nodeCount + 1);
    int timer = 0;

    depthFirstSearch(graph, 1, -1, timer, inTime, outTime, distance, parent);

    for (int node = 1; node <= nodeCount; ++node)
        segmentTree.addRange(inTime[node], inTime[node], distance[node]);

    for (const std::vector<int>& query : queries) {
        if (query[0] == 1) {
            const int firstNode = query[1];
            const int secondNode = query[2];
            const int newWeight = query[3];
            const std::pair<int, int> edgeKey = {std::min(firstNode, secondNode),
                                                 std::max(firstNode, secondNode)};
            const int delta = newWeight - edgeWeights[edgeKey];
            edgeWeights[edgeKey] = newWeight;
            const int childNode =
                (parent[secondNode] == firstNode) ? secondNode : firstNode;
            segmentTree.addRange(inTime[childNode], outTime[childNode], delta);
        } else {
            answers.push_back(segmentTree.query(inTime[query[1]]));
        }
    }

    return answers;
}

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
    std::cout << "Problem: Shortest Path in a Weighted Tree\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printAnswers(treeQueries(2, {{1, 2, 7}}, {{2, 2}, {1, 1, 2, 4}, {2, 2}}));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printAnswers(treeQueries(3, {{1, 2, 2}, {1, 3, 4}},
                             {{2, 1}, {2, 3}, {1, 1, 3, 7}, {2, 2}, {2, 3}}));
    std::cout << "\n";

    std::cout << "sample 3 -> ";
    printAnswers(treeQueries(4, {{1, 2, 2}, {2, 3, 1}, {3, 4, 5}},
                             {{2, 4}, {2, 3}, {1, 2, 3, 3}, {2, 2}, {2, 3}}));
    std::cout << "\n";
}
