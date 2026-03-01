/**
 * Basic DSA - Valid Palindrome II (LeetCode 680)
 * Check if string is palindrome after removing at most one character.
 */
#include <iostream>
#include <string>

bool valid(std::string& s, int i, int j) {
    while (i < j) {
        if (s[i] != s[j]) return false;
        i++;
        j--;
    }
    return true;
}

bool validPalindrome(std::string s) {
    int i = 0, j = (int)s.size() - 1;
    while (i < j) {
        if (s[i] != s[j])
            return valid(s, i + 1, j) || valid(s, i, j - 1);
        i++;
        j--;
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Valid Palindrome II\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "aba -> " << (validPalindrome("aba") ? "true" : "false") << "\n";
    std::cout << "abca -> " << (validPalindrome("abca") ? "true" : "false") << "\n";
    std::cout << "abc -> " << (validPalindrome("abc") ? "true" : "false") << "\n";
}
