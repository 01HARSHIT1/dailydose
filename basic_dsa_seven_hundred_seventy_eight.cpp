/**
 * Basic DSA - Make Array Non-decreasing (LeetCode 3523)
 * Greedy scan: keep an element only if it extends the non-decreasing tail.
 */

#include <iostream>
#include <vector>

int maximumPossibleSize(const std::vector<int>& values) {
    int keptCount = 0;
    int tailMaximum = 0;

    for (const int value : values) {
        if (tailMaximum <= value) {
            ++keptCount;
            tailMaximum = value;
        }
    }

    return keptCount;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Make Array Non-decreasing\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maximumPossibleSize({4, 2, 5, 3, 5}) << "\n";
    std::cout << "sample 2 -> " << maximumPossibleSize({1, 2, 3}) << "\n";
}
