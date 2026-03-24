/**
 * Basic DSA - Longest Palindromic Substring (LeetCode 5)
 * Return any longest palindromic substring of s.
 */
#include <iostream>
#include <string>

std::string longestPalindrome(std::string s) {
    int n = s.size(), start = 0, len = 0;
    auto expand = [&](int lo, int hi) {
        while (lo >= 0 && hi < n && s[lo] == s[hi]) {
            if (hi - lo + 1 > len) {
                len = hi - lo + 1;
                start = lo;
            }
            lo--;
            hi++;
        }
    };
    for (int i = 0; i < n; i++) {
        expand(i, i);
        expand(i, i + 1);
    }
    return s.substr(start, len);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Longest Palindromic Substring\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "babad -> " << longestPalindrome("babad") << "\n";
    std::cout << "cbbd -> " << longestPalindrome("cbbd") << "\n";
}
