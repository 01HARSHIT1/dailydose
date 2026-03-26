/**
 * Basic DSA - Reverse Only Letters (LeetCode 917)
 * Reverse letter order; non-letters stay in place.
 */
#include <cctype>
#include <iostream>
#include <string>

std::string reverseOnlyLetters(std::string s) {
    int i = 0;
    int j = static_cast<int>(s.size()) - 1;
    while (i < j) {
        while (i < j && !std::isalpha(static_cast<unsigned char>(s[i])))
            ++i;
        while (i < j && !std::isalpha(static_cast<unsigned char>(s[j])))
            --j;
        if (i < j)
            std::swap(s[i++], s[j--]);
    }
    return s;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Reverse Only Letters\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "ab-cd -> " << reverseOnlyLetters("ab-cd") << "\n";
    std::cout << "a-bC-dEf-gh!! -> " << reverseOnlyLetters("a-bC-dEf-gh!!") << "\n";
}
