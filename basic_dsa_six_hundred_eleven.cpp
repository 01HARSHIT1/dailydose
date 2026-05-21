/**
 * Basic DSA - Sort the Students by Their Kth Score (LeetCode 2545)
 * Sort each student's exam row by score at index k in descending order.
 */
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> sortTheStudents(const std::vector<std::vector<int>>& score, int k) {
    std::vector<std::vector<int>> sorted = score;
    std::sort(sorted.begin(), sorted.end(), [k](const std::vector<int>& a, const std::vector<int>& b) {
        return a[static_cast<size_t>(k)] > b[static_cast<size_t>(k)];
    });
    return sorted;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    std::cout << "[";
    for (size_t i = 0; i < matrix.size(); ++i) {
        if (i) std::cout << ",";
        std::cout << "[";
        for (size_t j = 0; j < matrix[i].size(); ++j) {
            if (j) std::cout << ",";
            std::cout << matrix[i][j];
        }
        std::cout << "]";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sort the Students by Their Kth Score\n";
    std::cout << std::string(60, '=') << "\n";

    printMatrix(sortTheStudents({{10, 6, 9, 1}, {7, 5, 11, 2}, {4, 8, 3, 15}}, 2));
    printMatrix(sortTheStudents({{1, 1, 0}, {0, 0, 0}}, 1));
}
