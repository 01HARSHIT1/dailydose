/**
 * Basic DSA - Implement strStr() (LeetCode 28)
 * Return index of first occurrence of needle in haystack, or -1 if not found.
 */
#include <iostream>
#include <string>

int strStr(std::string haystack, std::string needle) {
    if (needle.empty()) return 0;
    int n = haystack.size(), m = needle.size();
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        while (j < m && haystack[i + j] == needle[j]) j++;
        if (j == m) return i;
    }
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Implement strStr()\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sadbutsad, sad -> " << strStr("sadbutsad", "sad") << "\n";
    std::cout << "leetcode, leeto -> " << strStr("leetcode", "leeto") << "\n";
    std::cout << "hello, ll -> " << strStr("hello", "ll") << "\n";
}
