/**
 * Basic DSA - Search Insert Position (LeetCode 35)
 * Find index to insert target in sorted array.
 */
#include <iostream>
#include <vector>

int searchInsert(std::vector<int>& nums, int target) {
    int lo = 0, hi = (int)nums.size();
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Search Insert Position\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 3, 5, 6};
    std::cout << "[1,3,5,6], 5 -> " << searchInsert(a1, 5) << "\n";

    std::vector<int> a2 = {1, 3, 5, 6};
    std::cout << "[1,3,5,6], 2 -> " << searchInsert(a2, 2) << "\n";

    std::vector<int> a3 = {1, 3, 5, 6};
    std::cout << "[1,3,5,6], 7 -> " << searchInsert(a3, 7) << "\n";
}
