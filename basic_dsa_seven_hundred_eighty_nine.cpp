/**
 * Basic DSA - Fill a Special Grid (LeetCode 3537)
 * Divide-and-conquer fill in quadrant order: top-right, bottom-right, bottom-left, top-left.
 */

#include <iostream>
#include <vector>

void fillSpecialGrid(std::vector<std::vector<int>>& grid, int rowStart, int rowEnd,
                     int columnStart, int columnEnd, int& fillValue) {
    if (rowEnd - rowStart == 1) {
        grid[rowStart][columnStart] = fillValue++;
        return;
    }

    const int midRow = (rowStart + rowEnd) / 2;
    const int midColumn = (columnStart + columnEnd) / 2;

    fillSpecialGrid(grid, rowStart, midRow, midColumn, columnEnd, fillValue);
    fillSpecialGrid(grid, midRow, rowEnd, midColumn, columnEnd, fillValue);
    fillSpecialGrid(grid, midRow, rowEnd, columnStart, midColumn, fillValue);
    fillSpecialGrid(grid, rowStart, midRow, columnStart, midColumn, fillValue);
}

std::vector<std::vector<int>> specialGrid(int exponent) {
    const int size = 1 << exponent;
    std::vector<std::vector<int>> grid(size, std::vector<int>(size, 0));
    int fillValue = 0;
    fillSpecialGrid(grid, 0, size, 0, size, fillValue);
    return grid;
}

void printGrid(const std::vector<std::vector<int>>& grid) {
    std::cout << "[";
    for (int row = 0; row < static_cast<int>(grid.size()); ++row) {
        if (row > 0)
            std::cout << ",";
        std::cout << "[";
        for (int column = 0; column < static_cast<int>(grid[row].size()); ++column) {
            if (column > 0)
                std::cout << ",";
            std::cout << grid[row][column];
        }
        std::cout << "]";
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Fill a Special Grid\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printGrid(specialGrid(0));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printGrid(specialGrid(1));
    std::cout << "\n";
}
