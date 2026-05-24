/**
 * Basic DSA - Maximum Number of Fish in a Grid (LeetCode 2658)
 * Flood-fill each connected water region (positive cells); track the largest total catch.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int dfs(std::vector<std::vector<int>>& grid, int r, int c) {
    int rows = static_cast<int>(grid.size());
    int cols = static_cast<int>(grid[0].size());
    if (r < 0 || c < 0 || r >= rows || c >= cols || grid[static_cast<size_t>(r)][static_cast<size_t>(c)] == 0)
        return 0;

    int caught = grid[static_cast<size_t>(r)][static_cast<size_t>(c)];
    grid[static_cast<size_t>(r)][static_cast<size_t>(c)] = 0;
    caught += dfs(grid, r + 1, c);
    caught += dfs(grid, r - 1, c);
    caught += dfs(grid, r, c + 1);
    caught += dfs(grid, r, c - 1);
    return caught;
}

int findMaxFish(std::vector<std::vector<int>> grid) {
    int best = 0;
    for (int r = 0; r < static_cast<int>(grid.size()); ++r) {
        for (int c = 0; c < static_cast<int>(grid[0].size()); ++c) {
            if (grid[static_cast<size_t>(r)][static_cast<size_t>(c)] > 0)
                best = std::max(best, dfs(grid, r, c));
        }
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Number of Fish in a Grid\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << findMaxFish({{0, 2, 1, 0}, {4, 0, 0, 3}, {1, 0, 0, 4}, {0, 3, 2, 0}}) << "\n";
    std::cout << "sample 2 -> "
              << findMaxFish({{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 1}}) << "\n";
}
