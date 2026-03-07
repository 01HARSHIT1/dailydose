/**
 * Basic DSA - Longest Increasing Subsequence (LeetCode 300)
 * Length of longest strictly increasing subsequence (binary search).
 */
#include <iostream>
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

    std::vector<int> a1 = {10, 9, 2, 5, 3, 7, 101, 18};
    std::cout << "[10,9,2,5,3,7,101,18] -> " << lengthOfLIS(a1) << "\n";

    std::vector<int> a2 = {0, 1, 0, 3, 2, 3};
    std::cout << "[0,1,0,3,2,3] -> " << lengthOfLIS(a2) << "\n";

    std::vector<int> a3 = {7, 7, 7, 7, 7, 7, 7};
    std::cout << "[7,7,7,7,7,7,7] -> " << lengthOfLIS(a3) << "\n";
}
