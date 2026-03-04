/**
 * Basic DSA - Valid Parentheses (LeetCode 20)
 * Check if brackets are valid (properly closed and nested).
 */
#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

bool isValid(std::string s) {
    std::stack<char> st;
    std::unordered_map<char, char> m = {{')','('}, {']','['}, {'}','{'}};
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') st.push(c);
        else {
            if (st.empty() || st.top() != m[c]) return false;
            st.pop();
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
    std::cout << "([)] -> " << (isValid("([)]") ? "true" : "false") << "\n";
}
