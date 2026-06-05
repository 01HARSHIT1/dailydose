/**
 * Basic DSA - Minimum Operations to Convert All Elements to Zero (LeetCode 3542)
 * Monotonic stack tracks distinct value layers separated by smaller numbers.
 */

#include <iostream>
#include <vector>

int minOperations(const std::vector<int>& values) {
    std::vector<int> increasingStack;
    int operationCount = 0;

    for (const int value : values) {
        while (!increasingStack.empty() && increasingStack.back() > value) {
            ++operationCount;
            increasingStack.pop_back();
        }

        if (value != 0 &&
            (increasingStack.empty() || increasingStack.back() != value)) {
            increasingStack.push_back(value);
        }
    }

    operationCount += static_cast<int>(increasingStack.size());
    return operationCount;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Operations to Convert All Elements to Zero\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minOperations({0, 2}) << "\n";
    std::cout << "sample 2 -> " << minOperations({3, 1, 2, 1}) << "\n";
    std::cout << "sample 3 -> " << minOperations({1, 2, 1, 2, 1, 2}) << "\n";
}
