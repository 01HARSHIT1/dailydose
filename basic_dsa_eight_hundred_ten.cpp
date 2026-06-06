/**
 * Basic DSA - Smallest Index With Digit Sum Equal to Index (LeetCode 3550)
 * Linear scan comparing each index with the digit sum of its value.
 */

#include <iostream>
#include <vector>

int digitSum(int value) {
    int sum = 0;
    while (value > 0) {
        sum += value % 10;
        value /= 10;
    }
    return sum;
}

int smallestMatchingIndex(const std::vector<int>& values) {
    for (int index = 0; index < static_cast<int>(values.size()); ++index) {
        if (digitSum(values[index]) == index)
            return index;
    }
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Smallest Index With Digit Sum Equal to Index\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << smallestMatchingIndex({1, 3, 2}) << "\n";
    std::cout << "sample 2 -> " << smallestMatchingIndex({1, 10, 11}) << "\n";
    std::cout << "sample 3 -> " << smallestMatchingIndex({1, 2, 3}) << "\n";
}
