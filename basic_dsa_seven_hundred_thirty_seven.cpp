/**
 * Basic DSA - Find the Number of Copy Arrays (LeetCode 3468)
 * Count arrays with same adjacent differences and each value within bounds.
 */

#include <algorithm>
#include <iostream>
#include <vector>

int countArrays(const std::vector<int>& original, const std::vector<std::vector<int>>& bounds) {
    int minStart = bounds[0][0];
    int maxStart = bounds[0][1];

    for (int i = 1; i < static_cast<int>(original.size()); ++i) {
        const int diff = original[i] - original[i - 1];
        minStart = std::max(minStart + diff, bounds[i][0]);
        maxStart = std::min(maxStart + diff, bounds[i][1]);
    }

    return std::max(0, maxStart - minStart + 1);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Number of Copy Arrays\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << countArrays({1, 2, 3, 4}, {{1, 2}, {2, 3}, {3, 4}, {4, 5}}) << "\n";
    std::cout << "sample 2 -> "
              << countArrays({1, 2, 3, 4}, {{1, 10}, {2, 9}, {3, 8}, {4, 7}}) << "\n";
    std::cout << "sample 3 -> "
              << countArrays({1, 2, 1, 2}, {{1, 1}, {2, 3}, {3, 3}, {2, 3}}) << "\n";
}
