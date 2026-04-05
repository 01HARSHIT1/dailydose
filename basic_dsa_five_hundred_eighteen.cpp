/**
 * Basic DSA - Missing Number (LeetCode 268)
 * nums has n distinct values from {0..n} with exactly one integer from that range missing.
 * XOR together all indices 0..n-1, all nums[i], and n; pairs cancel to the missing value.
 * Time: O(n), Space: O(1).
 */
#include <iostream>
#include <vector>

int missingNumber(const std::vector<int>& nums) {
    int x = static_cast<int>(nums.size());
    for (int i = 0; i < static_cast<int>(nums.size()); ++i)
        x ^= i ^ nums[i];
    return x;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Missing Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[3,0,1] -> " << missingNumber({3, 0, 1}) << "\n";
    std::cout << "[0,1] -> " << missingNumber({0, 1}) << "\n";
    std::cout << "[9,6,4,2,3,5,7,0,1] -> " << missingNumber({9, 6, 4, 2, 3, 5, 7, 0, 1}) << "\n";
}
