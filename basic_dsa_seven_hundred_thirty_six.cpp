/**
 * Basic DSA - Transform Array by Parity (LeetCode 3467)
 * Replace evens with 0, odds with 1, then sort non-decreasing.
 */

#include <iostream>
#include <vector>

std::vector<int> transformArray(std::vector<int> nums) {
    int evenCount = 0;
    for (int value : nums)
        evenCount += (value % 2 == 0);

    for (int i = 0; i < evenCount; ++i)
        nums[i] = 0;
    for (int i = evenCount; i < static_cast<int>(nums.size()); ++i)
        nums[i] = 1;

    return nums;
}

void printArray(const std::vector<int>& values) {
    std::cout << "[";
    for (int i = 0; i < static_cast<int>(values.size()); ++i) {
        if (i > 0)
            std::cout << ", ";
        std::cout << values[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Transform Array by Parity\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printArray(transformArray({4, 3, 2, 1}));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printArray(transformArray({1, 5, 1, 4, 2}));
    std::cout << "\n";
}
