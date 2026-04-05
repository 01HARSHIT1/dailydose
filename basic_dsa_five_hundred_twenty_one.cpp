/**
 * Basic DSA - Valid Palindrome (LeetCode 125)
 * After keeping only letters and digits and ignoring case, read the same forwards and backwards.
 * Time: O(n), Space: O(1).
 */
#include <cctype>
#include <iostream>
#include <string>

bool isPalindrome(const std::string& s) {
    int i = 0;
    int j = static_cast<int>(s.size()) - 1;
    while (i < j) {
        while (i < j && !std::isalnum(static_cast<unsigned char>(s[i])))
            ++i;
        while (i < j && !std::isalnum(static_cast<unsigned char>(s[j])))
            --j;
        if (std::tolower(static_cast<unsigned char>(s[i])) !=
            std::tolower(static_cast<unsigned char>(s[j])))
            return false;
        ++i;
        --j;
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Valid Palindrome\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "\"A man, a plan, a canal: Panama\" -> "
              << (isPalindrome("A man, a plan, a canal: Panama") ? "true" : "false") << "\n";
    std::cout << "\"race a car\" -> " << (isPalindrome("race a car") ? "true" : "false") << "\n";
    std::cout << "\" \" -> " << (isPalindrome(" ") ? "true" : "false") << "\n";
}
