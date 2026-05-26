/**
 * Basic DSA - Score of a String (LeetCode 3110)
 * Sum the absolute differences between ASCII values of adjacent characters.
 */
#include <cstdlib>
#include <iostream>
#include <string>

int scoreOfString(const std::string& s) {
    int score = 0;
    for (size_t i = 0; i + 1 < s.size(); ++i)
        score += std::abs(s[i] - s[i + 1]);
    return score;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Score of a String\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << scoreOfString("hello") << "\n";
    std::cout << "sample 2 -> " << scoreOfString("zaz") << "\n";
}
