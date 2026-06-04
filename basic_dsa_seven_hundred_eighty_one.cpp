/**
 * Basic DSA - Minimum Threshold for Inversion Pairs Count (LeetCode 3520)
 * Binary search on threshold; count qualifying inversion pairs with sorted insertion.
 */

#include <algorithm>
#include <iostream>
#include <vector>

bool hasEnoughInversionPairs(const std::vector<int>& values, int requiredCount,
                             int threshold) {
    int inversionCount = 0;
    std::vector<int> processedValues;

    for (const int value : values) {
        const auto lower =
            std::upper_bound(processedValues.begin(), processedValues.end(), value);
        const auto upper = std::upper_bound(processedValues.begin(),
                                            processedValues.end(), value + threshold);
        inversionCount += static_cast<int>(upper - lower);
        processedValues.insert(lower, value);

        if (inversionCount >= requiredCount)
            return true;
    }

    return inversionCount >= requiredCount;
}

int minThreshold(const std::vector<int>& values, int requiredCount) {
    const int maximumValue =
        *std::max_element(values.begin(), values.end());
    int left = 0;
    int right = maximumValue + 1;

    while (left < right) {
        const int middle = left + (right - left) / 2;
        if (hasEnoughInversionPairs(values, requiredCount, middle))
            right = middle;
        else
            left = middle + 1;
    }

    return left > maximumValue ? -1 : left;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Threshold for Inversion Pairs Count\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minThreshold({1, 2, 3, 4, 3, 2, 1}, 7) << "\n";
    std::cout << "sample 2 -> " << minThreshold({10, 9, 9, 9, 1}, 4) << "\n";
}
