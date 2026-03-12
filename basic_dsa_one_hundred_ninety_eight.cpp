/**
 * Basic DSA - Merge Sorted Array (LeetCode 88)
 * Merge nums2 into nums1 in-place (nums1 has extra space for result).
 */
#include <iostream>
#include <vector>
#include <algorithm>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Merge Sorted Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> b1 = {2, 5, 6};
    merge(a1, 3, b1, 3);
    std::cout << "[1,2,3] + [2,5,6] -> [";
    for (size_t i = 0; i < a1.size(); i++) std::cout << (i ? "," : "") << a1[i];
    std::cout << "]\n";

    std::vector<int> a2 = {1};
    std::vector<int> b2 = {};
    merge(a2, 1, b2, 0);
    std::cout << "[1] + [] -> [1]\n";
}
