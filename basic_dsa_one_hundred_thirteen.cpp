/**
 * Basic DSA - Trapping Rain Water (LeetCode 42)
 * Compute how much water can be trapped after raining.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int trap(std::vector<int>& height) {
    int n = height.size();
    if (n < 3) return 0;
    int left = 0, right = n - 1;
    int maxL = 0, maxR = 0, ans = 0;
    while (left < right) {
        if (height[left] <= height[right]) {
            maxL = std::max(maxL, height[left]);
            ans += maxL - height[left];
            left++;
        } else {
            maxR = std::max(maxR, height[right]);
            ans += maxR - height[right];
            right--;
        }
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Trapping Rain Water\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << "[0,1,0,2,1,0,1,3,2,1,2,1] -> " << trap(a1) << "\n";

    std::vector<int> a2 = {4, 2, 0, 3, 2, 5};
    std::cout << "[4,2,0,3,2,5] -> " << trap(a2) << "\n";

    std::vector<int> a3 = {1, 2, 3};
    std::cout << "[1,2,3] -> " << trap(a3) << "\n";
}
