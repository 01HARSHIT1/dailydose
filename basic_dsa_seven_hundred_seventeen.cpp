/**
 * Basic DSA - Sort Matrix by Diagonals (LeetCode 3446)
 * Bottom-left diagonals non-increasing; top-right diagonals non-decreasing.
 */
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<std::vector<int>> sortMatrix(std::vector<std::vector<int>> grid) {
    int n = static_cast<int>(grid.size());

    for (int k = n - 2; k >= 0; --k) {
        std::vector<int> values;
        for (int i = k, j = 0; i < n && j < n; ++i, ++j)
            values.push_back(grid[i][j]);
        std::sort(values.begin(), values.end());
        for (int i = k, j = 0; i < n && j < n; ++i, ++j) {
            grid[i][j] = values.back();
            values.pop_back();
        }
    }

    for (int k = n - 2; k > 0; --k) {
        std::vector<int> values;
        for (int i = k, j = n - 1; i >= 0 && j >= 0; --i, --j)
            values.push_back(grid[i][j]);
        std::sort(values.begin(), values.end());
        for (int i = k, j = n - 1; i >= 0 && j >= 0; --i, --j) {
            grid[i][j] = values.back();
            values.pop_back();
        }
    }

    return grid;
}

void printGrid(const std::vector<std::vector<int>>& grid) {
    std::cout << "[";
    for (size_t i = 0; i < grid.size(); ++i) {
        if (i)
            std::cout << ",";
        std::cout << "[";
        for (size_t j = 0; j < grid[i].size(); ++j) {
            if (j)
                std::cout << ",";
            std::cout << grid[i][j];
        }
        std::cout << "]";
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sort Matrix by Diagonals\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printGrid(sortMatrix({{1, 7, 3}, {9, 8, 2}, {4, 5, 6}}));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printGrid(sortMatrix({{0, 1}, {1, 2}}));
    std::cout << "\n";
}
