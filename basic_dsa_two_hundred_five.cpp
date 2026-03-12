/**
 * Basic DSA - Container With Most Water (LeetCode 11)
 * Find two lines that form container with most water.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int maxArea(std::vector<int>& height) {
    int ans = 0, i = 0, j = (int)height.size() - 1;
    while (i < j) {
        ans = std::max(ans, (j - i) * std::min(height[i], height[j]));
        if (height[i] < height[j]) i++;
        else j--;
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
}
