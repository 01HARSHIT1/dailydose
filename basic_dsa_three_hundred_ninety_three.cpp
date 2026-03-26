/**
 * Basic DSA - Reordered Power of 2 (LeetCode 869)
 * True if digits of n can be rearranged to form a power of two.
 */
#include <algorithm>
#include <iostream>
#include <string>

bool reorderedPowerOf2(int n) {
    std::string s = std::to_string(n);
    std::sort(s.begin(), s.end());
    for (int i = 0; i < 31; ++i) {
        std::string t = std::to_string(1 << i);
        std::sort(t.begin(), t.end());
        if (s == t)
            return true;
    }
    return false;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Reordered Power of 2\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "n=1 -> " << (reorderedPowerOf2(1) ? "true" : "false") << "\n";
    std::cout << "n=10 -> " << (reorderedPowerOf2(10) ? "true" : "false") << "\n";
    std::cout << "n=46 -> " << (reorderedPowerOf2(46) ? "true" : "false") << "\n";
}
