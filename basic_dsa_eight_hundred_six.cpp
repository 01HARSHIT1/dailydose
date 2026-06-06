/**
 * Basic DSA - Smallest Palindromic Rearrangement II (LeetCode 3518)
 * Combinatorial counting to build the k-th lexicographic palindrome.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

static constexpr int kMaxPermutations = 1'000'001;

long long binomialCoefficient(int total, int choose) {
    if (choose < 0 || choose > total)
        return 0;

    long long result = 1;
    const int iterations = std::min(choose, total - choose);

    for (int index = 1; index <= iterations; ++index) {
        result = result * (total - index + 1) / index;
        if (result >= kMaxPermutations)
            return kMaxPermutations;
    }

    return result;
}

long long countArrangements(const std::vector<int>& halfCounts) {
    int remaining = 0;
    for (const int count : halfCounts)
        remaining += count;

    long long arrangements = 1;
    for (const int count : halfCounts) {
        arrangements *= binomialCoefficient(remaining, count);
        if (arrangements >= kMaxPermutations)
            return kMaxPermutations;
        remaining -= count;
    }

    return arrangements;
}

std::string smallestPalindromeByIndex(const std::string& text, int index) {
    std::vector<int> counts(26, 0);
    for (const char character : text)
        ++counts[character - 'a'];

    int oddCount = 0;
    for (const int count : counts) {
        if (count % 2 == 1)
            ++oddCount;
    }

    if (oddCount > 1)
        return "";

    std::vector<int> halfCounts(26, 0);
    char middleCharacter = '\0';

    for (int letter = 0; letter < 26; ++letter) {
        halfCounts[letter] = counts[letter] / 2;
        if (counts[letter] % 2 == 1)
            middleCharacter = static_cast<char>('a' + letter);
    }

    if (index > countArrangements(halfCounts))
        return "";

    std::string leftHalf;

    for (int built = 0; built < static_cast<int>(text.size() / 2); ++built) {
        for (int letter = 0; letter < 26; ++letter) {
            if (halfCounts[letter] == 0)
                continue;

            --halfCounts[letter];
            const long long arrangements = countArrangements(halfCounts);

            if (arrangements >= index) {
                leftHalf.push_back(static_cast<char>('a' + letter));
                break;
            }

            index -= static_cast<int>(arrangements);
            ++halfCounts[letter];
        }
    }

    std::string answer = leftHalf;
    if (middleCharacter != '\0')
        answer.push_back(middleCharacter);

    std::string reversedHalf = leftHalf;
    std::reverse(reversedHalf.begin(), reversedHalf.end());
    answer += reversedHalf;
    return answer;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Smallest Palindromic Rearrangement II\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << smallestPalindromeByIndex("abba", 2) << "\n";
    std::cout << "sample 2 -> " << smallestPalindromeByIndex("aa", 2) << "\n";
    std::cout << "sample 3 -> " << smallestPalindromeByIndex("bacab", 1) << "\n";
}
