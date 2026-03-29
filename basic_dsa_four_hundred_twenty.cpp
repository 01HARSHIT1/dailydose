/**
 * Basic DSA - Check If It Is a Straight Line (LeetCode 1232)
 * At least two distinct points; check if all lie on one infinite line.
 */
#include <iostream>
#include <string>
#include <vector>

bool checkStraightLine(const std::vector<std::vector<int>>& coordinates) {
    int n = static_cast<int>(coordinates.size());
    if (n <= 2)
        return true;
    int x0 = coordinates[0][0];
    int y0 = coordinates[0][1];
    int x1 = coordinates[1][0];
    int y1 = coordinates[1][1];
    for (int i = 2; i < n; ++i) {
        int x = coordinates[i][0];
        int y = coordinates[i][1];
        long long lhs = static_cast<long long>(x1 - x0) * (y - y0);
        long long rhs = static_cast<long long>(y1 - y0) * (x - x0);
        if (lhs != rhs)
            return false;
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Check If It Is a Straight Line\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> a = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
    std::cout << "collinear six points -> " << (checkStraightLine(a) ? "true" : "false") << "\n";

    std::vector<std::vector<int>> b = {{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
    std::cout << "with one bend -> " << (checkStraightLine(b) ? "true" : "false") << "\n";
}
