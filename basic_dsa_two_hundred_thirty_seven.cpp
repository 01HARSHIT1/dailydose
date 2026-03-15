/**
 * Basic DSA - Minimum Time Visiting All Points (LeetCode 1266)
 * Min time to visit all points in order (1 sec per unit in x or y).
 */
#include <iostream>
#include <vector>
#include <cmath>

int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
    int ans = 0;
    for (size_t i = 1; i < points.size(); i++)
        ans += std::max(std::abs(points[i][0] - points[i-1][0]), std::abs(points[i][1] - points[i-1][1]));
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Time Visiting All Points\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> p1 = {{1,1},{3,4},{-1,0}};
    std::cout << "[[1,1],[3,4],[-1,0]] -> " << minTimeToVisitAllPoints(p1) << "\n";

    std::vector<std::vector<int>> p2 = {{3,2},{-2,2}};
    std::cout << "[[3,2],[-2,2]] -> " << minTimeToVisitAllPoints(p2) << "\n";
}
