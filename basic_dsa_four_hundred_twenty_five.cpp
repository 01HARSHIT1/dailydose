/**
 * Basic DSA - Count Negative Numbers in a Sorted Matrix (LeetCode 1351)
 * Rows and columns are non-increasing (sorted high to low left/down).
 */
#include <iostream>
#include <string>
#include <vector>

int countNegatives(const std::vector<std::vector<int>>& grid) {
    int m = static_cast<int>(grid.size());
    int n = static_cast<int>(grid[0].size());
    int cnt = 0;
    int j = n - 1;
    for (int i = 0; i < m; ++i) {
        while (j >= 0 && grid[i][j] < 0) {
            cnt += m - i;
            --j;
        }
    }
    return cnt;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count Negative Numbers in a Sorted Matrix\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> g1 = {
        {4, 3, 2, -1},
        {3, 2, 1, -1},
        {1, 1, -1, -2},
        {-1, -1, -2, -3}};
    std::cout << "4x4 example -> " << countNegatives(g1) << "\n";

    std::vector<std::vector<int>> g2 = {{3, 2}, {1, 0}};
    std::cout << "[[3,2],[1,0]] -> " << countNegatives(g2) << "\n";
}
