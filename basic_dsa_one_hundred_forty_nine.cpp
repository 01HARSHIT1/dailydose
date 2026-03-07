/**
 * Basic DSA - Generate Parentheses (LeetCode 22)
 * All valid combinations of n pairs of parentheses.
 */
#include <iostream>
#include <vector>
#include <string>

void backtrack(std::vector<std::string>& ans, std::string cur, int open, int close, int n) {
    if ((int)cur.size() == 2 * n) { ans.push_back(cur); return; }
    if (open < n) backtrack(ans, cur + '(', open + 1, close, n);
    if (close < open) backtrack(ans, cur + ')', open, close + 1, n);
}

std::vector<std::string> generateParenthesis(int n) {
    std::vector<std::string> ans;
    backtrack(ans, "", 0, 0, n);
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Generate Parentheses\n";
    std::cout << std::string(60, '=') << "\n";

    auto r1 = generateParenthesis(3);
    std::cout << "n=3 -> ";
    for (size_t i = 0; i < r1.size(); i++) std::cout << (i ? "," : "") << r1[i];
    std::cout << "\n";

    auto r2 = generateParenthesis(1);
    std::cout << "n=1 -> " << r2[0] << "\n";
}
