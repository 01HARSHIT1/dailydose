/**
 * Basic DSA - Min Stack (LeetCode 155)
 * Design a stack that supports push, pop, top, and getMin in O(1).
 */
#include <iostream>
#include <stack>

class MinStack {
    std::stack<int> stk, minStk;
public:
    void push(int val) {
        stk.push(val);
        if (minStk.empty() || val <= minStk.top())
            minStk.push(val);
    }
    void pop() {
        if (stk.top() == minStk.top())
            minStk.pop();
        stk.pop();
    }
    int top() { return stk.top(); }
    int getMin() { return minStk.top(); }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Min Stack\n";
    std::cout << std::string(60, '=') << "\n";

    MinStack ms;
    ms.push(-2);
    ms.push(0);
    ms.push(-3);
    std::cout << "push(-2), push(0), push(-3) -> getMin: " << ms.getMin() << "\n";
    ms.pop();
    std::cout << "pop() -> top: " << ms.top() << ", getMin: " << ms.getMin() << "\n";
}
