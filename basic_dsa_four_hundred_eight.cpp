/**
 * Basic DSA - Remove Outermost Parentheses (LeetCode 1021)
 * A primitive decomposition is a balanced substring that cannot be split further; drop its outer ( ).
 */
#include <iostream>
#include <string>

std::string removeOuterParentheses(const std::string& s) {
    std::string ans;
    int bal = 0;
    for (char c : s) {
        if (c == '(') {
            if (bal > 0)
                ans += c;
            ++bal;
        } else {
            --bal;
            if (bal > 0)
                ans += c;
        }
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Remove Outermost Parentheses\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "(()())(()) -> " << removeOuterParentheses("(()())(())") << "\n";
    std::cout << "() -> " << removeOuterParentheses("()") << "\n";
}
