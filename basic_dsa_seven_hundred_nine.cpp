/**
 * Basic DSA - Maximum Frequency After Subarray Operation (LeetCode 3434)
 * Pick a subarray and add x once; maximize how many elements equal k.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int kadaneGain(const std::vector<int>& nums, int target, int k) {
    int maxSum = 0;
    int sum = 0;
    for (int num : nums) {
        if (num == target)
            ++sum;
        else if (num == k)
            --sum;
        if (sum < 0)
            sum = 0;
        maxSum = std::max(maxSum, sum);
    }
    return maxSum;
}

int maxFrequency(const std::vector<int>& nums, int k) {
    int countK = 0;
    for (int x : nums)
        if (x == k)
            ++countK;

    int bestGain = 0;
    for (int target = 1; target <= 50; ++target) {
        if (target == k)
            continue;
        bestGain = std::max(bestGain, kadaneGain(nums, target, k));
    }
    return countK + bestGain;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Frequency After Subarray Operation\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxFrequency({1, 2, 3, 4, 5, 6}, 1) << "\n";
    std::cout << "sample 2 -> " << maxFrequency({10, 2, 3, 4, 5, 5, 4, 3, 2, 2}, 10) << "\n";
}
