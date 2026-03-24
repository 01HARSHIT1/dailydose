/**
 * Basic DSA - Longest Harmonious Subsequence (LeetCode 594)
 * Subsequence where max - min == 1; maximize length.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int findLHS(std::vector<int>& nums) {
    std::unordered_map<int, int> cnt;
    for (int x : nums)
        ++cnt[x];
    int best = 0;
    for (const auto& p : cnt) {
        int v = p.first;
        auto it = cnt.find(v + 1);
        if (it != cnt.end())
            best = std::max(best, p.second + it->second);
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Longest Harmonious Subsequence\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 3, 2, 2, 5, 2, 3, 7};
    std::cout << "[1,3,2,2,5,2,3,7] -> " << findLHS(v1) << "\n";

    std::vector<int> v2 = {1, 1, 1, 1};
    std::cout << "[1,1,1,1] -> " << findLHS(v2) << "\n";
}
