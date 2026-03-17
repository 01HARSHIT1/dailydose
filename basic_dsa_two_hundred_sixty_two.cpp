/**
 * Basic DSA - Find Pivot Index (LeetCode 724)
 * Return leftmost pivot index where left sum equals right sum.
 */
#include <iostream>
#include <vector>
#include <numeric>

int pivotIndex(std::vector<int>& nums) {
    int total = std::accumulate(nums.begin(), nums.end(), 0);
    int left = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (left == total - left - nums[i]) return i;
        left += nums[i];
    }
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Pivot Index\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 7, 3, 6, 5, 6};
    std::cout << "[1,7,3,6,5,6] -> " << pivotIndex(v1) << "\n";

    std::vector<int> v2 = {1, 2, 3};
    std::cout << "[1,2,3] -> " << pivotIndex(v2) << "\n";

    std::vector<int> v3 = {2, 1, -1};
    std::cout << "[2,1,-1] -> " << pivotIndex(v3) << "\n";
}
