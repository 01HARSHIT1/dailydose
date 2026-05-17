/**
 * Basic DSA - Split Array Largest Sum (LeetCode 410)
 * Partition nums into m contiguous parts; minimize the largest part sum. Binary search answer; greedy count parts for a cap.
 */
#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

bool canSplit(const std::vector<int>& nums, int m, long long cap) {
    int parts = 1;
    long long sum = 0;
    for (int x : nums) {
        if (sum + x > cap) {
            ++parts;
            sum = x;
            if (parts > m)
                return false;
        } else
            sum += x;
    }
    return true;
}

int splitArray(const std::vector<int>& nums, int m) {
    long long lo = *std::max_element(nums.begin(), nums.end());
    long long hi = std::accumulate(nums.begin(), nums.end(), 0LL);
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (canSplit(nums, m, mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    return static_cast<int>(lo);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Split Array Largest Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[7,2,5,10,8] m=2 -> " << splitArray({7, 2, 5, 10, 8}, 2) << "\n";
    std::cout << "[1,2,3,4,5] m=2  -> " << splitArray({1, 2, 3, 4, 5}, 2) << "\n";
}
