/**
 * Basic DSA - Maximum Nesting Depth of the Parentheses (LeetCode 1614)
 * VPS string of digits and +*; ignore them — only '(' and ')' change nesting.
 */
#include <algorithm>
#include <iostream>
#include <string>

int maxDepthParentheses(const std::string& s) {
    int cur = 0;
    int mx = 0;
    for (char c : s) {
        if (c == '(') {
            ++cur;
            mx = std::max(mx, cur);
        } else if (c == ')') {
            --cur;
        }
    }
    return mx;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Nesting Depth of the Parentheses\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "(1+(2*3)+((8)/4))+1 -> " << maxDepthParentheses("(1+(2*3)+((8)/4))+1") << "\n";
    std::cout << "(1) -> " << maxDepthParentheses("(1)") << "\n";
}
