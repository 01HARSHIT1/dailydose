/**
 * Basic DSA - Search in Rotated Sorted Array (LeetCode 33)
 * Search target in rotated sorted array, return index or -1.
 */
#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        if (nums[lo] <= nums[mid]) {
            if (target >= nums[lo] && target < nums[mid]) hi = mid - 1;
            else lo = mid + 1;
        } else {
            if (target > nums[mid] && target <= nums[hi]) lo = mid + 1;
            else hi = mid - 1;
        }
    }
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Search in Rotated Sorted Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {4, 5, 6, 7, 0, 1, 2};
    std::cout << "[4,5,6,7,0,1,2], target=0 -> " << search(a1, 0) << "\n";

    std::vector<int> a2 = {4, 5, 6, 7, 0, 1, 2};
    std::cout << "[4,5,6,7,0,1,2], target=3 -> " << search(a2, 3) << "\n";

    std::vector<int> a3 = {1};
    std::cout << "[1], target=1 -> " << search(a3, 1) << "\n";
}
