/**
 * Basic DSA - Row With Maximum Ones (LeetCode 2643)
 * Count ones in each row; track the row with the most (lowest index on ties).
 */
#include <iostream>
#include <vector>

std::vector<int> rowAndMaximumOnes(const std::vector<std::vector<int>>& mat) {
    int bestRow = 0;
    int bestCount = -1;
    for (int i = 0; i < static_cast<int>(mat.size()); ++i) {
        int ones = 0;
        for (int cell : mat[static_cast<size_t>(i)])
            ones += cell;
        if (ones > bestCount) {
            bestCount = ones;
            bestRow = i;
        }
    }
    return {bestRow, bestCount};
}

void printVec(const std::vector<int>& v) {
    std::cout << "[" << v[0] << "," << v[1] << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Row With Maximum Ones\n";
    std::cout << std::string(60, '=') << "\n";

    printVec(rowAndMaximumOnes({{0, 1}, {1, 0}}));
    printVec(rowAndMaximumOnes({{0, 0, 0}, {0, 1, 1}}));
    printVec(rowAndMaximumOnes({{0, 0}, {1, 1}, {0, 0}}));
}
