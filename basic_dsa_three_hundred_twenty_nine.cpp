/**
 * Basic DSA - Intersection of Two Arrays II (LeetCode 350)
 * Return multiset intersection (min frequency per value).
 */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    if (nums1.size() > nums2.size()) return intersect(nums2, nums1);
    std::unordered_map<int, int> cnt;
    for (int x : nums1) cnt[x]++;
    std::vector<int> ans;
    for (int x : nums2) {
        if (cnt[x] > 0) {
            ans.push_back(x);
            cnt[x]--;
        }
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Intersection of Two Arrays II\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 2, 1}, b1 = {2, 2};
    auto r1 = intersect(a1, b1);
    std::sort(r1.begin(), r1.end());
    std::cout << "[1,2,2,1] & [2,2] -> [";
    for (int i = 0; i < (int)r1.size(); i++) std::cout << (i ? "," : "") << r1[i];
    std::cout << "]\n";

    std::vector<int> a2 = {4, 9, 5}, b2 = {9, 4, 9, 8, 4};
    auto r2 = intersect(a2, b2);
    std::sort(r2.begin(), r2.end());
    std::cout << "[4,9,5] & [9,4,9,8,4] -> [";
    for (int i = 0; i < (int)r2.size(); i++) std::cout << (i ? "," : "") << r2[i];
    std::cout << "]\n";
}
