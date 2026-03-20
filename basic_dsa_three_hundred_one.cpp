/**
 * Basic DSA - Single Number II (LeetCode 137)
 * Every element appears three times except one; find that element.
 */
#include <iostream>
#include <vector>

int singleNumber(std::vector<int>& nums) {
    int ones = 0, twos = 0;
    for (int n : nums) {
        ones = (ones ^ n) & ~twos;
        twos = (twos ^ n) & ~ones;
    }
    return ones;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Single Number II\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {2, 2, 3, 2};
    std::cout << "[2,2,3,2] -> " << singleNumber(v1) << "\n";

    std::vector<int> v2 = {0, 1, 0, 1, 0, 1, 99};
    std::cout << "[0,1,0,1,0,1,99] -> " << singleNumber(v2) << "\n";
}
