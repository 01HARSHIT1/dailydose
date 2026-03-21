/**
 * Basic DSA - Valid Parentheses (LeetCode 20)
 * Return true if brackets (), [], {} are properly nested.
 */
#include <iostream>
#include <string>
#include <stack>

bool isValid(std::string s) {
    std::stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') st.push(c);
        else {
            if (st.empty()) return false;
            char t = st.top(); st.pop();
            if ((c == ')' && t != '(') || (c == ']' && t != '[') || (c == '}' && t != '{'))
                return false;
        }
    }
    return st.empty();
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Valid Parentheses\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "() -> " << (isValid("()") ? "true" : "false") << "\n";
    std::cout << "()[]{} -> " << (isValid("()[]{}") ? "true" : "false") << "\n";
    std::cout << "(] -> " << (isValid("(]") ? "true" : "false") << "\n";
}
