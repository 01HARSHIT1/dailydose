/**
 * Basic DSA - Search Insert Position (LeetCode 35)
 * Return index where target would be inserted in sorted array.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int searchInsert(std::vector<int>& nums, int target) {
    return std::lower_bound(nums.begin(), nums.end(), target) - nums.begin();
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Search Insert Position\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 3, 5, 6};
    std::cout << "[1,3,5,6], 5 -> " << searchInsert(v1, 5) << "\n";

    std::vector<int> v2 = {1, 3, 5, 6};
    std::cout << "[1,3,5,6], 2 -> " << searchInsert(v2, 2) << "\n";

    std::vector<int> v3 = {1, 3, 5, 6};
    std::cout << "[1,3,5,6], 7 -> " << searchInsert(v3, 7) << "\n";
}
