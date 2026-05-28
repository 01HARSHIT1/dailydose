/**
 * Basic DSA - Minimum Operations to Make Columns Strictly Increasing (LeetCode 3402)
 * For each column, bump cells upward so every row is strictly greater than the one above.
 */
#include <iostream>
#include <vector>

int minimumOperations(std::vector<std::vector<int>> grid) {
    int operations = 0;
    int rows = static_cast<int>(grid.size());
    int cols = static_cast<int>(grid[0].size());

    for (int col = 0; col < cols; ++col) {
        for (int row = 1; row < rows; ++row) {
            if (grid[static_cast<size_t>(row)][static_cast<size_t>(col)]
                <= grid[static_cast<size_t>(row - 1)][static_cast<size_t>(col)]) {
                int needed = grid[static_cast<size_t>(row - 1)][static_cast<size_t>(col)]
                             - grid[static_cast<size_t>(row)][static_cast<size_t>(col)] + 1;
                operations += needed;
                grid[static_cast<size_t>(row)][static_cast<size_t>(col)] += needed;
            }
        }
    }
    return operations;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Operations to Make Columns Strictly Increasing\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << minimumOperations({{3, 2}, {1, 3}, {3, 4}, {0, 1}}) << "\n";
    std::cout << "sample 2 -> "
              << minimumOperations({{3, 2, 1}, {2, 1, 0}, {1, 2, 3}}) << "\n";
}
