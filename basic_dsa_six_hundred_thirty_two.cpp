/**
 * Basic DSA - Maximize Greatness of an Array (LeetCode 2592)
 * Sort, then greedily match each element to a strictly larger one with two pointers.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int maximizeGreatness(std::vector<int> nums) {
    std::sort(nums.begin(), nums.end());
    int count = 0;
    size_t i = 0;
    for (size_t j = 0; j < nums.size(); ++j) {
        if (nums[j] > nums[i]) {
            ++count;
            ++i;
        }
    }
    return count;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximize Greatness of an Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maximizeGreatness({1, 3, 5, 2, 1, 3, 1}) << "\n";
    std::cout << "sample 2 -> " << maximizeGreatness({1, 2, 3, 4}) << "\n";
}
