/**
 * Basic DSA - Set Matrix Zeroes (LeetCode 73)
 * Set entire row and column to 0 if element is 0 (in-place).
 */
#include <iostream>
#include <vector>

void setZeroes(std::vector<std::vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    bool col0 = false;
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) col0 = true;
        for (int j = 1; j < n; j++)
            if (matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
    }
    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        if (col0) matrix[i][0] = 0;
    }
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Set Matrix Zeroes\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> m1 = {{1,1,1},{1,0,1},{1,1,1}};
    setZeroes(m1);
    std::cout << "[[1,1,1],[1,0,1],[1,1,1]] -> ";
    for (const auto& r : m1) { std::cout << "["; for (int x : r) std::cout << x << ","; std::cout << "] "; }
    std::cout << "\n";

    std::vector<std::vector<int>> m2 = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(m2);
    std::cout << "[[0,1,2,0],[3,4,5,2],[1,3,1,5]] -> ";
    for (const auto& r : m2) { std::cout << "["; for (int x : r) std::cout << x << ","; std::cout << "] "; }
    std::cout << "\n";
}
