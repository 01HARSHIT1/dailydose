/**
 * Basic DSA - Remove Element (LeetCode 27)
 * Remove all instances of val in-place, return new length.
 */
#include <iostream>
#include <vector>

int removeElement(std::vector<int>& nums, int val) {
    int k = 0;
    for (int i = 0; i < (int)nums.size(); i++) {
        if (nums[i] != val) nums[k++] = nums[i];
    }
    return k;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Remove Element\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {3, 2, 2, 3};
    int k1 = removeElement(v1, 3);
    std::cout << "[3,2,2,3], 3 -> " << k1 << ", nums = [";
    for (int i = 0; i < k1; i++) std::cout << (i ? "," : "") << v1[i];
    std::cout << "]\n";

    std::vector<int> v2 = {0, 1, 2, 2, 3, 0, 4, 2};
    int k2 = removeElement(v2, 2);
    std::cout << "[0,1,2,2,3,0,4,2], 2 -> " << k2 << ", nums = [";
    for (int i = 0; i < k2; i++) std::cout << (i ? "," : "") << v2[i];
    std::cout << "]\n";
}
