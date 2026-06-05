/**
 * Basic DSA - Equal Sum Grid Partition I (LeetCode 3546)
 * Check horizontal or vertical prefix sums for an equal half-total split.
 */

#include <iostream>
#include <vector>

bool canPartitionGrid(const std::vector<std::vector<int>>& grid) {
    long long totalSum = 0;
    for (const std::vector<int>& row : grid) {
        for (const int value : row)
            totalSum += value;
    }

    if (totalSum % 2 != 0)
        return false;

    const int rowCount = static_cast<int>(grid.size());
    const int columnCount = static_cast<int>(grid[0].size());
    long long prefixSum = 0;

    for (int row = 0; row < rowCount; ++row) {
        for (const int value : grid[row])
            prefixSum += value;

        if (prefixSum * 2 == totalSum && row + 1 < rowCount)
            return true;
    }

    prefixSum = 0;
    for (int column = 0; column < columnCount; ++column) {
        for (int row = 0; row < rowCount; ++row)
            prefixSum += grid[row][column];

        if (prefixSum * 2 == totalSum && column + 1 < columnCount)
            return true;
    }

    return false;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Equal Sum Grid Partition I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << (canPartitionGrid({{1, 4}, {2, 3}}) ? "true" : "false") << "\n";

    std::cout << "sample 2 -> "
              << (canPartitionGrid({{1, 3}, {2, 4}}) ? "true" : "false") << "\n";
}
