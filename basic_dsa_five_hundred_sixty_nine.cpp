/**
 * Basic DSA - Single Element in a Sorted Array (LeetCode 540)
 * All but one value appear twice in sorted order. Binary search on even indices: pair with right neighbor if singleton is to the right, else search left.
 */
#include <iostream>
#include <vector>

int singleNonDuplicate(const std::vector<int>& nums) {
    int lo = 0;
    int hi = static_cast<int>(nums.size()) - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (mid % 2 == 1)
            --mid;
        if (nums[static_cast<size_t>(mid)] == nums[static_cast<size_t>(mid + 1)])
            lo = mid + 2;
        else
            hi = mid;
    }
    return nums[static_cast<size_t>(lo)];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Single Element in a Sorted Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[1,1,2,3,3,4,4,8,8]   -> " << singleNonDuplicate({1, 1, 2, 3, 3, 4, 4, 8, 8}) << "\n";
    std::cout << "[3,3,7,7,10,11,11]    -> " << singleNonDuplicate({3, 3, 7, 7, 10, 11, 11}) << "\n";
}
