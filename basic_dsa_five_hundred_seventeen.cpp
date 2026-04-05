/**
 * Basic DSA - Merge Sorted Array (LeetCode 88)
 * nums1 has length m+n; first m entries are sorted, rest is buffer. Merge sorted nums2
 * (length n) into nums1 in non-decreasing order. Fill from the back to avoid overwrite.
 * Time: O(m+n), Space: O(1) extra.
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

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            std::cout << ",";
        std::cout << v[i];
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Merge Sorted Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a = {1, 2, 3, 0, 0, 0};
    merge(a, 3, {2, 5, 6}, 3);
    printVec(a);

    std::vector<int> b = {1};
    merge(b, 1, std::vector<int>(), 0);
    printVec(b);

    std::vector<int> c = {0};
    merge(c, 0, {1}, 1);
    printVec(c);
}
