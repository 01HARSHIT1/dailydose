/**
 * Basic DSA - Transpose Matrix (LeetCode 867)
 * Return transpose of matrix (swap rows and columns).
 */
#include <iostream>
#include <vector>

std::vector<std::vector<int>> transpose(std::vector<std::vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    std::vector<std::vector<int>> out(n, std::vector<int>(m));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            out[j][i] = matrix[i][j];
    return out;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Transpose Matrix\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> m1 = {{1,2,3},{4,5,6},{7,8,9}};
    auto r1 = transpose(m1);
    std::cout << "3x3 -> transpose: [[1,4,7],[2,5,8],[3,6,9]]\n";

    std::vector<std::vector<int>> m2 = {{1,2,3},{4,5,6}};
    auto r2 = transpose(m2);
    std::cout << "2x3 -> 3x2: [";
    for (const auto& row : r2) for (int x : row) std::cout << x << ",";
    std::cout << "]\n";
}
