/**
 * Basic DSA - Sum of Good Numbers (LeetCode 3452)
 * nums[i] is good if it is strictly greater than nums[i-k] and nums[i+k].
 */
#include <iostream>
#include <vector>

int sumOfGoodNumbers(const std::vector<int>& nums, int k) {
    int n = static_cast<int>(nums.size());
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        if (i >= k && nums[i] <= nums[i - k])
            continue;
        if (i + k < n && nums[i] <= nums[i + k])
            continue;
        sum += nums[i];
    }
    return sum;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sum of Good Numbers\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << sumOfGoodNumbers({1, 3, 2, 1, 5, 4}, 2) << "\n";
    std::cout << "sample 2 -> " << sumOfGoodNumbers({2, 1}, 1) << "\n";
}
