/**
 * Basic DSA - Word Break (LeetCode 139)
 * Return true if s can be segmented into words from wordDict.
 */
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
    std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
    int n = s.size();
    std::vector<bool> dp(n + 1);
    dp[0] = true;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i && !dp[i]; j++)
            if (dp[j] && dict.count(s.substr(j, i - j))) dp[i] = true;
    return dp[n];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Word Break\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::string> d1 = {"leet", "code"};
    std::cout << "leetcode -> " << (wordBreak("leetcode", d1) ? "true" : "false") << "\n";

    std::vector<std::string> d2 = {"apple", "pen"};
    std::cout << "applepen -> " << (wordBreak("applepen", d2) ? "true" : "false") << "\n";

    std::vector<std::string> d3 = {"cats", "dog", "sand", "and", "cat"};
    std::cout << "catsandog -> " << (wordBreak("catsandog", d3) ? "true" : "false") << "\n";
}
