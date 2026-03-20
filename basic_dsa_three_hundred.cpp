/**
 * Basic DSA - Single Number (LeetCode 136)
 * Every element appears twice except one; find that element.
 */
#include <iostream>
#include <vector>

int singleNumber(std::vector<int>& nums) {
    int x = 0;
    for (int n : nums) x ^= n;
    return x;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Single Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {2, 2, 1};
    std::cout << "[2,2,1] -> " << singleNumber(v1) << "\n";

    std::vector<int> v2 = {4, 1, 2, 1, 2};
    std::cout << "[4,1,2,1,2] -> " << singleNumber(v2) << "\n";

    std::vector<int> v3 = {1};
    std::cout << "[1] -> " << singleNumber(v3) << "\n";
}
