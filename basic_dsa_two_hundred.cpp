/**
 * Basic DSA - Remove Duplicates from Sorted Array (LeetCode 26)
 * Remove duplicates in-place, return new length.
 */
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums) {
    if (nums.empty()) return 0;
    int k = 1;
    for (size_t i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[k-1]) nums[k++] = nums[i];
    }
    return k;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Remove Duplicates from Sorted Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 1, 2};
    int k1 = removeDuplicates(a1);
    std::cout << "[1,1,2] -> " << k1 << ", [";
    for (int i = 0; i < k1; i++) std::cout << (i ? "," : "") << a1[i];
    std::cout << "]\n";

    std::vector<int> a2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = removeDuplicates(a2);
    std::cout << "[0,0,1,1,1,2,2,3,3,4] -> " << k2 << ", [";
    for (int i = 0; i < k2; i++) std::cout << (i ? "," : "") << a2[i];
    std::cout << "]\n";
}
