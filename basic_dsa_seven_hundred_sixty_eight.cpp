/**
 * Basic DSA - Longest Palindrome After Substring Concatenation I (LeetCode 3503)
 * Palindrome DP across s and reversed-t match, plus suffix/prefix extensions.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::vector<int> getPalindromeLengths(const std::string& text, bool fromStart) {
    const int size = static_cast<int>(text.size());
    std::vector<std::vector<bool>> isPalindrome(size, std::vector<bool>(size, false));
    std::vector<int> lengths(size, 0);

    for (int left = size - 1; left >= 0; --left) {
        for (int right = left; right < size; ++right) {
            if (text[left] == text[right] && (right - left < 2 || isPalindrome[left + 1][right - 1])) {
                isPalindrome[left][right] = true;
                const int index = fromStart ? left : right;
                lengths[index] = std::max(lengths[index], right - left + 1);
            }
        }
    }

    return lengths;
}

int longestPalindrome(const std::string& s, const std::string& t) {
    const int sSize = static_cast<int>(s.size());
    const int tSize = static_cast<int>(t.size());
    const std::vector<int> suffixLengths = getPalindromeLengths(s, true);
    const std::vector<int> prefixLengths = getPalindromeLengths(t, false);
    int answer = std::max(*std::max_element(suffixLengths.begin(), suffixLengths.end()),
                          *std::max_element(prefixLengths.begin(), prefixLengths.end()));
    std::vector<std::vector<int>> matchLength(sSize, std::vector<int>(tSize, 0));

    for (int sIndex = 0; sIndex < sSize; ++sIndex) {
        for (int tIndex = tSize - 1; tIndex >= 0; --tIndex) {
            if (s[sIndex] != t[tIndex])
                continue;

            matchLength[sIndex][tIndex] =
                2 + (sIndex > 0 && tIndex + 1 < tSize ? matchLength[sIndex - 1][tIndex + 1] : 0);
            const int extension = std::max(sIndex + 1 < sSize ? suffixLengths[sIndex + 1] : 0,
                                           tIndex > 0 ? prefixLengths[tIndex - 1] : 0);
            answer = std::max(answer, matchLength[sIndex][tIndex] + extension);
        }
    }

    return answer;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Longest Palindrome After Substring Concatenation I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << longestPalindrome("a", "a") << "\n";
    std::cout << "sample 2 -> " << longestPalindrome("abcde", "ecdba") << "\n";
}
