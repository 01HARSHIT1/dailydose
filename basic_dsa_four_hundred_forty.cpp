/**
 * Basic DSA - Determine if String Halves Are Alike (LeetCode 1704)
 * Even length; compare vowel counts in first vs second half (a,e,i,o,u, case-insensitive).
 */
#include <iostream>
#include <string>

static bool is_vowel(unsigned char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I'
        || c == 'O' || c == 'U';
}

bool halvesAreAlike(const std::string& s) {
    int n = static_cast<int>(s.size()) / 2;
    int a = 0;
    int b = 0;
    for (int i = 0; i < n; ++i) {
        if (is_vowel(s[static_cast<size_t>(i)]))
            ++a;
        if (is_vowel(s[static_cast<size_t>(n + i)]))
            ++b;
    }
    return a == b;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Determine if String Halves Are Alike\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "book -> " << (halvesAreAlike("book") ? "true" : "false") << "\n";
    std::cout << "textbook -> " << (halvesAreAlike("textbook") ? "true" : "false") << "\n";
}
