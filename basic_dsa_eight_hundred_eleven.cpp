/**
 * Basic DSA - Minimum Swaps to Sort by Digit Sum (LeetCode 3551)
 * Sort by digit sum, then count permutation cycles for minimum swaps.
 */

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

int digitSum(int value) {
    int sum = 0;
    while (value > 0) {
        sum += value % 10;
        value /= 10;
    }
    return sum;
}

bool sortByDigitSumThenValue(int left, int right) {
    const int leftSum = digitSum(left);
    const int rightSum = digitSum(right);
    if (leftSum != rightSum)
        return leftSum < rightSum;
    return left < right;
}

int minimumSwapsToSortByDigitSum(std::vector<int> values) {
    const int count = static_cast<int>(values.size());
    std::vector<int> sortedValues = values;
    std::sort(sortedValues.begin(), sortedValues.end(), sortByDigitSumThenValue);

    std::unordered_map<int, int> targetIndexByValue;
    for (int index = 0; index < count; ++index)
        targetIndexByValue[sortedValues[index]] = index;

    std::vector<int> permutation(count);
    for (int index = 0; index < count; ++index)
        permutation[index] = targetIndexByValue[values[index]];

    std::vector<bool> visited(count, false);
    int cycleCount = 0;

    for (int index = 0; index < count; ++index) {
        if (visited[index])
            continue;

        ++cycleCount;
        int current = index;
        while (!visited[current]) {
            visited[current] = true;
            current = permutation[current];
        }
    }

    return count - cycleCount;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Swaps to Sort by Digit Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minimumSwapsToSortByDigitSum({37, 100}) << "\n";
    std::cout << "sample 2 -> "
              << minimumSwapsToSortByDigitSum({22, 14, 33, 7}) << "\n";
    std::cout << "sample 3 -> "
              << minimumSwapsToSortByDigitSum({18, 43, 34, 16}) << "\n";
}
