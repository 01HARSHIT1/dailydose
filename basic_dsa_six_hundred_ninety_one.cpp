/**
 * Basic DSA - Construct the Minimum Bitwise Array I (LeetCode 3314)
 * For odd q, find minimum x with x | (x + 1) = q; even q has no solution.
 */
#include <iostream>
#include <vector>

std::vector<int> minBitwiseArray(const std::vector<int>& queries) {
    std::vector<int> result;
    for (int q : queries) {
        if (q % 2 == 0) {
            result.push_back(-1);
            continue;
        }
        int lowbit = (q + 1) & -(q + 1);
        if (lowbit == q + 1)
            result.push_back(q / 2);
        else
            result.push_back(q - lowbit / 2);
    }
    return result;
}

void printArray(const std::vector<int>& nums) {
    std::cout << "[";
    for (size_t i = 0; i < nums.size(); ++i) {
        if (i)
            std::cout << ", ";
        std::cout << nums[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Construct the Minimum Bitwise Array I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> ";
    printArray(minBitwiseArray({2, 3, 7, 11}));
    std::cout << "\n";

    std::cout << "sample 2 -> ";
    printArray(minBitwiseArray({17, 21}));
    std::cout << "\n";
}
