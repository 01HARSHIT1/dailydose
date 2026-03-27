/**
 * Basic DSA - Valid Boomerang (LeetCode 1037)
 * Three distinct points form a boomerang iff they are not collinear.
 */
#include <iostream>
#include <string>
#include <vector>

bool isBoomerang(const std::vector<std::vector<int>>& p) {
    long long dx1 = p[1][0] - p[0][0];
    long long dy1 = p[1][1] - p[0][1];
    long long dx2 = p[2][0] - p[0][0];
    long long dy2 = p[2][1] - p[0][1];
    return dx1 * dy2 != dx2 * dy1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Valid Boomerang\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> a = {{1, 1}, {2, 3}, {3, 2}};
    std::cout << "[[1,1],[2,3],[3,2]] -> " << (isBoomerang(a) ? "true" : "false") << "\n";

    std::vector<std::vector<int>> b = {{1, 1}, {2, 2}, {3, 3}};
    std::cout << "[[1,1],[2,2],[3,3]] -> " << (isBoomerang(b) ? "true" : "false") << "\n";
}
