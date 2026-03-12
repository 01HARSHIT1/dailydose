/**
 * Basic DSA - Pascal's Triangle (LeetCode 118)
 * Generate first numRows of Pascal's triangle.
 */
#include <iostream>
#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> out;
    for (int i = 0; i < numRows; i++) {
        std::vector<int> row(i + 1, 1);
        for (int j = 1; j < i; j++)
            row[j] = out[i-1][j-1] + out[i-1][j];
        out.push_back(row);
    }
    return out;
}

void printTriangle(const std::vector<std::vector<int>>& t) {
    for (const auto& row : t) {
        std::cout << "[";
        for (size_t i = 0; i < row.size(); i++) std::cout << (i ? "," : "") << row[i];
        std::cout << "] ";
    }
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Pascal's Triangle\n";
    std::cout << std::string(60, '=') << "\n";

    auto r1 = generate(5);
    std::cout << "numRows=5 -> "; printTriangle(r1); std::cout << "\n";

    auto r2 = generate(1);
    std::cout << "numRows=1 -> "; printTriangle(r2); std::cout << "\n";
}
