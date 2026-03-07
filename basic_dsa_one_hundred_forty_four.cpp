/**
 * Basic DSA - Word Break (LeetCode 139)
 * Check if string can be segmented into dictionary words.
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    std::vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            if (dp[j] && dict.count(s.substr(j, i - j))) {
                dp[i] = true;
                break;
            }
    return dp[n];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Word Break\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::string> d1 = {"leet", "code"};
    std::cout << "\"leetcode\", [leet,code] -> " << (wordBreak("leetcode", d1) ? "true" : "false") << "\n";

    std::vector<std::string> d2 = {"apple", "pen"};
    std::cout << "\"applepenapple\", [apple,pen] -> " << (wordBreak("applepenapple", d2) ? "true" : "false") << "\n";

    std::vector<std::string> d3 = {"cats", "dog", "sand", "and", "cat"};
    std::cout << "\"catsandog\", [cats,dog,sand,and,cat] -> " << (wordBreak("catsandog", d3) ? "true" : "false") << "\n";
}
