/**
 * Basic DSA - Is Subsequence (LeetCode 392)
 * Check if s is a subsequence of t.
 */
#include <iostream>
#include <string>

bool isSubsequence(std::string s, std::string t) {
    int i = 0;
    for (char c : t) {
        if (i < (int)s.size() && s[i] == c) i++;
    }
    return i == (int)s.size();
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Is Subsequence\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "abc, ahbgdc -> " << (isSubsequence("abc", "ahbgdc") ? "true" : "false") << "\n";
    std::cout << "axc, ahbgdc -> " << (isSubsequence("axc", "ahbgdc") ? "true" : "false") << "\n";
    std::cout << "\"\", ahbgdc -> " << (isSubsequence("", "ahbgdc") ? "true" : "false") << "\n";
}
