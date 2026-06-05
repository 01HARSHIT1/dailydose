/**
 * Basic DSA - Find Most Frequent Vowel and Consonant (LeetCode 3541)
 * Count letter frequencies; return max vowel frequency plus max consonant frequency.
 */

#include <algorithm>
#include <iostream>
#include <string>

bool isVowel(char character) {
    return character == 'a' || character == 'e' || character == 'i' ||
           character == 'o' || character == 'u';
}

int maxFreqSum(const std::string& text) {
    int counts[26] = {};

    for (const char character : text)
        ++counts[character - 'a'];

    int maxVowelFrequency = 0;
    int maxConsonantFrequency = 0;

    for (int index = 0; index < 26; ++index) {
        const char character = static_cast<char>('a' + index);
        if (isVowel(character))
            maxVowelFrequency = std::max(maxVowelFrequency, counts[index]);
        else
            maxConsonantFrequency = std::max(maxConsonantFrequency, counts[index]);
    }

    return maxVowelFrequency + maxConsonantFrequency;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Most Frequent Vowel and Consonant\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxFreqSum("successes") << "\n";
    std::cout << "sample 2 -> " << maxFreqSum("aeiaeia") << "\n";
}
