/**
 * Basic DSA - Valid Palindrome (LeetCode 125)
 * Alphanumeric chars only matter; ignore case and non-alphanumeric.
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

    std::cout << std::boolalpha;
    std::cout << "\"A man, a plan, a canal: Panama\" -> "
              << isPalindrome("A man, a plan, a canal: Panama") << "\n";
    std::cout << "\"race a car\" -> " << isPalindrome("race a car") << "\n";
    std::cout << "\" \" -> " << isPalindrome(" ") << "\n";
}
