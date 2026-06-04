/**
 * Basic DSA - Maximum Profit from Valid Topological Order in DAG (LeetCode 3530)
 * Bitmask DP over node subsets, respecting dependency masks and position weights.
 */

#include <algorithm>
#include <iostream>
#include <vector>

int countSetBits(unsigned value) {
    int bitCount = 0;
    while (value > 0) {
        bitCount += static_cast<int>(value & 1U);
        value >>= 1U;
    }
    return bitCount;
}

int maxProfit(int nodeCount, const std::vector<std::vector<int>>& edges,
              const std::vector<int>& scores) {
    const int maxMask = 1 << nodeCount;
    std::vector<int> prerequisites(nodeCount, 0);
    std::vector<int> bestProfit(maxMask, -1);
    bestProfit[0] = 0;

    for (const std::vector<int>& edge : edges) {
        const int source = edge[0];
        const int target = edge[1];
        prerequisites[target] |= 1 << source;
    }

    for (unsigned mask = 0; mask < static_cast<unsigned>(maxMask); ++mask) {
        if (bestProfit[mask] == -1)
            continue;

        const int position = countSetBits(mask) + 1;

        for (int node = 0; node < nodeCount; ++node) {
            if ((mask >> node) & 1U)
                continue;
            if ((mask & static_cast<unsigned>(prerequisites[node])) !=
                static_cast<unsigned>(prerequisites[node]))
                continue;

            const unsigned newMask = mask | (1U << node);
            bestProfit[newMask] =
                std::max(bestProfit[newMask], bestProfit[mask] + scores[node] * position);
        }
    }

    return bestProfit[maxMask - 1];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Profit from Valid Topological Order in DAG\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << maxProfit(2, {{0, 1}}, {2, 3}) << "\n";

    std::cout << "sample 2 -> "
              << maxProfit(3, {{0, 1}, {0, 2}}, {1, 6, 3}) << "\n";
}
