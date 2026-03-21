/**
 * Basic DSA - Min Stack (LeetCode 155)
 * push, pop, top, getMin in O(1) amortized.
 */
#include <iostream>
#include <vector>
#include <algorithm>

class MinStack {
    std::vector<int> st, mn;
public:
    void push(int val) {
        st.push_back(val);
        mn.push_back(mn.empty() ? val : std::min(val, mn.back()));
    }
    void pop() {
        st.pop_back();
        mn.pop_back();
    }
    int top() { return st.back(); }
    int getMin() { return mn.back(); }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Min Stack\n";
    std::cout << std::string(60, '=') << "\n";

    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    std::cout << "getMin -> " << ms.getMin() << "\n";
    ms.pop();
    std::cout << "top -> " << ms.top() << "\n";
    std::cout << "getMin -> " << ms.getMin() << "\n";
}
