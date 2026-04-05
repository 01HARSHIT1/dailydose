/**
 * Basic DSA - Single Number (LeetCode 136)
 * Every element appears exactly twice except one. Find the element that appears once.
 * XOR: a ^ a = 0 and a ^ 0 = a, so pairing duplicates cancels them out.
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
    std::cout << "Problem: Single Number (XOR)\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[2,2,1] -> " << singleNumber({2, 2, 1}) << "\n";
    std::cout << "[4,1,2,1,2] -> " << singleNumber({4, 1, 2, 1, 2}) << "\n";
    std::cout << "[1] -> " << singleNumber({1}) << "\n";
}
