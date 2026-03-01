/**
 * Basic DSA - Reverse Vowels of a String (LeetCode 345)
 * Reverse only the vowels in a string.
 */
#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>

bool isVowel(char c) {
    static const std::unordered_set<char> v = {'a','e','i','o','u','A','E','I','O','U'};
    return v.count(c);
}

std::string reverseVowels(std::string s) {
    int i = 0, j = (int)s.size() - 1;
    while (i < j) {
        while (i < j && !isVowel(s[i])) i++;
        while (i < j && !isVowel(s[j])) j--;
        if (i < j) std::swap(s[i++], s[j--]);
    }
    return s;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Reverse Vowels of a String\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "hello -> " << reverseVowels("hello") << "\n";
    std::cout << "leetcode -> " << reverseVowels("leetcode") << "\n";
    std::cout << "aA -> " << reverseVowels("aA") << "\n";
}
