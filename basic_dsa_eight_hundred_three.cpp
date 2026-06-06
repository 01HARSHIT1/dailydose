/**
 * Basic DSA - Minimum Pair Removal to Sort Array II (LeetCode 3510)
 * Repeatedly merge the leftmost adjacent pair with minimum sum.
 */

#include <climits>
#include <iostream>
#include <vector>

bool isNonDecreasing(const std::vector<int>& values) {
    for (int index = 0; index + 1 < static_cast<int>(values.size()); ++index) {
        if (values[index] > values[index + 1])
            return false;
    }
    return true;
}

int minimumPairRemoval(std::vector<int> values) {
    int operationCount = 0;

    while (!isNonDecreasing(values)) {
        int minimumSum = INT_MAX;
        int pairIndex = -1;

        for (int index = 0; index + 1 < static_cast<int>(values.size()); ++index) {
            const int pairSum = values[index] + values[index + 1];
            if (pairSum < minimumSum) {
                minimumSum = pairSum;
                pairIndex = index;
            }
        }

        values[pairIndex] = minimumSum;
        values.erase(values.begin() + pairIndex + 1);
        ++operationCount;
    }

    return operationCount;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Pair Removal to Sort Array II\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minimumPairRemoval({5, 2, 3, 1}) << "\n";
    std::cout << "sample 2 -> " << minimumPairRemoval({1, 2, 2}) << "\n";
}
