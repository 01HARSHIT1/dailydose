/**
 * Basic DSA - Find Minimum in Rotated Sorted Array II (LeetCode 154)
 * Find minimum in rotated sorted array with duplicates.
 */
#include <iostream>
#include <vector>

int findMin(std::vector<int>& nums) {
    int lo = 0, hi = (int)nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[hi]) lo = mid + 1;
        else if (nums[mid] < nums[hi]) hi = mid;
        else hi--;
    }
    return nums[lo];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Minimum in Rotated Sorted Array II\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 3, 5};
    std::cout << "[1,3,5] -> " << findMin(a1) << "\n";

    std::vector<int> a2 = {2, 2, 2, 0, 1};
    std::cout << "[2,2,2,0,1] -> " << findMin(a2) << "\n";
}
