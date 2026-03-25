/**
 * Basic DSA - Binary Gap (LeetCode 868)
 * Longest distance between two consecutive 1 bits in binary representation of n.
 */
#include <algorithm>
#include <iostream>
#include <string>

int binaryGap(int n) {
    int best = 0;
    int last = -1;
    for (int i = 0; n > 0; ++i, n >>= 1) {
        if (n & 1) {
            if (last >= 0)
                best = std::max(best, i - last);
            last = i;
        }
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Binary Gap\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "n=22 (10110) -> " << binaryGap(22) << "\n";
    std::cout << "n=8 (1000) -> " << binaryGap(8) << "\n";
    std::cout << "n=5 (101) -> " << binaryGap(5) << "\n";
}
