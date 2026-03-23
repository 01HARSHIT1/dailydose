/**
 * Basic DSA - Implement Stack using Queues (LeetCode 225)
 * push O(n), top/pop O(1) using two queues.
 */
#include <iostream>
#include <string>
#include <queue>

class MyStack {
    std::queue<int> q1, q2;
public:
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        std::swap(q1, q2);
    }
    int pop() {
        int v = q1.front();
        q1.pop();
        return v;
    }
    int top() { return q1.front(); }
    bool empty() { return q1.empty(); }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Implement Stack using Queues\n";
    std::cout << std::string(60, '=') << "\n";

    MyStack st;
    st.push(1);
    st.push(2);
    std::cout << "top -> " << st.top() << "\n";
    std::cout << "pop -> " << st.pop() << "\n";
    std::cout << "empty -> " << (st.empty() ? "true" : "false") << "\n";
}
