/**
 * Basic DSA - Valid Parentheses (LeetCode 20)
 * Brackets () [] {} must close in correct order (stack of expected openers).
 */
#include <iostream>
#include <string>
#include <vector>

bool isValid(const std::string& s) {
    std::vector<char> st;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push_back(c);
            continue;
        }
        if (st.empty())
            return false;
        char o = st.back();
        st.pop_back();
        if (c == ')' && o != '(')
            return false;
        if (c == ']' && o != '[')
            return false;
        if (c == '}' && o != '{')
            return false;
    }
    return st.empty();
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Valid Parentheses\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "\"()\" -> " << isValid("()") << "\n";
    std::cout << "\"()[]{}\" -> " << isValid("()[]{}") << "\n";
    std::cout << "\"(]\" -> " << isValid("(]") << "\n";
}
