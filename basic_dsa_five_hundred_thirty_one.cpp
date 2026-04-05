/**
 * Basic DSA - Intersection of Two Arrays (LeetCode 349)
 * Return each distinct integer that appears in both nums1 and nums2 (any order).
 * Put nums2 in a set, scan nums1, collect first-seen matches. Time: O(m+n), Space: O(m+n).
 */
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>

std::vector<int> intersection(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    std::unordered_set<int> in2(nums2.begin(), nums2.end());
    std::unordered_set<int> picked;
    std::vector<int> out;
    for (int x : nums1) {
        if (in2.count(x) && picked.insert(x).second)
            out.push_back(x);
    }
    std::sort(out.begin(), out.end());
    return out;
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
    std::cout << "Problem: Intersection of Two Arrays\n";
    std::cout << std::string(60, '=') << "\n";

    printVec(intersection({1, 2, 2, 1}, {2, 2}));
    printVec(intersection({4, 9, 5}, {9, 4, 9, 8, 4}));
}
