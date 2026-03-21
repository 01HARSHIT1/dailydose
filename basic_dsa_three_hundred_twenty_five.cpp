/**
 * Basic DSA - Longest Consecutive Sequence (LeetCode 128)
 * Length of longest run of consecutive integers in nums.
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int longestConsecutive(std::vector<int>& nums) {
    std::unordered_set<int> s(nums.begin(), nums.end());
    int best = 0;
    for (int x : s) {
        if (s.count(x - 1)) continue;
        int y = x, len = 0;
        while (s.count(y)) { y++; len++; }
        best = std::max(best, len);
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Longest Consecutive Sequence\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {100, 4, 200, 1, 3, 2};
    std::cout << "[100,4,200,1,3,2] -> " << longestConsecutive(v1) << "\n";

    std::vector<int> v2 = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
    std::cout << "[0,3,7,2,5,8,4,6,0,1] -> " << longestConsecutive(v2) << "\n";
}
