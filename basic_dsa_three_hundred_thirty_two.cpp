/**
 * Basic DSA - Word Pattern (LeetCode 290)
 * Return true if pattern letters map one-to-one to words in s.
 */
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

bool wordPattern(std::string pattern, std::string s) {
    std::istringstream iss(s);
    std::vector<std::string> words;
    std::string w;
    while (iss >> w) words.push_back(w);
    if (pattern.size() != words.size()) return false;
    std::unordered_map<char, std::string> a2b;
    std::unordered_set<std::string> used;
    for (size_t i = 0; i < pattern.size(); i++) {
        char c = pattern[i];
        const std::string& wd = words[i];
        if (a2b.count(c)) {
            if (a2b[c] != wd) return false;
        } else {
            if (used.count(wd)) return false;
            a2b[c] = wd;
            used.insert(wd);
        }
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Word Pattern\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "abba / dog cat cat dog -> "
              << (wordPattern("abba", "dog cat cat dog") ? "true" : "false") << "\n";
    std::cout << "abba / dog dog dog dog -> "
              << (wordPattern("abba", "dog dog dog dog") ? "true" : "false") << "\n";
}
