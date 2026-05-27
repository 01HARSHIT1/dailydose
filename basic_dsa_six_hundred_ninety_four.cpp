/**
 * Basic DSA - Identify the Largest Outlier in an Array (LeetCode 3371)
 * If x is the outlier, (total - x) is even and (total - x) / 2 must appear in nums.
 */
#include <algorithm>
#include <climits>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

int getLargestOutlier(const std::vector<int>& nums) {
    int total = std::accumulate(nums.begin(), nums.end(), 0);
    std::unordered_map<int, int> count;
    for (int v : nums)
        ++count[v];

    int best = INT_MIN;
    for (int x : nums) {
        int without = total - x;
        if (without % 2 != 0)
            continue;
        int specialSum = without / 2;
        if (count[specialSum] > (x == specialSum ? 1 : 0))
            best = std::max(best, x);
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Identify the Largest Outlier in an Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << getLargestOutlier({2, 3, 5, 10}) << "\n";
    std::cout << "sample 2 -> " << getLargestOutlier({-2, -1, -3, -6, 4}) << "\n";
    std::cout << "sample 3 -> " << getLargestOutlier({1, 1, 1, 1, 1, 5, 5}) << "\n";
}
