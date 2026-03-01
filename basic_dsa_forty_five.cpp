/**
 * Basic DSA - Backspace String Compare (LeetCode 844)
 * Compare two strings after applying backspace (#) processing.
 */
#include <iostream>
#include <string>

std::string build(std::string s) {
    std::string out;
    for (char c : s) {
        if (c == '#') {
            if (!out.empty()) out.pop_back();
        } else out += c;
    }
    return out;
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
