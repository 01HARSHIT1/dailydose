/**
 * Basic DSA - Count Partitions with Even Sum Difference (LeetCode 3432)
 * Difference is even iff total array sum is even; answer is n - 1 or 0.
 */
#include <iostream>
#include <vector>

int countPartitions(const std::vector<int>& nums) {
    long long left = 0;
    long long right = 0;
    for (int x : nums)
        right += x;

    int ans = 0;
    for (size_t i = 0; i + 1 < nums.size(); ++i) {
        left += nums[i];
        right -= nums[i];
        if ((left - right) % 2 == 0)
            ++ans;
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count Partitions with Even Sum Difference\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << countPartitions({10, 10, 3, 7, 6}) << "\n";
    std::cout << "sample 2 -> " << countPartitions({1, 2, 2}) << "\n";
    std::cout << "sample 3 -> " << countPartitions({2, 4, 6, 8}) << "\n";
}
