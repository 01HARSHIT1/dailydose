/**
 * Basic DSA - Toeplitz Matrix (LeetCode 766)
 * Check if every diagonal from top-left to bottom-right has same elements.
 */
#include <iostream>
#include <vector>

bool isToeplitzMatrix(std::vector<std::vector<int>>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 1; i < m; i++)
        for (int j = 1; j < n; j++)
            if (matrix[i][j] != matrix[i-1][j-1]) return false;
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Toeplitz Matrix\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> m1 = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};
    std::cout << "[[1,2,3,4],[5,1,2,3],[9,5,1,2]] -> " << (isToeplitzMatrix(m1) ? "true" : "false") << "\n";

    std::vector<std::vector<int>> m2 = {{1,2},{2,2}};
    std::cout << "[[1,2],[2,2]] -> " << (isToeplitzMatrix(m2) ? "true" : "false") << "\n";
}
