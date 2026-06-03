/**
 * Basic DSA - Smallest Palindromic Rearrangement I (LeetCode 3517)
 * Build lexicographically smallest half, optional middle char, then mirror.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string smallestPalindrome(const std::string& text) {
    std::vector<int> counts(26, 0);

    for (const char character : text)
        ++counts[character - 'a'];

    std::string firstHalf;
    char middleCharacter = '\0';

    for (char character = 'a'; character <= 'z'; ++character) {
        const int index = character - 'a';
        const int halfCount = counts[index] / 2;

        firstHalf.append(halfCount, character);
        counts[index] -= halfCount * 2;

        if (counts[index] == 1)
            middleCharacter = character;
    }

    std::string answer = firstHalf;

    if (middleCharacter != '\0')
        answer.push_back(middleCharacter);

    std::string reversedHalf = firstHalf;
    std::reverse(reversedHalf.begin(), reversedHalf.end());
    answer += reversedHalf;
    return answer;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Smallest Palindromic Rearrangement I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << smallestPalindrome("babab") << "\n";
    std::cout << "sample 2 -> " << smallestPalindrome("daccad") << "\n";
}
