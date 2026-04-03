/**
 * Basic DSA - Merge Sorted Array (LeetCode 88)
 * nums1 has length m+n; first m entries sorted, rest unused. Merge nums2 (length n)
 * into nums1 in non-decreasing order (in-place, fill from the back).
 */
#include <iostream>
#include <vector>

void merge(std::vector<int>& nums1, int m, const std::vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;
    while (j >= 0) {
        if (i >= 0 && nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
}

void printVec(const std::vector<int>& v, int len) {
    std::cout << "[";
    for (int i = 0; i < len; ++i) {
        if (i)
            std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Merge Sorted Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a = {1, 2, 3, 0, 0, 0};
    std::vector<int> b = {2, 5, 6};
    printVec(a, 6);
    std::cout << " + ";
    printVec(b, static_cast<int>(b.size()));
    std::cout << " -> ";
    merge(a, 3, b, 3);
    printVec(a, 6);
    std::cout << "\n";
}
