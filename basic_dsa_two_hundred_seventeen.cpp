/**
 * Basic DSA - Find Peak Element (LeetCode 162)
 * Find a peak element (greater than neighbors) in O(log n).
 */
#include <iostream>
#include <vector>

int findPeakElement(std::vector<int>& nums) {
    int lo = 0, hi = (int)nums.size() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] > nums[mid + 1]) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Peak Element\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 3, 1};
    std::cout << "[1,2,3,1] -> index " << findPeakElement(a1) << "\n";

    std::vector<int> a2 = {1, 2, 1, 3, 5, 6, 4};
    std::cout << "[1,2,1,3,5,6,4] -> index " << findPeakElement(a2) << "\n";
}
