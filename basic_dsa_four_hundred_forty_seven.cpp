/**
 * Basic DSA - Lucky Numbers in a Matrix (LeetCode 1380)
 * Return values that are the minimum in their row and the maximum in their column.
 */
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

std::vector<int> luckyNumbers(const std::vector<std::vector<int>>& matrix) {
    int m = static_cast<int>(matrix.size()), n = static_cast<int>(matrix[0].size());
    std::vector<int> rowMin(m), colMax(n, std::numeric_limits<int>::min());
    for (int i = 0; i < m; ++i) {
        rowMin[i] = *std::min_element(matrix[i].begin(), matrix[i].end());
        for (int j = 0; j < n; ++j)
            colMax[j] = std::max(colMax[j], matrix[i][j]);
    }
    std::vector<int> ans;
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j])
                ans.push_back(matrix[i][j]);
    return ans;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Lucky Numbers in a Matrix\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> g1 = {{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
    std::cout << "[[3,7,8],[9,11,13],[15,16,17]] -> ";
    printVec(luckyNumbers(g1));
    std::cout << "\n";

    std::vector<std::vector<int>> g2 = {{1, 10, 4, 2}, {9, 3, 8, 7}, {15, 16, 17, 12}};
    std::cout << "[[1,10,4,2],[9,3,8,7],[15,16,17,12]] -> ";
    printVec(luckyNumbers(g2));
    std::cout << "\n";

    std::vector<std::vector<int>> g3 = {{7, 8}, {1, 2}};
    std::cout << "[[7,8],[1,2]] -> ";
    printVec(luckyNumbers(g3));
    std::cout << "\n";
}
