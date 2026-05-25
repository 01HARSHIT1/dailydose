/**
 * Basic DSA - Find the Maximum Achievable Number (LeetCode 2769)
 * Each operation can raise num by 2 per step (increment num, decrement target), so answer = num + 2*t.
 */
#include <iostream>

int theMaximumAchievableX(int num, int t) {
    return num + 2 * t;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Maximum Achievable Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << theMaximumAchievableX(4, 1) << "\n";
    std::cout << "sample 2 -> " << theMaximumAchievableX(3, 2) << "\n";
}
