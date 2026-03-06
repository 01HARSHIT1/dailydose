/**
 * Basic DSA - Min Stack (LeetCode 155)
 * Stack that supports push, pop, top, and getMin in O(1).
 */
#include <iostream>
#include <stack>

class MinStack {
    std::stack<int> st, minSt;
public:
    void push(int val) {
        st.push(val);
        if (minSt.empty() || val <= minSt.top()) minSt.push(val);
    }
    void pop() {
        if (st.top() == minSt.top()) minSt.pop();
        st.pop();
    }
    int top() { return st.top(); }
    int getMin() { return minSt.top(); }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Min Stack\n";
    std::cout << std::string(60, '=') << "\n";

    MinStack ms;
    ms.push(-2); ms.push(0); ms.push(-3);
    std::cout << "push -2,0,-3; getMin -> " << ms.getMin() << "\n";
    ms.pop();
    std::cout << "pop; top -> " << ms.top() << ", getMin -> " << ms.getMin() << "\n";
}
