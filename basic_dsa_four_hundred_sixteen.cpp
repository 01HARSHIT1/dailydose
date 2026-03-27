/**
 * Basic DSA - Check If a Number Is Majority Element in a Sorted Array (LeetCode 1150)
 * target is a majority element if it appears strictly more than n/2 times.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool isMajorityElement(const std::vector<int>& nums, int target) {
    auto lo = std::lower_bound(nums.begin(), nums.end(), target);
    auto hi = std::upper_bound(nums.begin(), nums.end(), target);
    int cnt = static_cast<int>(hi - lo);
    return cnt * 2 > static_cast<int>(nums.size());
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Check If a Number Is Majority Element in a Sorted Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {2, 4, 5, 5, 5, 5, 5, 6, 6};
    std::cout << "[2,4,5,5,5,5,5,6,6], target=5 -> " << (isMajorityElement(v1, 5) ? "true" : "false") << "\n";

    std::vector<int> v2 = {10, 100, 101, 101};
    std::cout << "[10,100,101,101], target=101 -> " << (isMajorityElement(v2, 101) ? "true" : "false") << "\n";
}
