/**
 * Basic DSA - Modify the Matrix (LeetCode 3033)
 * Replace every -1 with the maximum value found in its column.
 */
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> modifiedMatrix(std::vector<std::vector<int>> matrix) {
    int rows = static_cast<int>(matrix.size());
    int cols = static_cast<int>(matrix[0].size());
    for (int c = 0; c < cols; ++c) {
        int colMax = 0;
        for (int r = 0; r < rows; ++r)
            colMax = std::max(colMax, matrix[static_cast<size_t>(r)][static_cast<size_t>(c)]);
        for (int r = 0; r < rows; ++r) {
            if (matrix[static_cast<size_t>(r)][static_cast<size_t>(c)] == -1)
                matrix[static_cast<size_t>(r)][static_cast<size_t>(c)] = colMax;
        }
    }
    return matrix;
}

void printMatrix(const std::vector<std::vector<int>>& m) {
    std::cout << "[";
    for (size_t i = 0; i < m.size(); ++i) {
        if (i) std::cout << ",";
        std::cout << "[";
        for (size_t j = 0; j < m[i].size(); ++j) {
            if (j) std::cout << ",";
            std::cout << m[i][j];
        }
        std::cout << "]";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Modify the Matrix\n";
    std::cout << std::string(60, '=') << "\n";

    printMatrix(modifiedMatrix({{1, 2, -1}, {4, -1, 6}, {7, 8, 9}}));
    printMatrix(modifiedMatrix({{3, -1}, {5, 2}}));
}
