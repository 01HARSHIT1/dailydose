/**
 * Basic DSA - Single Number (LeetCode 136)
 * Find the single element in array where every other appears twice.
 */
#include <iostream>
#include <vector>

int singleNumber(std::vector<int>& nums) {
    int ans = 0;
    for (int x : nums) ans ^= x;
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Single Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {2, 2, 1};
    std::cout << "[2,2,1] -> " << singleNumber(a1) << "\n";

    std::vector<int> a2 = {4, 1, 2, 1, 2};
    std::cout << "[4,1,2,1,2] -> " << singleNumber(a2) << "\n";

    std::vector<int> a3 = {1};
    std::cout << "[1] -> " << singleNumber(a3) << "\n";
}
