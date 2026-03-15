/**
 * Basic DSA - Reshape the Matrix (LeetCode 566)
 * Reshape matrix to r x c if possible, else return original.
 */
#include <iostream>
#include <vector>

std::vector<std::vector<int>> matrixReshape(std::vector<std::vector<int>>& mat, int r, int c) {
    int m = mat.size(), n = mat[0].size();
    if (m * n != r * c) return mat;
    std::vector<std::vector<int>> out(r, std::vector<int>(c));
    for (int i = 0; i < m * n; i++)
        out[i / c][i % c] = mat[i / n][i % n];
    return out;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Reshape the Matrix\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> m1 = {{1, 2}, {3, 4}};
    auto r1 = matrixReshape(m1, 1, 4);
    std::cout << "[[1,2],[3,4]] -> 1x4: [";
    for (int x : r1[0]) std::cout << x << ",";
    std::cout << "]\n";

    std::vector<std::vector<int>> m2 = {{1, 2}, {3, 4}};
    auto r2 = matrixReshape(m2, 2, 4);
    std::cout << "[[1,2],[3,4]] -> 2x4: (invalid, return original)\n";
}
