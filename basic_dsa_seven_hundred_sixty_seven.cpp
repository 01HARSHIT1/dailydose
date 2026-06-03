/**
 * Basic DSA - Minimum Pair Removal to Sort Array I (LeetCode 3507)
 * Repeatedly merge the leftmost adjacent pair with minimum sum until sorted.
 */

#include <iostream>
#include <vector>

bool isNonDecreasing(const std::vector<int>& values) {
    for (int index = 1; index < static_cast<int>(values.size()); ++index) {
        if (values[index] < values[index - 1])
            return false;
    }
    return true;
}

int minimumPairRemoval(std::vector<int> values) {
    int operations = 0;

    while (!isNonDecreasing(values)) {
        int leftIndex = 0;
        int minimumSum = values[0] + values[1];

        for (int index = 1; index + 1 < static_cast<int>(values.size()); ++index) {
            const int pairSum = values[index] + values[index + 1];
            if (pairSum < minimumSum) {
                minimumSum = pairSum;
                leftIndex = index;
            }
        }

        values[leftIndex] = minimumSum;
        values.erase(values.begin() + leftIndex + 1);
        ++operations;
    }

    return operations;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Pair Removal to Sort Array I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minimumPairRemoval({5, 2, 3, 1}) << "\n";
    std::cout << "sample 2 -> " << minimumPairRemoval({1, 2, 2}) << "\n";
}
