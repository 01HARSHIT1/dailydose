/**
 * Basic DSA - Report Spam Message (LeetCode 3295)
 * Count message words that appear in bannedWords; report spam if count >= threshold.
 */
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

bool reportSpam(const std::vector<std::string>& message, const std::vector<std::string>& bannedWords, int threshold) {
    std::unordered_set<std::string> banned(bannedWords.begin(), bannedWords.end());
    int count = 0;
    for (const std::string& word : message) {
        if (banned.count(word))
            ++count;
    }
    return count >= threshold;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Report Spam Message\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> "
              << reportSpam({"hello", "user", "twoTwo"}, {"hello", "world"}, 2) << "\n";
    std::cout << "sample 2 -> "
              << reportSpam({"howdy", "world", "world", "world"}, {"world", "howdy"}, 3) << "\n";
}
