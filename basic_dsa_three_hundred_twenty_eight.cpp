/**
 * Basic DSA - Intersection of Two Arrays (LeetCode 349)
 * Return distinct elements common to both arrays.
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_set<int> a(nums1.begin(), nums1.end());
    std::unordered_set<int> b(nums2.begin(), nums2.end());
    std::vector<int> ans;
    for (int x : a) if (b.count(x)) ans.push_back(x);
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Intersection of Two Arrays\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> n1 = {1, 2, 2, 1}, n2 = {2, 2};
    auto r = intersection(n1, n2);
    std::sort(r.begin(), r.end());
    std::cout << "[1,2,2,1] & [2,2] -> [";
    for (int i = 0; i < (int)r.size(); i++) std::cout << (i ? "," : "") << r[i];
    std::cout << "]\n";

    std::vector<int> a = {4, 9, 5}, b = {9, 4, 9, 8, 4};
    auto r2 = intersection(a, b);
    std::sort(r2.begin(), r2.end());
    std::cout << "[4,9,5] & [9,4,9,8,4] -> [";
    for (int i = 0; i < (int)r2.size(); i++) std::cout << (i ? "," : "") << r2[i];
    std::cout << "]\n";
}
