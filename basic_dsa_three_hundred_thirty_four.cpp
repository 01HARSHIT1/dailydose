/**
 * Basic DSA - Design Circular Queue (LeetCode 622)
 * Fixed-size circular queue with enQueue, deQueue, Front, Rear, isEmpty, isFull.
 */
#include <iostream>
#include <vector>

class MyCircularQueue {
    std::vector<int> buf;
    int front, sz, cap;
public:
    MyCircularQueue(int k) : buf(k), front(0), sz(0), cap(k) {}
    bool enQueue(int value) {
        if (isFull()) return false;
        buf[(front + sz) % cap] = value;
        sz++;
        return true;
    }
    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % cap;
        sz--;
        return true;
    }
    int Front() { return isEmpty() ? -1 : buf[front]; }
    int Rear() { return isEmpty() ? -1 : buf[(front + sz - 1) % cap]; }
    bool isEmpty() { return sz == 0; }
    bool isFull() { return sz == cap; }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Design Circular Queue\n";
    std::cout << std::string(60, '=') << "\n";

    MyCircularQueue q(3);
    q.enQueue(1);
    q.enQueue(2);
    std::cout << "after enQueue 1,2: Rear -> " << q.Rear() << "\n";
    std::cout << "isFull -> " << (q.isFull() ? "true" : "false") << "\n";
    std::cout << "enQueue 3 -> " << q.enQueue(3) << "\n";
    std::cout << "enQueue 4 -> " << q.enQueue(4) << "\n";
    std::cout << "isFull -> " << (q.isFull() ? "true" : "false") << "\n";
    std::cout << "Rear -> " << q.Rear() << "\n";
    std::cout << "isFull -> " << (q.isFull() ? "true" : "false") << "\n";
    std::cout << "deQueue -> " << q.deQueue() << "\n";
    std::cout << "enQueue 4 -> " << q.enQueue(4) << "\n";
    std::cout << "Rear -> " << q.Rear() << "\n";
}
