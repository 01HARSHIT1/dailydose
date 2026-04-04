/**
 * Basic DSA - Intersection of Two Arrays (LeetCode 349)
 * Each value in the output appears in both arrays; no duplicates in the output.
 */
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<int> intersection(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::unordered_set<int> in1(nums1.begin(), nums1.end());
    std::unordered_set<int> out;
    for (int x : nums2) {
        if (in1.count(x))
            out.insert(x);
    }
    return std::vector<int>(out.begin(), out.end());
}

void printSorted(const std::vector<int>& v) {
    std::vector<int> a = v;
    std::sort(a.begin(), a.end());
    std::cout << "[";
    for (size_t i = 0; i < a.size(); ++i) {
        if (i)
            std::cout << ", ";
        std::cout << a[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Intersection of Two Arrays\n";
    std::cout << std::string(60, '=') << "\n";

    printSorted(intersection({1, 2, 2, 1}, {2, 2}));
    std::cout << "\n";

    printSorted(intersection({4, 9, 5}, {9, 4, 9, 8, 4}));
    std::cout << "\n";
}
