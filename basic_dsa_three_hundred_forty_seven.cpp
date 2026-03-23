/**
 * Basic DSA - Pascal's Triangle (LeetCode 118)
 * Return first numRows of Pascal's triangle.
 */
#include <iostream>
#include <string>
#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < numRows; i++) {
        std::vector<int> row(i + 1, 1);
        for (int j = 1; j < i; j++)
            row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
        ans.push_back(std::move(row));
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Pascal's Triangle\n";
    std::cout << std::string(60, '=') << "\n";

    auto g = generate(5);
    for (const auto& row : g) {
        std::cout << "[";
        for (int i = 0; i < (int)row.size(); i++) std::cout << (i ? "," : "") << row[i];
        std::cout << "]\n";
    }
}
