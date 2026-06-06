/**
 * Basic DSA - Equal Sum Grid Partition II (LeetCode 3548)
 * Check horizontal/vertical cuts with optional single-cell discount.
 */

#include <iostream>
#include <numeric>
#include <unordered_set>
#include <vector>

long long gridTotalSum(const std::vector<std::vector<int>>& grid) {
    long long total = 0;
    for (const std::vector<int>& row : grid) {
        total += std::accumulate(row.begin(), row.end(), 0LL);
    }
    return total;
}

long long rowSum(const std::vector<int>& row) {
    return std::accumulate(row.begin(), row.end(), 0LL);
}

std::vector<std::vector<int>> transposeGrid(
    const std::vector<std::vector<int>>& grid) {
    const int rowCount = static_cast<int>(grid.size());
    const int columnCount = static_cast<int>(grid[0].size());
    std::vector<std::vector<int>> transposed(columnCount,
                                             std::vector<int>(rowCount));

    for (int row = 0; row < rowCount; ++row) {
        for (int column = 0; column < columnCount; ++column)
            transposed[column][row] = grid[row][column];
    }

    return transposed;
}

std::vector<std::vector<int>> reverseRows(
    const std::vector<std::vector<int>>& grid) {
    return std::vector<std::vector<int>>(grid.rbegin(), grid.rend());
}

bool canPartitionHorizontally(const std::vector<std::vector<int>>& grid,
                              long long totalSum) {
    long long topSum = 0;
    std::unordered_set<int> seenValues;

    for (int row = 0; row < static_cast<int>(grid.size()); ++row) {
        topSum += rowSum(grid[row]);
        const long long bottomSum = totalSum - topSum;
        seenValues.insert(grid[row].begin(), grid[row].end());

        const long long difference = topSum - bottomSum;
        if (difference == 0 || difference == grid[0][0] ||
            difference == grid[0].back() || difference == grid[row][0]) {
            return true;
        }

        if (static_cast<int>(grid[0].size()) > 1 && row > 0 &&
            seenValues.count(static_cast<int>(difference)) > 0) {
            return true;
        }
    }

    return false;
}

bool canPartitionGrid(const std::vector<std::vector<int>>& grid) {
    const long long totalSum = gridTotalSum(grid);
    const std::vector<std::vector<int>> transposed = transposeGrid(grid);
    const std::vector<std::vector<int>> reversedTransposed =
        reverseRows(transposed);

    return canPartitionHorizontally(grid, totalSum) ||
           canPartitionHorizontally(reverseRows(grid), totalSum) ||
           canPartitionHorizontally(transposed, totalSum) ||
           canPartitionHorizontally(reversedTransposed, totalSum);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Equal Sum Grid Partition II\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << (canPartitionGrid({{1, 4}, {2, 3}}) ? "true" : "false")
              << "\n";

    std::cout << "sample 2 -> "
              << (canPartitionGrid({{1, 2}, {3, 4}}) ? "true" : "false")
              << "\n";

    std::cout << "sample 3 -> "
              << (canPartitionGrid({{1, 2, 4}, {2, 3, 5}}) ? "true" : "false")
              << "\n";

    std::cout << "sample 4 -> "
              << (canPartitionGrid({{4, 1, 8}, {3, 2, 6}}) ? "true" : "false")
              << "\n";
}
