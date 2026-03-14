/**
 * Basic DSA - Median of Two Sorted Arrays (LeetCode 4)
 * Find median of two sorted arrays in O(log(min(m,n))).
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
    int m = nums1.size(), n = nums2.size();
    int lo = 0, hi = m;
    while (lo <= hi) {
        int i = (lo + hi) / 2;
        int j = (m + n + 1) / 2 - i;
        int l1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int r1 = (i == m) ? INT_MAX : nums1[i];
        int l2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int r2 = (j == n) ? INT_MAX : nums2[j];
        if (l1 <= r2 && l2 <= r1) {
            if ((m + n) % 2) return std::max(l1, l2);
            return (std::max(l1, l2) + std::min(r1, r2)) / 2.0;
        }
        if (l1 > r2) hi = i - 1;
        else lo = i + 1;
    }
    return 0;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Median of Two Sorted Arrays\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 3}, b1 = {2};
    std::cout << "[1,3] + [2] -> " << findMedianSortedArrays(a1, b1) << "\n";

    std::vector<int> a2 = {1, 2}, b2 = {3, 4};
    std::cout << "[1,2] + [3,4] -> " << findMedianSortedArrays(a2, b2) << "\n";
}
