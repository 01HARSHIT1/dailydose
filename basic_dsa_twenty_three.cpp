/**
 * Basic DSA - Merge Sorted Array (LeetCode 88)
 * Merge two sorted arrays into the first in-place.
 */
#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int i = m - 1, j = n - 1, k = m + n - 1;
    while (i >= 0 && j >= 0) {
        if (nums1[i] >= nums2[j]) nums1[k--] = nums1[i--];
        else nums1[k--] = nums2[j--];
    }
    while (j >= 0) nums1[k--] = nums2[j--];
}

void print(std::vector<int>& v, int len) {
    std::cout << "[";
    for (int i = 0; i < len; i++) {
        std::cout << v[i];
        if (i + 1 < len) std::cout << ",";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Merge Sorted Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> a2 = {2, 5, 6};
    merge(a1, 3, a2, 3);
    std::cout << "[1,2,3,0,0,0] + [2,5,6] -> ";
    print(a1, 6);

    std::vector<int> b1 = {1};
    std::vector<int> b2 = {};
    merge(b1, 1, b2, 0);
    std::cout << "[1] + [] -> ";
    print(b1, 1);
}
