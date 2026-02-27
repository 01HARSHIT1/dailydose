/**
 * Basic DSA - Remove Duplicates from Sorted Array (LeetCode 26)
 * Remove duplicates in-place, return count of unique elements.
 */
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0;
    int w = 1;
    for (size_t r = 1; r < nums.size(); r++) {
        if (nums[r] != nums[r - 1]) nums[w++] = nums[r];
    }
    return w;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Remove Duplicates from Sorted Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 1, 2};
    int k1 = removeDuplicates(a1);
    std::cout << "[1,1,2] -> k=" << k1 << ", nums=[1,2]\n";

    std::vector<int> a2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = removeDuplicates(a2);
    std::cout << "[0,0,1,1,1,2,2,3,3,4] -> k=" << k2 << "\n";
}
