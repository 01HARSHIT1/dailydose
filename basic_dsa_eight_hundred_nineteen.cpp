/**
 * Basic DSA - Resulting String After Adjacent Removals (LeetCode 3561)
 * Stack simulation; pop when top and current are alphabet neighbors (incl. a-z wrap).
 */

#include <cstdlib>
#include <iostream>
#include <string>

bool areAlphabetNeighbors(char first, char second) {
    const int difference = std::abs(first - second);
    return difference == 1 || difference == 25;
}

std::string resultingStringAfterRemovals(const std::string& input) {
    std::string stackCharacters;

    for (const char letter : input) {
        if (!stackCharacters.empty() &&
            areAlphabetNeighbors(stackCharacters.back(), letter)) {
            stackCharacters.pop_back();
        } else {
            stackCharacters.push_back(letter);
        }
    }

    return stackCharacters;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Resulting String After Adjacent Removals\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> \"" << resultingStringAfterRemovals("abc") << "\"\n";
    std::cout << "sample 2 -> \"" << resultingStringAfterRemovals("adcb") << "\"\n";
    std::cout << "sample 3 -> \"" << resultingStringAfterRemovals("zadb") << "\"\n";
}
