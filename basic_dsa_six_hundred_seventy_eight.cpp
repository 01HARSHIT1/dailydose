/**
 * Basic DSA - Find the Number of Good Pairs I (LeetCode 3162)
 * Count pairs (i,j) where nums1[i] is divisible by nums2[j]*k.
 */
#include <iostream>
#include <vector>

int numberOfPairs(const std::vector<int>& nums1, const std::vector<int>& nums2, int k) {
    int count = 0;
    for (int a : nums1) {
        for (int b : nums2) {
            if (a % (b * k) == 0)
                ++count;
        }
    }
    return count;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Number of Good Pairs I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << numberOfPairs({1, 3, 4}, {1, 3, 4}, 1) << "\n";
    std::cout << "sample 2 -> " << numberOfPairs({1, 2, 4, 12}, {2, 4}, 3) << "\n";
}
