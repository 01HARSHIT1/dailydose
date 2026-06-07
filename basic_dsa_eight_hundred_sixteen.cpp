/**
 * Basic DSA - Number of Ways to Assign Edge Weights I (LeetCode 3558)
 * BFS max depth from root; answer is 2^(depth - 2) mod 1e9+7.
 */

#include <iostream>
#include <queue>
#include <vector>

namespace {
constexpr int kMod = 1'000'000'007;

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

int assignEdgeWeights(const std::vector<std::vector<int>>& edges) {
    const int nodeCount = static_cast<int>(edges.size()) + 1;
    std::vector<std::vector<int>> graph(nodeCount + 1);

    for (const std::vector<int>& edge : edges) {
        const int firstNode = edge[0];
        const int secondNode = edge[1];
        graph[firstNode].push_back(secondNode);
        graph[secondNode].push_back(firstNode);
    }

    std::queue<int> breadthFirstQueue;
    breadthFirstQueue.push(1);
    std::vector<bool> visited(nodeCount + 1, false);
    visited[1] = true;

    int depthLevels = 0;
    while (!breadthFirstQueue.empty()) {
        const int levelSize = static_cast<int>(breadthFirstQueue.size());
        for (int processed = 0; processed < levelSize; ++processed) {
            const int currentNode = breadthFirstQueue.front();
            breadthFirstQueue.pop();
            for (const int neighbor : graph[currentNode]) {
                if (visited[neighbor])
                    continue;
                visited[neighbor] = true;
                breadthFirstQueue.push(neighbor);
            }
        }
        ++depthLevels;
    }

    if (depthLevels == 0)
        return 0;
    return static_cast<int>(modPow(2, depthLevels - 2));
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Number of Ways to Assign Edge Weights I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << assignEdgeWeights({{1, 2}}) << "\n";
    std::cout << "sample 2 -> "
              << assignEdgeWeights({{1, 2}, {1, 3}, {3, 4}, {3, 5}}) << "\n";
}
