/**
 * Basic DSA - Implement Queue using Stacks (LeetCode 232)
 * Queue with push, pop, peek, empty using two stacks.
 */
#include <iostream>
#include <stack>

class MyQueue {
    std::stack<int> in, out;
    void pour() {
        if (out.empty())
            while (!in.empty()) { out.push(in.top()); in.pop(); }
    }
public:
    void push(int x) { in.push(x); }
    int pop() {
        pour();
        int x = out.top();
        out.pop();
        return x;
    }
    int peek() {
        pour();
        return out.top();
    }
    bool empty() { return in.empty() && out.empty(); }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Implement Queue using Stacks\n";
    std::cout << std::string(60, '=') << "\n";

    MyQueue q;
    q.push(1);
    q.push(2);
    std::cout << "push(1), push(2), peek() -> " << q.peek() << "\n";
    std::cout << "pop() -> " << q.pop() << "\n";
    std::cout << "empty() -> " << (q.empty() ? "true" : "false") << "\n";
    std::cout << "pop() -> " << q.pop() << "\n";
    std::cout << "empty() -> " << (q.empty() ? "true" : "false") << "\n";
}
