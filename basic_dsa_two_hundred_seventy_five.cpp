/**
 * Basic DSA - Find Minimum in Rotated Sorted Array (LeetCode 153)
 * Return minimum element in rotated sorted array.
 */
#include <iostream>
#include <vector>

int findMin(std::vector<int>& nums) {
    int lo = 0, hi = nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[hi]) lo = mid + 1;
        else hi = mid;
    }
    return nums[lo];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Minimum in Rotated Sorted Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {3, 4, 5, 1, 2};
    std::cout << "[3,4,5,1,2] -> " << findMin(v1) << "\n";

    std::vector<int> v2 = {4, 5, 6, 7, 0, 1, 2};
    std::cout << "[4,5,6,7,0,1,2] -> " << findMin(v2) << "\n";

    std::vector<int> v3 = {11, 13, 15, 17};
    std::cout << "[11,13,15,17] -> " << findMin(v3) << "\n";
}
