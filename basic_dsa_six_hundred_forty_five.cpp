/**
 * Basic DSA - Minimum Additions to Make Valid String (LeetCode 2645)
 * Walk the word against the repeating "abc" pattern; count missing letters that must be inserted.
 */
#include <iostream>
#include <string>

int addMinimum(const std::string& word) {
    int additions = 0;
    char expected = 'a';
    for (char ch : word) {
        while (ch != expected) {
            ++additions;
            expected = (expected == 'c') ? 'a' : expected + 1;
        }
        expected = (expected == 'c') ? 'a' : expected + 1;
    }
    if (expected != 'a')
        additions += (expected == 'b') ? 2 : 1;
    return additions;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Additions to Make Valid String\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << addMinimum("b") << "\n";
    std::cout << "sample 2 -> " << addMinimum("aaa") << "\n";
    std::cout << "sample 3 -> " << addMinimum("abc") << "\n";
}
