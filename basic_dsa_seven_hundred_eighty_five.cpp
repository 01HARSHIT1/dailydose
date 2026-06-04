/**
 * Basic DSA - Count Covered Buildings (LeetCode 3531)
 * Track row/column extremes; a building is covered if it lies strictly inside both.
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

int countCoveredBuildings(int gridSize,
                          const std::vector<std::vector<int>>& buildings) {
    std::vector<int> northernmost(gridSize + 1, INT_MAX);
    std::vector<int> southernmost(gridSize + 1, 0);
    std::vector<int> westernmost(gridSize + 1, INT_MAX);
    std::vector<int> easternmost(gridSize + 1, 0);

    for (const std::vector<int>& building : buildings) {
        const int row = building[0];
        const int column = building[1];
        northernmost[row] = std::min(northernmost[row], column);
        southernmost[row] = std::max(southernmost[row], column);
        westernmost[column] = std::min(westernmost[column], row);
        easternmost[column] = std::max(easternmost[column], row);
    }

    int coveredCount = 0;
    for (const std::vector<int>& building : buildings) {
        const int row = building[0];
        const int column = building[1];
        if (northernmost[row] < column && column < southernmost[row] &&
            westernmost[column] < row && row < easternmost[column]) {
            ++coveredCount;
        }
    }

    return coveredCount;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count Covered Buildings\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> "
              << countCoveredBuildings(3, {{1, 2}, {2, 2}, {3, 2}, {2, 1}, {2, 3}})
              << "\n";

    std::cout << "sample 2 -> "
              << countCoveredBuildings(3, {{1, 1}, {1, 2}, {2, 1}, {2, 2}}) << "\n";
}
