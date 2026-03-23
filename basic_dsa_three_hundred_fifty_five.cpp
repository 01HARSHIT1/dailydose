/**
 * Basic DSA - Longest Increasing Subsequence (LeetCode 300)
 * Length of strictly increasing subsequence (patience / binary search).
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int lengthOfLIS(std::vector<int>& nums) {
    std::vector<int> tail;
    for (int x : nums) {
        auto it = std::lower_bound(tail.begin(), tail.end(), x);
        if (it == tail.end()) tail.push_back(x);
        else *it = x;
    }
    return tail.size();
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Longest Increasing Subsequence\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << "example 1 -> " << lengthOfLIS(v1) << "\n";

    std::vector<int> v2 = {0, 1, 0, 3, 2, 3};
    std::cout << "example 2 -> " << lengthOfLIS(v2) << "\n";
}
