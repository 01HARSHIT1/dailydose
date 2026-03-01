/**
 * Basic DSA - Implement Stack using Queues (LeetCode 225)
 * Stack with push, pop, top, empty using two queues.
 */
#include <iostream>
#include <queue>

class MyStack {
    std::queue<int> q;
public:
    void push(int x) {
        int n = q.size();
        q.push(x);
        while (n--) {
            q.push(q.front());
            q.pop();
        }
    }
    int pop() {
        int x = q.front();
        q.pop();
        return x;
    }
    int top() { return q.front(); }
    bool empty() { return q.empty(); }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Implement Stack using Queues\n";
    std::cout << std::string(60, '=') << "\n";

    MyStack st;
    st.push(1);
    st.push(2);
    std::cout << "push(1), push(2), top() -> " << st.top() << "\n";
    std::cout << "pop() -> " << st.pop() << "\n";
    std::cout << "empty() -> " << (st.empty() ? "true" : "false") << "\n";
}
