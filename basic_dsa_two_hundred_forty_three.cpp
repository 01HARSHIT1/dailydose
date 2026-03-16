/**
 * Basic DSA - Array Partition (LeetCode 561)
 * Maximize sum of min(a,b) for each pair.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int arrayPairSum(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    int sum = 0;
    for (int i = 0; i < (int)nums.size(); i += 2) sum += nums[i];
    return sum;
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
