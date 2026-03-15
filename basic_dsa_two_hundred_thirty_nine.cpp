/**
 * Basic DSA - Projection Area of 3D Shapes (LeetCode 883)
 * Sum of xy (top), xz (front), yz (side) projection areas.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int projectionArea(std::vector<std::vector<int>>& grid) {
    int n = grid.size();
    int xy = 0, xz = 0, yz = 0;
    for (int i = 0; i < n; i++) {
        int maxRow = 0, maxCol = 0;
        for (int j = 0; j < n; j++) {
            if (grid[i][j] > 0) xy++;
            maxRow = std::max(maxRow, grid[i][j]);
            maxCol = std::max(maxCol, grid[j][i]);
        }
        xz += maxRow;
        yz += maxCol;
    }
    return xy + xz + yz;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Projection Area of 3D Shapes\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> g1 = {{1,2},{3,4}};
    std::cout << "[[1,2],[3,4]] -> " << projectionArea(g1) << "\n";

    std::vector<std::vector<int>> g2 = {{2}};
    std::cout << "[[2]] -> " << projectionArea(g2) << "\n";

    std::vector<std::vector<int>> g3 = {{1,0},{0,2}};
    std::cout << "[[1,0],[0,2]] -> " << projectionArea(g3) << "\n";
}
