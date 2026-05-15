/**
 * Basic DSA - Evaluate Reverse Polish Notation (LeetCode 150)
 * Stack operands; on operator pop two, apply, push. Integer division truncates toward zero.
 */
#include <iostream>
#include <string>
#include <vector>

int evalRPN(const std::vector<std::string>& tokens) {
    std::vector<long> st;
    st.reserve(tokens.size());
    for (const std::string& t : tokens) {
        if (t == "+" || t == "-" || t == "*" || t == "/") {
            long b = st.back();
            st.pop_back();
            long a = st.back();
            st.pop_back();
            if (t == "+")
                st.push_back(a + b);
            else if (t == "-")
                st.push_back(a - b);
            else if (t == "*")
                st.push_back(a * b);
            else
                st.push_back(a / b);
        } else {
            st.push_back(std::stol(t));
        }
    }
    return static_cast<int>(st.back());
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Evaluate RPN\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[2,1,+,3,*]           -> " << evalRPN({"2", "1", "+", "3", "*"}) << "\n";
    std::cout << "[4,13,5,/,+]         -> " << evalRPN({"4", "13", "5", "/", "+"}) << "\n";
    std::cout << "[10,6,9,3,+,-11,*,/,*,17,+,5,+] -> "
              << evalRPN({"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}) << "\n";
}
