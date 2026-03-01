/**
 * Basic DSA - Pascal's Triangle (LeetCode 118)
 * Return first numRows of Pascal's triangle.
 */
#include <iostream>
#include <vector>

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> out;
    for (int i = 0; i < numRows; i++) {
        std::vector<int> row(i + 1, 1);
        for (int j = 1; j < i; j++)
            row[j] = out[i - 1][j - 1] + out[i - 1][j];
        out.push_back(row);
    }
    return out;
}

void print(std::vector<std::vector<int>>& t) {
    std::cout << "[";
    for (size_t i = 0; i < t.size(); i++) {
        std::cout << "[";
        for (size_t j = 0; j < t[i].size(); j++) {
            std::cout << t[i][j];
            if (j + 1 < t[i].size()) std::cout << ",";
        }
        std::cout << "]";
        if (i + 1 < t.size()) std::cout << ",";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Pascal's Triangle\n";
    std::cout << std::string(60, '=') << "\n";

    auto r1 = generate(5);
    std::cout << "numRows=5 -> ";
    print(r1);

    auto r2 = generate(1);
    std::cout << "numRows=1 -> ";
    print(r2);
}
