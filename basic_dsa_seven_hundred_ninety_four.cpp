/**
 * Basic DSA - Maximum Weighted K-Edge Path (LeetCode 3543)
 * DP over edge counts and path sums on a DAG; keep sums strictly below t.
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

int maxWeight(int nodeCount, const std::vector<std::vector<int>>& edges, int edgeCount,
              int limit) {
    std::vector<std::vector<std::pair<int, int>>> graph(nodeCount);
    std::vector<std::unordered_map<int, std::unordered_set<int>>> pathSums(nodeCount);

    for (const std::vector<int>& edge : edges) {
        const int source = edge[0];
        const int target = edge[1];
        const int weight = edge[2];
        graph[source].emplace_back(target, weight);
    }

    for (int node = 0; node < nodeCount; ++node)
        pathSums[node][0].insert(0);

    for (int usedEdges = 0; usedEdges < edgeCount; ++usedEdges) {
        for (int node = 0; node < nodeCount; ++node) {
            const auto edgeIt = pathSums[node].find(usedEdges);
            if (edgeIt == pathSums[node].end())
                continue;

            for (const int currentSum : edgeIt->second) {
                for (const auto& nextEdge : graph[node]) {
                    const int nextNode = nextEdge.first;
                    const int nextWeight = nextEdge.second;
                    const int nextSum = currentSum + nextWeight;
                    if (nextSum < limit)
                        pathSums[nextNode][usedEdges + 1].insert(nextSum);
                }
            }
        }
    }

    int bestSum = -1;
    for (int node = 0; node < nodeCount; ++node) {
        const auto finalIt = pathSums[node].find(edgeCount);
        if (finalIt == pathSums[node].end())
            continue;

        for (const int pathSum : finalIt->second)
            bestSum = std::max(bestSum, pathSum);
    }

    return bestSum;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Weighted K-Edge Path\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << maxWeight(3, {{0, 1, 1}, {1, 2, 2}}, 2, 4) << "\n";

    std::cout << "sample 2 -> "
              << maxWeight(3, {{0, 1, 2}, {0, 2, 3}}, 1, 3) << "\n";

    std::cout << "sample 3 -> "
              << maxWeight(3, {{0, 1, 6}, {1, 2, 8}}, 1, 6) << "\n";
}
