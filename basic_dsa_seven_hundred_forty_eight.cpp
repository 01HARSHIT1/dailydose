/**
 * Basic DSA - Maximize Subarrays After Removing One Conflicting Pair (LeetCode 3480)
 * Count valid subarrays after removing one conflicting pair for maximum count.
 */

#include <algorithm>
#include <iostream>
#include <vector>

long long maxSubarrays(int n, std::vector<std::vector<int>> conflictingPairs) {
    long long validSubarrays = 0;
    int maxLeft = 0;
    int secondMaxLeft = 0;
    std::vector<long long> gains(n + 1, 0);
    std::vector<std::vector<int>> conflicts(n + 1);

    for (const auto& pair : conflictingPairs) {
        const int a = pair[0];
        const int b = pair[1];
        conflicts[std::max(a, b)].push_back(std::min(a, b));
    }

    for (int right = 1; right <= n; ++right) {
        for (int left : conflicts[right]) {
            if (left > maxLeft) {
                secondMaxLeft = maxLeft;
                maxLeft = left;
            } else if (left > secondMaxLeft) {
                secondMaxLeft = left;
            }
        }

        validSubarrays += right - maxLeft;
        gains[maxLeft] += maxLeft - secondMaxLeft;
    }

    return validSubarrays + *std::max_element(gains.begin(), gains.end());
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximize Subarrays After Removing One Conflicting Pair\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxSubarrays(4, {{2, 3}, {1, 4}}) << "\n";
    std::cout << "sample 2 -> " << maxSubarrays(5, {{1, 2}, {2, 5}, {3, 5}}) << "\n";
}
