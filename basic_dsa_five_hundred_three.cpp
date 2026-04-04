/**
 * Basic DSA - Binary Search (LeetCode 704)
 * nums is sorted ascending and strictly increasing; return index of target or -1.
 */
#include <iostream>
#include <vector>

int search(const std::vector<int>& nums, int target) {
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
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Binary Search\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a = {-1, 0, 3, 5, 9, 12};
    std::cout << "[-1,0,3,5,9,12], target=9 -> " << search(a, 9) << "\n";
    std::cout << "[-1,0,3,5,9,12], target=2 -> " << search(a, 2) << "\n";
}
