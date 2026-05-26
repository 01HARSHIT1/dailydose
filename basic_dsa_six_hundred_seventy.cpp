/**
 * Basic DSA - Find Common Elements Between Two Arrays (LeetCode 2956)
 * answer[0]: count in nums1 also present in nums2; answer[1]: count in nums2 also present in nums1.
 */
#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<int> findIntersectionValues(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> set2(nums2.begin(), nums2.end());

    int count1 = 0;
    for (int v : nums1)
        if (set2.count(v))
            ++count1;

    int count2 = 0;
    for (int v : nums2)
        if (set1.count(v))
            ++count2;

    return {count1, count2};
}

void printVec(const std::vector<int>& v) {
    std::cout << "[" << v[0] << "," << v[1] << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Common Elements Between Two Arrays\n";
    std::cout << std::string(60, '=') << "\n";

    printVec(findIntersectionValues({4, 3, 2, 3, 1}, {2, 2, 5, 2, 3, 6}));
    printVec(findIntersectionValues({3, 4, 2, 3}, {1, 5}));
}
