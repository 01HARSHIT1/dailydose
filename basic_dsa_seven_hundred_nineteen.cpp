/**
 * Basic DSA - Apply Operations to Make All Array Elements Equal to Zero (LeetCode 2772)
 * Greedy left-to-right: subtract nums[i] from the next k-length window via diff array.
 */
#include <iostream>
#include <vector>

bool checkArray(std::vector<int> nums, int k) {
    int n = static_cast<int>(nums.size());
    std::vector<long long> diff(n + 1, 0);
    long long pending = 0;

    for (int i = 0; i < n; ++i) {
        pending += diff[i];
        nums[i] += static_cast<int>(pending);
        if (nums[i] == 0)
            continue;
        if (nums[i] < 0 || i + k > n)
            return false;
        pending -= nums[i];
        diff[i + k] += nums[i];
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Apply Operations to Make All Array Elements Equal to Zero\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << std::boolalpha
              << checkArray({2, 2, 3, 1, 1, 0}, 3) << "\n";
    std::cout << "sample 2 -> " << std::boolalpha
              << checkArray({1, 3, 1, 1}, 2) << "\n";
}
