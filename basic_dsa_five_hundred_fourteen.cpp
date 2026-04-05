/**
 * Basic DSA - Move Zeroes (LeetCode 283)
 * Move every 0 to the end of the array while keeping the relative order of non-zeros.
 * Time: O(n), Space: O(1) extra (in-place).
 */
#include <iostream>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
    size_t w = 0;
    for (size_t r = 0; r < nums.size(); ++r) {
        if (nums[r] != 0)
            nums[w++] = nums[r];
    }
    while (w < nums.size())
        nums[w++] = 0;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            std::cout << ",";
        std::cout << v[i];
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Move Zeroes\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a = {0, 1, 0, 3, 12};
    moveZeroes(a);
    printVec(a);

    std::vector<int> b = {0};
    moveZeroes(b);
    printVec(b);

    std::vector<int> c = {1, 2, 3};
    moveZeroes(c);
    printVec(c);
}
