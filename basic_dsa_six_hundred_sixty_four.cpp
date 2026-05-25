/**
 * Basic DSA - Points That Intersect With Cars (LeetCode 2848)
 * Mark covered integer points with a difference array, then count positions with positive coverage.
 */
#include <array>
#include <iostream>
#include <vector>

int numberOfPoints(const std::vector<std::vector<int>>& nums) {
    std::array<int, 102> diff{};
    for (const auto& car : nums) {
        ++diff[static_cast<size_t>(car[0])];
        --diff[static_cast<size_t>(car[1] + 1)];
    }
    int covered = 0;
    int running = 0;
    for (size_t i = 1; i <= 100; ++i) {
        running += diff[i];
        if (running > 0)
            ++covered;
    }
    return covered;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Points That Intersect With Cars\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << numberOfPoints({{3, 6}, {1, 5}, {4, 7}}) << "\n";
    std::cout << "sample 2 -> " << numberOfPoints({{1, 3}, {5, 8}}) << "\n";
}
