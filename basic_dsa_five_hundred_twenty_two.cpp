/**
 * Basic DSA - Search Insert Position (LeetCode 35)
 * nums is sorted with distinct values. Return the index of target, or the index where
 * target would be inserted in order. Classic binary search; answer is lo when the
 * search range is empty.
 * Time: O(log n), Space: O(1).
 */
#include <iostream>
#include <vector>

int searchInsert(const std::vector<int>& nums, int target) {
    int lo = 0;
    int hi = static_cast<int>(nums.size()) - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target)
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return lo;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Search Insert Position\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a = {1, 3, 5, 6};
    std::cout << "[1,3,5,6] target=5 -> " << searchInsert(a, 5) << "\n";
    std::cout << "[1,3,5,6] target=2 -> " << searchInsert(a, 2) << "\n";
    std::cout << "[1,3,5,6] target=7 -> " << searchInsert(a, 7) << "\n";
}
