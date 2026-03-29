/**
 * Basic DSA - Check If a Word Occurs As a Prefix of Any Word in a Sentence (LeetCode 1455)
 * Words are space-separated; return 1-based index of first word starting with searchWord, or -1.
 */
#include <iostream>
#include <string>

int isPrefixOfWord(const std::string& sentence, const std::string& searchWord) {
    int word_idx = 1;
    size_t start = 0;
    const size_t n = sentence.size();
    const size_t m = searchWord.size();
    while (start < n) {
        while (start < n && sentence[start] == ' ')
            ++start;
        if (start >= n)
            break;
        size_t end = start;
        while (end < n && sentence[end] != ' ')
            ++end;
        if (end - start >= m) {
            bool ok = true;
            for (size_t k = 0; k < m; ++k) {
                if (sentence[start + k] != searchWord[k]) {
                    ok = false;
                    break;
                }
            }
            if (ok)
                return word_idx;
        }
        ++word_idx;
        start = end;
    }
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Check If a Word Occurs As a Prefix of Any Word in a Sentence\n";
    std::cout << std::string(60, '=') << "\n";

    std::string s1 = "i love eating burger";
    std::cout << "\"i love eating burger\", burg -> " << isPrefixOfWord(s1, "burg") << "\n";

    std::string s2 = "this problem is an easy problem";
    std::cout << "easy sentence, pro -> " << isPrefixOfWord(s2, "pro") << "\n";
}
