/**
 * Basic DSA - Array Partition (LeetCode 561)
 * Pair 2n integers to maximize the sum of the smaller number in each pair.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int arrayPairSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int s = 0;
    for (size_t i = 0; i < nums.size(); i += 2)
        s += nums[i];
    return s;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Array Partition\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 4, 3, 2};
    std::cout << "[1,4,3,2] -> " << arrayPairSum(v1) << "\n";

    std::vector<int> v2 = {6, 2, 6, 5, 1, 2};
    std::cout << "[6,2,6,5,1,2] -> " << arrayPairSum(v2) << "\n";
}
