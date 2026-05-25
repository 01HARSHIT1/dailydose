/**
 * Basic DSA - Maximum Value of an Ordered Triplet I (LeetCode 2873)
 * Maximize (nums[i]-nums[j])*nums[k] for i<j<k; track best i and best (i-j) difference as we scan.
 */
#include <algorithm>
#include <iostream>
#include <vector>

long long maximumTripletValue(const std::vector<int>& nums) {
    long long best = 0;
    long long maxI = 0;       // max nums[i]
    long long maxDiff = 0;    // max (nums[i] - nums[j])
    for (int k = 0; k < static_cast<int>(nums.size()); ++k) {
        best = std::max(best, maxDiff * nums[static_cast<size_t>(k)]);
        maxDiff = std::max(maxDiff, maxI - nums[static_cast<size_t>(k)]);
        maxI = std::max(maxI, static_cast<long long>(nums[static_cast<size_t>(k)]));
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Value of an Ordered Triplet I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maximumTripletValue({12, 6, 1, 2, 7}) << "\n";
    std::cout << "sample 2 -> " << maximumTripletValue({1, 10, 3, 4, 19}) << "\n";
    std::cout << "sample 3 -> " << maximumTripletValue({1, 2, 3}) << "\n";
}
