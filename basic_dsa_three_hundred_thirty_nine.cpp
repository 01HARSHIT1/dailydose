/**
 * Basic DSA - Backspace String Compare (LeetCode 844)
 * Return true if two strings are equal after # backspaces.
 */
#include <iostream>
#include <string>

std::string build(const std::string& s) {
    std::string t;
    for (char c : s) {
        if (c == '#') {
            if (!t.empty()) t.pop_back();
        } else t.push_back(c);
    }
    return t;
}

bool backspaceCompare(std::string s, std::string t) {
    return build(s) == build(t);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Backspace String Compare\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "ab#c, ad#c -> " << (backspaceCompare("ab#c", "ad#c") ? "true" : "false") << "\n";
    std::cout << "ab##, c#d# -> " << (backspaceCompare("ab##", "c#d#") ? "true" : "false") << "\n";
    std::cout << "a#c, b -> " << (backspaceCompare("a#c", "b") ? "true" : "false") << "\n";
}
