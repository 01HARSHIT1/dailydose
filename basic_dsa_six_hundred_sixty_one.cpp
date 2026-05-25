/**
 * Basic DSA - Sum of Values at Indices With K Set Bits (LeetCode 2859)
 * Sum nums[i] where the popcount of index i equals k.
 */
#include <iostream>
#include <vector>

int popcount(int x) {
    int count = 0;
    while (x > 0) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

int sumIndicesWithKSetBits(const std::vector<int>& nums, int k) {
    int total = 0;
    for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
        if (popcount(i) == k)
            total += nums[static_cast<size_t>(i)];
    }
    return total;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sum of Values at Indices With K Set Bits\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << sumIndicesWithKSetBits({5, 10, 1, 5, 2}, 1) << "\n";
    std::cout << "sample 2 -> " << sumIndicesWithKSetBits({4, 3, 2, 1}, 2) << "\n";
}
