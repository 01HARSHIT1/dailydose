/**
 * Basic DSA - Find the Original Typed String I (LeetCode 3330)
 * Each run of equal letters may come from a long press; answer is the product of run lengths.
 */
#include <iostream>
#include <string>

int possibleStringCount(const std::string& word) {
    long long ways = 1;
    for (size_t i = 0; i < word.size();) {
        size_t j = i + 1;
        while (j < word.size() && word[j] == word[i])
            ++j;
        ways *= static_cast<long long>(j - i);
        i = j;
    }
    return static_cast<int>(ways);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Original Typed String I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << possibleStringCount("abbcccc") << "\n";
    std::cout << "sample 2 -> " << possibleStringCount("abcd") << "\n";
    std::cout << "sample 3 -> " << possibleStringCount("aaaa") << "\n";
}
