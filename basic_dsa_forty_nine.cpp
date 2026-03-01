/**
 * Basic DSA - Intersection of Two Arrays (LeetCode 349)
 * Return unique elements present in both arrays.
 */
#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> set1(nums1.begin(), nums1.end());
    std::unordered_set<int> out;
    for (int x : nums2)
        if (set1.count(x)) out.insert(x);
    return std::vector<int>(out.begin(), out.end());
}

void print(std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i];
        if (i + 1 < v.size()) std::cout << ",";
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Intersection of Two Arrays\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 2, 1};
    std::vector<int> a2 = {2, 2};
    auto r1 = intersection(a1, a2);
    std::cout << "[1,2,2,1], [2,2] -> ";
    print(r1);

    std::vector<int> b1 = {4, 9, 5};
    std::vector<int> b2 = {9, 4, 9, 8, 4};
    auto r2 = intersection(b1, b2);
    std::cout << "[4,9,5], [9,4,9,8,4] -> ";
    print(r2);
}
