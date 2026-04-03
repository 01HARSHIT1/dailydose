/**
 * Basic DSA - Move Zeroes (LeetCode 283)
 * In-place: keep relative order of non-zero elements; shift all zeros to the end.
 */
#include <iostream>
#include <utility>
#include <vector>

void moveZeroes(std::vector<int>& nums) {
    int j = 0;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        if (nums[i] != 0) {
            std::swap(nums[j], nums[i]);
            ++j;
        }
    }
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Move Zeroes\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a = {0, 1, 0, 3, 12};
    printVec(a);
    std::cout << " -> ";
    moveZeroes(a);
    printVec(a);
    std::cout << "\n";

    std::vector<int> b = {0};
    printVec(b);
    std::cout << " -> ";
    moveZeroes(b);
    printVec(b);
    std::cout << "\n";
}
