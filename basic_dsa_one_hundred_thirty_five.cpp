/**
 * Basic DSA - Number of Islands (LeetCode 200)
 * Count number of connected 1-regions in 2D grid (DFS).
 */
#include <iostream>
#include <vector>

int numIslands(std::vector<std::vector<char>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    int count = 0;
    auto dfs = [&](auto&& self, int r, int c) {
        if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] == '0') return;
        grid[r][c] = '0';
        self(self, r+1, c); self(self, r-1, c);
        self(self, r, c+1); self(self, r, c-1);
    };
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (grid[i][j] == '1') { count++; dfs(dfs, i, j); }
    return count;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Number of Islands\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<char>> g1 = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    std::cout << "4x5 grid -> " << numIslands(g1) << "\n";

    std::vector<std::vector<char>> g2 = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    std::cout << "4x5 grid (3 islands) -> " << numIslands(g2) << "\n";
}
