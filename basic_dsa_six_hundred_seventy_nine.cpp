/**
 * Basic DSA - Find if Digit Game Can Be Won (LeetCode 3232)
 * Alice wins if the single-digit sum differs from the double-digit sum (she picks the larger group).
 */
#include <iostream>
#include <vector>

bool canAliceWin(const std::vector<int>& nums) {
    int single = 0;
    int doubleDigit = 0;
    for (int v : nums) {
        if (v < 10)
            single += v;
        else
            doubleDigit += v;
    }
    return single != doubleDigit;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find if Digit Game Can Be Won\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> " << canAliceWin({1, 2, 3, 4, 10}) << "\n";
    std::cout << "sample 2 -> " << canAliceWin({1, 2, 3, 4, 5, 14}) << "\n";
    std::cout << "sample 3 -> " << canAliceWin({5, 5, 5, 25}) << "\n";
}
