/**
 * Basic DSA - Implement Queue using Stacks (LeetCode 232)
 * push O(1), pop/peek amortized O(1).
 */
#include <iostream>
#include <string>
#include <stack>

class MyQueue {
    std::stack<int> in, out;
    void dump() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
    }
public:
    void push(int x) { in.push(x); }
    int pop() {
        dump();
        int v = out.top();
        out.pop();
        return v;
    }
    int peek() {
        dump();
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
    std::cout << "peek -> " << q.peek() << "\n";
    std::cout << "pop -> " << q.pop() << "\n";
    std::cout << "empty -> " << (q.empty() ? "true" : "false") << "\n";
}
