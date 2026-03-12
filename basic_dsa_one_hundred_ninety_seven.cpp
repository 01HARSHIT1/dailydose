/**
 * Basic DSA - Repeated Substring Pattern (LeetCode 459)
 * Check if s can be formed by repeating a substring.
 */
#include <iostream>
#include <string>

bool repeatedSubstringPattern(std::string s) {
    int n = s.size();
    for (int len = 1; len <= n / 2; len++) {
        if (n % len != 0) continue;
        std::string sub = s.substr(0, len);
        bool ok = true;
        for (int i = len; i < n && ok; i += len)
            if (s.substr(i, len) != sub) ok = false;
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
