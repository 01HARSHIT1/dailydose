/**
 * Basic DSA - Subtree Inversion Sum (LeetCode 3544)
 * Tree DP with distance constraint on optional subtree sign flips.
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

long long subtreeInversionSum(const std::vector<std::vector<int>>& edges,
                              const std::vector<int>& nodeValues, int k) {
    const int nodeCount = static_cast<int>(nodeValues.size());
    std::vector<std::vector<int>> graph(nodeCount);
    std::vector<int> parent(nodeCount, -1);
    std::vector<std::vector<std::vector<long long>>> memo(
        nodeCount, std::vector<std::vector<long long>>(
                       k + 1, std::vector<long long>(2, -1)));

    for (const std::vector<int>& edge : edges) {
        graph[edge[0]].push_back(edge[1]);
        graph[edge[1]].push_back(edge[0]);
    }

    std::function<long long(int, int, bool)> depthFirstSearch =
        [&](int node, int stepsSinceInversion, bool inverted) -> long long {
        if (memo[node][stepsSinceInversion][inverted ? 1 : 0] != -1) {
            return memo[node][stepsSinceInversion][inverted ? 1 : 0];
        }

        long long keepSum =
            inverted ? -static_cast<long long>(nodeValues[node])
                     : static_cast<long long>(nodeValues[node]);
        long long invertSum = -keepSum;

        for (const int neighbor : graph[node]) {
            if (neighbor == parent[node])
                continue;

            parent[neighbor] = node;
            keepSum += depthFirstSearch(
                neighbor, std::min(k, stepsSinceInversion + 1), inverted);

            if (stepsSinceInversion == k) {
                invertSum += depthFirstSearch(neighbor, 1, !inverted);
            }
        }

        const long long bestSum = (stepsSinceInversion == k)
                                      ? std::max(keepSum, invertSum)
                                      : keepSum;
        memo[node][stepsSinceInversion][inverted ? 1 : 0] = bestSum;
        return bestSum;
    };

    return depthFirstSearch(0, k, false);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Subtree Inversion Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << subtreeInversionSum(
                     {{0, 1}, {0, 2}, {1, 3}, {1, 4}, {2, 5}, {2, 6}},
                     {4, -8, -6, 3, 7, -2, 5}, 2)
              << "\n";

    std::cout << "sample 2 -> "
              << subtreeInversionSum({{0, 1}, {1, 2}, {2, 3}, {3, 4}},
                                     {-1, 3, -2, 4, -5}, 2)
              << "\n";

    std::cout << "sample 3 -> "
              << subtreeInversionSum({{0, 1}, {0, 2}}, {0, -1, -2}, 3) << "\n";
}
