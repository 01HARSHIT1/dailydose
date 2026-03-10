/**
 * Basic DSA - Intersection of Two Arrays II (LeetCode 350)
 * Return intersection of two arrays (each element as many times as it appears in both).
 */
#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_map<int, int> freq;
    for (int x : nums1) freq[x]++;
    std::vector<int> out;
    for (int x : nums2) {
        if (freq[x]-- > 0) out.push_back(x);
    }
    return out;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Intersection of Two Arrays II\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 2, 1}, b1 = {2, 2};
    auto r1 = intersect(a1, b1);
    std::cout << "[1,2,2,1] & [2,2] -> [";
    for (size_t i = 0; i < r1.size(); i++) std::cout << (i ? "," : "") << r1[i];
    std::cout << "]\n";

    std::vector<int> a2 = {4, 9, 5}, b2 = {9, 4, 9, 8, 4};
    auto r2 = intersect(a2, b2);
    std::cout << "[4,9,5] & [9,4,9,8,4] -> [";
    for (size_t i = 0; i < r2.size(); i++) std::cout << (i ? "," : "") << r2[i];
    std::cout << "]\n";
}
