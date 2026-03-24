/**
 * Basic DSA - Palindromic Substrings (LeetCode 647)
 * Count substrings that are palindromes (expand around center).
 */
#include <iostream>
#include <string>

int countSubstrings(std::string s) {
    int n = s.size(), ans = 0;
    for (int c = 0; c < 2 * n - 1; c++) {
        int lo = c / 2, hi = lo + c % 2;
        while (lo >= 0 && hi < n && s[lo] == s[hi]) {
            ans++;
            lo--;
            hi++;
        }
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Palindromic Substrings\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "abc -> " << countSubstrings("abc") << "\n";
    std::cout << "aaa -> " << countSubstrings("aaa") << "\n";
}
