/**
 * Basic DSA - Reverse Degree of a String (LeetCode 3498)
 * Sum index times reverse-alphabet position for each character.
 */

#include <iostream>
#include <string>

int reverseDegree(const std::string& text) {
    int degree = 0;

    for (int index = 0; index < static_cast<int>(text.size()); ++index) {
        const int reverseAlphabetPosition = 26 - (text[index] - 'a');
        degree += reverseAlphabetPosition * (index + 1);
    }

    return degree;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Reverse Degree of a String\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << reverseDegree("abc") << "\n";
    std::cout << "sample 2 -> " << reverseDegree("zaza") << "\n";
}
