/**
 * Basic DSA - K Closest Points to Origin (LeetCode 973)
 * Return k closest points to origin.
 */
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
    std::partial_sort(points.begin(), points.begin() + k, points.end(),
        [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0]*a[0] + a[1]*a[1] < b[0]*b[0] + b[1]*b[1];
        });
    return std::vector<std::vector<int>>(points.begin(), points.begin() + k);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: K Closest Points to Origin\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> p1 = {{1,3}, {-2,2}};
    auto r1 = kClosest(p1, 1);
    std::cout << "[[1,3],[-2,2]], 1 -> [" << r1[0][0] << "," << r1[0][1] << "]\n";

    std::vector<std::vector<int>> p2 = {{3,3}, {5,-1}, {-2,4}};
    auto r2 = kClosest(p2, 2);
    std::cout << "[[3,3],[5,-1],[-2,4]], 2 -> ";
    for (auto& p : r2) std::cout << "[" << p[0] << "," << p[1] << "] ";
    std::cout << "\n";
}
