/**
 * Basic DSA - Check if the Sentence Is Pangram (LeetCode 1832)
 * A pangram uses every letter of the English alphabet at least once
 * (input uses lowercase English letters and spaces).
 */
#include <iostream>
#include <string>

bool checkIfPangram(const std::string& sentence) {
    int mask = 0;
    for (char ch : sentence) {
        if (ch >= 'a' && ch <= 'z')
            mask |= 1 << (ch - 'a');
    }
    return mask == (1 << 26) - 1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Check if Sentence Is Pangram\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "quick brown fox... -> "
              << checkIfPangram("thequickbrownfoxjumpsoverthelazydog") << "\n";
    std::cout << "leetcode -> " << checkIfPangram("leetcode") << "\n";
}
