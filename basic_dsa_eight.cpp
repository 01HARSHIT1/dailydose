/**
 * Basic DSA - Binary Search (LeetCode 704)
 * Find target in sorted array, return index or -1.
 */
#include <iostream>
#include <vector>

int search(std::vector<int>& nums, int target) {
    int lo = 0, hi = (int)nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Binary Search\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {-1, 0, 3, 5, 9, 12};
    std::cout << "[-1,0,3,5,9,12], target=9 -> " << search(a1, 9) << "\n";

    std::vector<int> a2 = {-1, 0, 3, 5, 9, 12};
    std::cout << "[-1,0,3,5,9,12], target=2 -> " << search(a2, 2) << "\n";

    std::vector<int> a3 = {5};
    std::cout << "[5], target=5 -> " << search(a3, 5) << "\n";
}
