/**
 * Basic DSA - Percentage of Letter in String (LeetCode 2278)
 * Return floor(100 * occurrences(letter) / length).
 */
#include <iostream>
#include <string>

int percentageLetter(const std::string& s, char letter) {
    int c = 0;
    for (char ch : s) {
        if (ch == letter)
            ++c;
    }
    return (100 * c) / static_cast<int>(s.size());
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Percentage of Letter in String\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "\"foobar\", 'o' -> " << percentageLetter("foobar", 'o') << "\n";
    std::cout << "\"jjjj\", 'j' -> " << percentageLetter("jjjj", 'j') << "\n";
}
