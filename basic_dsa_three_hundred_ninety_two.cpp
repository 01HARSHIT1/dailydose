/**
 * Basic DSA - Score After Flipping Matrix (LeetCode 861)
 * Toggle whole rows/columns so the matrix, read as binary rows, has maximum sum.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int matrixScore(std::vector<std::vector<int>>& grid) {
    int m = static_cast<int>(grid.size());
    int n = static_cast<int>(grid[0].size());
    for (int i = 0; i < m; ++i) {
        if (grid[i][0] == 0) {
            for (int j = 0; j < n; ++j)
                grid[i][j] ^= 1;
        }
    }
    int ans = 0;
    for (int j = 0; j < n; ++j) {
        int ones = 0;
        for (int i = 0; i < m; ++i)
            ones += grid[i][j];
        ans += std::max(ones, m - ones) * (1 << (n - 1 - j));
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Score After Flipping Matrix\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> g1 = {{0, 0, 1, 1}, {1, 0, 1, 0}, {1, 1, 0, 0}};
    std::cout << "[[0,0,1,1],...] -> " << matrixScore(g1) << "\n";

    std::vector<std::vector<int>> g2 = {{0}};
    std::cout << "[[0]] -> " << matrixScore(g2) << "\n";
}
