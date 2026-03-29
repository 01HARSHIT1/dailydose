/**
 * Basic DSA - Sum of All Odd Length Subarrays (LeetCode 1588)
 * Sum every contiguous subarray whose length is odd.
 */
#include <iostream>
#include <string>
#include <vector>

int sumOddLengthSubarrays(const std::vector<int>& arr) {
    int n = static_cast<int>(arr.size());
    int total = 0;
    for (int len = 1; len <= n; len += 2) {
        for (int i = 0; i + len <= n; ++i) {
            for (int j = i; j < i + len; ++j)
                total += arr[j];
        }
    }
    return total;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sum of All Odd Length Subarrays\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 4, 2, 5, 3};
    std::cout << "[1,4,2,5,3] -> " << sumOddLengthSubarrays(v1) << "\n";

    std::vector<int> v2 = {1, 2};
    std::cout << "[1,2] -> " << sumOddLengthSubarrays(v2) << "\n";
}
