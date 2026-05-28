/**
 * Basic DSA - Find the Lexicographically Largest String From the Box I (LeetCode 3403)
 * The answer is the best substring of length at most n - numFriends + 1 from any start.
 */
#include <algorithm>
#include <iostream>
#include <string>

std::string answerString(const std::string& word, int numFriends) {
    if (numFriends == 1)
        return word;

    std::string best;
    int n = static_cast<int>(word.size());
    int maxLen = n - numFriends + 1;
    for (int i = 0; i < n; ++i) {
        int len = std::min(maxLen, n - i);
        best = std::max(best, word.substr(static_cast<size_t>(i), static_cast<size_t>(len)));
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Lexicographically Largest String From the Box I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << answerString("dbca", 2) << "\n";
    std::cout << "sample 2 -> " << answerString("gggg", 4) << "\n";
    std::cout << "sample 3 -> " << answerString("gh", 1) << "\n";
}
