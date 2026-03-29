/**
 * Basic DSA - Find Nearest Point That Has the Same X or Y Coordinate (LeetCode 1779)
 * Among points sharing x with (x,y) or sharing y with (x,y), return the index with
 * smallest squared Euclidean distance; if none, return -1 (tie -> smaller index).
 */
#include <climits>
#include <iostream>
#include <vector>

int nearestValidPoint(int x, int y, const std::vector<std::vector<int>>& points) {
    int bestIdx = -1;
    long long bestDist = LLONG_MAX;
    for (int i = 0; i < static_cast<int>(points.size()); ++i) {
        int px = points[i][0];
        int py = points[i][1];
        if (px != x && py != y)
            continue;
        long long dx = static_cast<long long>(px) - x;
        long long dy = static_cast<long long>(py) - y;
        long long d = dx * dx + dy * dy;
        if (d < bestDist) {
            bestDist = d;
            bestIdx = i;
        }
    }
    return bestIdx;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Nearest Point Same X or Y\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> p1 = {{1, 2}, {3, 1}, {2, 4}, {2, 3}, {4, 4}};
    std::cout << "(3,4) points -> " << nearestValidPoint(3, 4, p1) << "\n";

    std::vector<std::vector<int>> p2 = {{3, 4}};
    std::cout << "(3,4) single -> " << nearestValidPoint(3, 4, p2) << "\n";

    std::vector<std::vector<int>> p3 = {{2, 3}};
    std::cout << "(3,4) none -> " << nearestValidPoint(3, 4, p3) << "\n";
}
