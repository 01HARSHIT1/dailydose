/**
 * Basic DSA - Smallest Range I (LeetCode 908)
 * Add any value in [-k, k] independently to each element; minimize max - min.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int smallestRangeI(std::vector<int>& nums, int k) {
    auto p = std::minmax_element(nums.begin(), nums.end());
    int span = *p.second - *p.first;
    return std::max(0, span - 2 * k);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Smallest Range I\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1};
    std::cout << "[1], k=0 -> " << smallestRangeI(v1, 0) << "\n";

    std::vector<int> v2 = {0, 10};
    std::cout << "[0,10], k=2 -> " << smallestRangeI(v2, 2) << "\n";

    std::vector<int> v3 = {1, 3, 6};
    std::cout << "[1,3,6], k=3 -> " << smallestRangeI(v3, 3) << "\n";
}
