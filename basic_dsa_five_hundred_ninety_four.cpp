/**
 * Basic DSA - Design Front Middle Back Queue (LeetCode 1670)
 * Two deques `left` and `right`; keep sizes balanced so middle ops touch the end of `left`.
 */
#include <algorithm>
#include <deque>
#include <iostream>

struct FrontMiddleBackQueue {
    std::deque<int> left;
    std::deque<int> right;

    void balance() {
        while (static_cast<int>(left.size()) < static_cast<int>(right.size())) {
            left.push_back(right.front());
            right.pop_front();
        }
        while (static_cast<int>(left.size()) > static_cast<int>(right.size()) + 1) {
            right.push_front(left.back());
            left.pop_back();
        }
    }

    void pushFront(int val) {
        left.push_front(val);
        balance();
    }

    void pushMiddle(int val) {
        left.push_back(val);
        balance();
    }

    void pushBack(int val) {
        right.push_back(val);
        balance();
    }

    int popFront() {
        int v = left.front();
        left.pop_front();
        balance();
        return v;
    }

    int popMiddle() {
        int v = left.back();
        left.pop_back();
        balance();
        return v;
    }

    int popBack() {
        int v = right.back();
        right.pop_back();
        balance();
        return v;
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Design Front Middle Back Queue\n";
    std::cout << std::string(60, '=') << "\n";

    FrontMiddleBackQueue q;
    q.pushFront(1);
    q.pushBack(2);
    q.pushMiddle(3);
    std::cout << "popMiddle -> " << q.popMiddle() << "\n";
    std::cout << "popFront  -> " << q.popFront() << "\n";
    std::cout << "popBack   -> " << q.popBack() << "\n";
}
