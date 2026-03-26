/**
 * Basic DSA - Validate Stack Sequences (LeetCode 946)
 * Simulate pushes in order; pop whenever top matches next wanted pop.
 */
#include <iostream>
#include <stack>
#include <string>
#include <vector>

bool validateStackSequences(const std::vector<int>& pushed, const std::vector<int>& popped) {
    std::stack<int> st;
    int j = 0;
    int m = static_cast<int>(popped.size());
    for (int x : pushed) {
        st.push(x);
        while (!st.empty() && j < m && st.top() == popped[j]) {
            st.pop();
            ++j;
        }
    }
    return j == m;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Validate Stack Sequences\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> p1 = {1, 2, 3, 4, 5};
    std::vector<int> o1 = {4, 5, 3, 2, 1};
    std::cout << "[1,2,3,4,5] push / [4,5,3,2,1] pop -> "
              << (validateStackSequences(p1, o1) ? "true" : "false") << "\n";

    std::vector<int> p2 = {1, 2, 3, 4, 5};
    std::vector<int> o2 = {4, 3, 5, 1, 2};
    std::cout << "[1,2,3,4,5] push / [4,3,5,1,2] pop -> "
              << (validateStackSequences(p2, o2) ? "true" : "false") << "\n";
}
