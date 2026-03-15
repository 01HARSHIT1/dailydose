/**
 * Basic DSA - Spiral Matrix (LeetCode 54)
 * Return elements of matrix in spiral order.
 */
#include <iostream>
#include <vector>

std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
    std::vector<int> out;
    int top = 0, bot = matrix.size() - 1, left = 0, right = matrix[0].size() - 1;
    while (top <= bot && left <= right) {
        for (int j = left; j <= right; j++) out.push_back(matrix[top][j]);
        top++;
        if (top > bot) break;
        for (int i = top; i <= bot; i++) out.push_back(matrix[i][right]);
        right--;
        if (left > right) break;
        for (int j = right; j >= left; j--) out.push_back(matrix[bot][j]);
        bot--;
        if (top > bot) break;
        for (int i = bot; i >= top; i--) out.push_back(matrix[i][left]);
        left++;
    }
    return out;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Spiral Matrix\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> m1 = {{1,2,3},{4,5,6},{7,8,9}};
    auto r1 = spiralOrder(m1);
    std::cout << "[[1,2,3],[4,5,6],[7,8,9]] -> [";
    for (size_t i = 0; i < r1.size(); i++) std::cout << (i ? "," : "") << r1[i];
    std::cout << "]\n";

    std::vector<std::vector<int>> m2 = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    auto r2 = spiralOrder(m2);
    std::cout << "[[1,2,3,4],[5,6,7,8],[9,10,11,12]] -> [";
    for (size_t i = 0; i < r2.size(); i++) std::cout << (i ? "," : "") << r2[i];
    std::cout << "]\n";
}
