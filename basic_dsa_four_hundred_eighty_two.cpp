/**
 * Basic DSA - Single Number (LeetCode 136)
 * Every element appears twice except one. Find that element (XOR cancels pairs).
 */
#include <iostream>
#include <vector>

int singleNumber(const std::vector<int>& nums) {
    int x = 0;
    for (int n : nums)
        x ^= n;
    return x;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Single Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[4,1,2,1,2] -> " << singleNumber({4, 1, 2, 1, 2}) << "\n";
    std::cout << "[2,2,1] -> " << singleNumber({2, 2, 1}) << "\n";
}
