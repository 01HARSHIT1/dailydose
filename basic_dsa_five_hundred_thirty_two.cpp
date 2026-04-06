/**
 * Basic DSA - Binary Search (LeetCode 704)
 * Find the index of target in a sorted array using binary search.
 */
#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& nums, int target) {
    int left = 0;
    int right = static_cast<int>(nums.size()) - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Binary Search\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a{ -1, 0, 3, 5, 9, 12 };
    std::cout << "[-1,0,3,5,9,12], target=9  -> " << binarySearch(a, 9) << "\n";
    std::cout << "[-1,0,3,5,9,12], target=2  -> " << binarySearch(a, 2) << "\n";

    std::vector<int> b{ 1 };
    std::cout << "[1], target=1              -> " << binarySearch(b, 1) << "\n";
    std::cout << "[1], target=0              -> " << binarySearch(b, 0) << "\n";

    std::vector<int> c{};
    std::cout << "[], target=42              -> " << binarySearch(c, 42) << "\n";
}

