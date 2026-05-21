/**
 * Basic DSA - Sum of Prefix Scores of Strings (LeetCode 2416)
 * Trie stores how many words pass each prefix; score of a word is the sum of counts along its path.
 */
#include <array>
#include <iostream>
#include <string>
#include <vector>

struct TrieNode {
    int count = 0;
    std::array<int, 26> next{};
    TrieNode() { next.fill(-1); }
};

std::vector<int> sumPrefixScores(const std::vector<std::string>& words) {
    std::vector<TrieNode> trie(1);
    auto insert = [&](const std::string& word) {
        int node = 0;
        ++trie[static_cast<size_t>(node)].count;
        for (char ch : word) {
            int idx = ch - 'a';
            if (trie[static_cast<size_t>(node)].next[static_cast<size_t>(idx)] == -1) {
                trie[static_cast<size_t>(node)].next[static_cast<size_t>(idx)] =
                    static_cast<int>(trie.size());
                trie.emplace_back();
            }
            node = trie[static_cast<size_t>(node)].next[static_cast<size_t>(idx)];
            ++trie[static_cast<size_t>(node)].count;
        }
    };

    for (const std::string& word : words)
        insert(word);

    std::vector<int> scores;
    scores.reserve(words.size());
    for (const std::string& word : words) {
        int node = 0;
        int total = 0;
        for (char ch : word) {
            node = trie[static_cast<size_t>(node)].next[static_cast<size_t>(ch - 'a')];
            total += trie[static_cast<size_t>(node)].count;
        }
        scores.push_back(total);
    }
    return scores;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i) std::cout << ",";
        std::cout << v[i];
    }
    std::cout << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sum of Prefix Scores of Strings\n";
    std::cout << std::string(60, '=') << "\n";

    printVec(sumPrefixScores({"abc", "ab", "bc", "b"}));
    printVec(sumPrefixScores({"abcd"}));
}
