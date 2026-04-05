/**
 * Basic DSA - Valid Parentheses (LeetCode 20)
 * Return true if every opening bracket has a matching closing bracket in correct order.
 * Time: O(n), Space: O(n) for the stack.
 */
#include <iostream>
#include <stack>
#include <string>

bool isValid(const std::string& s) {
    std::stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (st.empty())
                return false;
            char o = st.top();
            st.pop();
            if (c == ')' && o != '(')
                return false;
            if (c == ']' && o != '[')
                return false;
            if (c == '}' && o != '{')
                return false;
        }
    }
    return st.empty();
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Valid Parentheses\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "\"()\" -> " << (isValid("()") ? "true" : "false") << "\n";
    std::cout << "\"()[]{}\" -> " << (isValid("()[]{}") ? "true" : "false") << "\n";
    std::cout << "\"(]\" -> " << (isValid("(]") ? "true" : "false") << "\n";
    std::cout << "\"([)]\" -> " << (isValid("([)]") ? "true" : "false") << "\n";
    std::cout << "\"{[]}\" -> " << (isValid("{[]}") ? "true" : "false") << "\n";
}
