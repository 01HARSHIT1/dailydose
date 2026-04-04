/**
 * Basic DSA - Missing Number (LeetCode 268)
 * nums contains n distinct integers from [0..n] with exactly one missing; find it.
 * XOR: 0^1^...^n ^ (all nums) leaves the missing value.
 */
#include <iostream>
#include <vector>

int missingNumber(const std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    int x = n;
    for (int i = 0; i < n; ++i)
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
