/**
 * Basic DSA - Repeated Substring Pattern (LeetCode 459)
 * Check if s can be formed by repeating a substring.
 */
#include <iostream>
#include <string>

bool repeatedSubstringPattern(std::string s) {
    int n = (int)s.size();
    for (int len = 1; len <= n / 2; len++) {
        if (n % len != 0) continue;
        bool ok = true;
        for (int i = len; i < n; i++) {
            if (s[i] != s[i % len]) { ok = false; break; }
        }
        if (ok) return true;
    }
    return false;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Repeated Substring Pattern\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "abab -> " << (repeatedSubstringPattern("abab") ? "true" : "false") << "\n";
    std::cout << "aba -> " << (repeatedSubstringPattern("aba") ? "true" : "false") << "\n";
    std::cout << "abcabcabcabc -> " << (repeatedSubstringPattern("abcabcabcabc") ? "true" : "false") << "\n";
}
