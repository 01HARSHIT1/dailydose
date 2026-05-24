/**
 * Basic DSA - Furthest Point From Origin (LeetCode 2833)
 * Fixed L/R move that direction; each '_' can extend whichever side is larger, so answer = |L-R| + count('_').
 */
#include <cstdlib>
#include <iostream>
#include <string>

int furthestDistanceFromOrigin(const std::string& moves) {
    int left = 0;
    int right = 0;
    int blanks = 0;
    for (char ch : moves) {
        if (ch == 'L')
            ++left;
        else if (ch == 'R')
            ++right;
        else
            ++blanks;
    }
    return std::abs(left - right) + blanks;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Furthest Point From Origin\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << furthestDistanceFromOrigin("L_RL__R") << "\n";
    std::cout << "sample 2 -> " << furthestDistanceFromOrigin("_R__LL_") << "\n";
    std::cout << "sample 3 -> " << furthestDistanceFromOrigin("_______") << "\n";
}
