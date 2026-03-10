/**
 * Basic DSA - Reverse Words in a String III (LeetCode 557)
 * Reverse the order of characters in each word within a sentence.
 */
#include <iostream>
#include <string>
#include <algorithm>

std::string reverseWords(std::string s) {
    int i = 0, n = s.size();
    while (i < n) {
        int j = i;
        while (j < n && s[j] != ' ') j++;
        std::reverse(s.begin() + i, s.begin() + j);
        i = j + 1;
    }
    return s;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Reverse Words in a String III\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "Let's take LeetCode contest -> " << reverseWords("Let's take LeetCode contest") << "\n";
    std::cout << "Mr Ding -> " << reverseWords("Mr Ding") << "\n";
}
