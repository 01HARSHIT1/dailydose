/**
 * Basic DSA - Container With Most Water (LeetCode 11)
 * Find two lines that form container with most water.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int maxArea(std::vector<int>& height) {
    int lo = 0, hi = height.size() - 1, ans = 0;
    while (lo < hi) {
        ans = std::max(ans, (hi - lo) * std::min(height[lo], height[hi]));
        if (height[lo] < height[hi]) lo++;
        else hi--;
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Container With Most Water\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    std::cout << "[1,8,6,2,5,4,8,3,7] -> " << maxArea(a1) << "\n";

    std::vector<int> a2 = {1, 1};
    std::cout << "[1,1] -> " << maxArea(a2) << "\n";

    std::vector<int> a3 = {4, 3, 2, 1, 4};
    std::cout << "[4,3,2,1,4] -> " << maxArea(a3) << "\n";
}
