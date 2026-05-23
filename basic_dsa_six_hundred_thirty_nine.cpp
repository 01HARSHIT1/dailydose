/**
 * Basic DSA - Find the Longest Balanced Substring of a Binary String (LeetCode 2609)
 * Scan runs of 0s followed by 1s; a balanced block contributes 2*min(zeros, ones).
 */
#include <algorithm>
#include <iostream>
#include <string>

int findTheLongestBalancedSubstring(const std::string& s) {
    int best = 0;
    int zeros = 0;
    int ones = 0;
    for (size_t i = 0; i < s.size(); ++i) {
        if (s[i] == '0') {
            if (i > 0 && s[i - 1] == '1') {
                zeros = 0;
                ones = 0;
            }
            ++zeros;
        } else {
            ++ones;
            best = std::max(best, 2 * std::min(zeros, ones));
        }
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Longest Balanced Substring of a Binary String\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << findTheLongestBalancedSubstring("01000111") << "\n";
    std::cout << "sample 2 -> " << findTheLongestBalancedSubstring("00111") << "\n";
    std::cout << "sample 3 -> " << findTheLongestBalancedSubstring("111") << "\n";
}
