/**
 * Basic DSA - Form Smallest Number From Two Digit Arrays (LeetCode 2605)
 * If a digit is shared, that single digit is the answer; otherwise combine the two smallest digits in order.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int minNumber(std::vector<int> nums1, std::vector<int> nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.begin(), nums2.end());

    int common = 10;
    for (int a : nums1) {
        for (int b : nums2) {
            if (a == b)
                common = std::min(common, a);
        }
    }
    if (common != 10)
        return common;

    int small = std::min(nums1[0], nums2[0]);
    int large = std::max(nums1[0], nums2[0]);
    return small * 10 + large;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Form Smallest Number From Two Digit Arrays\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minNumber({4, 1, 3}, {5, 7}) << "\n";
    std::cout << "sample 2 -> " << minNumber({3, 5, 2, 6}, {3, 1, 7}) << "\n";
}
