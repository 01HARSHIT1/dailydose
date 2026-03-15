/**
 * Basic DSA - Rotate Image (LeetCode 48)
 * Rotate n x n matrix 90 degrees clockwise in-place.
 */
#include <iostream>
#include <vector>
#include <algorithm>

void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            std::swap(matrix[i][j], matrix[j][i]);
    for (int i = 0; i < n; i++)
        std::reverse(matrix[i].begin(), matrix[i].end());
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Rotate Image\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> m1 = {{1,2,3},{4,5,6},{7,8,9}};
    rotate(m1);
    std::cout << "[[1,2,3],[4,5,6],[7,8,9]] -> ";
    for (const auto& r : m1) { std::cout << "["; for (int x : r) std::cout << x << ","; std::cout << "] "; }
    std::cout << "\n";

    std::vector<std::vector<int>> m2 = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    rotate(m2);
    std::cout << "4x4 matrix rotated 90 CW\n";
}
