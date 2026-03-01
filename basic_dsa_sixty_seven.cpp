/**
 * Basic DSA - Minimum Number of Arrows to Burst Balloons (LeetCode 452)
 * Find minimum arrows to burst all balloons (intervals).
 */
#include <iostream>
#include <vector>
#include <algorithm>

int findMinArrowShots(std::vector<std::vector<int>>& points) {
    if (points.empty()) return 0;
    std::sort(points.begin(), points.end(), [](auto& a, auto& b) {
        return a[1] < b[1];
    });
    int arrows = 1, end = points[0][1];
    for (size_t i = 1; i < points.size(); i++) {
        if (points[i][0] > end) {
            arrows++;
            end = points[i][1];
        }
    }
    return arrows;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Number of Arrows to Burst Balloons\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> a1 = {{10,16},{2,8},{1,6},{7,12}};
    std::cout << "[[10,16],[2,8],[1,6],[7,12]] -> " << findMinArrowShots(a1) << "\n";

    std::vector<std::vector<int>> a2 = {{1,2},{3,4},{5,6},{7,8}};
    std::cout << "[[1,2],[3,4],[5,6],[7,8]] -> " << findMinArrowShots(a2) << "\n";

    std::vector<std::vector<int>> a3 = {{1,2},{2,3},{3,4},{4,5}};
    std::cout << "[[1,2],[2,3],[3,4],[4,5]] -> " << findMinArrowShots(a3) << "\n";
}
