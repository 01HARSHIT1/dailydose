/**
 * Basic DSA - Binary Search (LeetCode 704)
 * Return index of target in sorted array, or -1.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int search(std::vector<int>& nums, int target) {
    auto it = std::lower_bound(nums.begin(), nums.end(), target);
    if (it != nums.end() && *it == target) return it - nums.begin();
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Binary Search\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {-1, 0, 3, 5, 9, 12};
    std::cout << "[-1,0,3,5,9,12], 9 -> " << search(v1, 9) << "\n";

    std::vector<int> v2 = {-1, 0, 3, 5, 9, 12};
    std::cout << "[-1,0,3,5,9,12], 2 -> " << search(v2, 2) << "\n";

    std::vector<int> v3 = {5};
    std::cout << "[5], 5 -> " << search(v3, 5) << "\n";
}
