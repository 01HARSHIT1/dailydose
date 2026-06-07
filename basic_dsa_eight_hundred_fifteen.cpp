/**
 * Basic DSA - Find Maximum Number of Non Intersecting Substrings (LeetCode 3557)
 * Greedy scan: take earliest valid same-letter substring (length >= 4), then reset.
 */

#include <iostream>
#include <string>
#include <unordered_map>

int maxNonIntersectingSubstrings(const std::string& word) {
    int count = 0;
    std::unordered_map<char, int> firstIndex;

    for (int index = 0; index < static_cast<int>(word.size()); ++index) {
        const char letter = word[index];
        const auto found = firstIndex.find(letter);
        if (found == firstIndex.end()) {
            firstIndex[letter] = index;
        } else if (index - found->second + 1 >= 4) {
            ++count;
            firstIndex.clear();
        }
    }

    return count;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Maximum Number of Non Intersecting Substrings\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxNonIntersectingSubstrings("abcdeafdef") << "\n";
    std::cout << "sample 2 -> " << maxNonIntersectingSubstrings("bcdaaaab") << "\n";
}
