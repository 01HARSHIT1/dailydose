/**
 * Basic DSA - Moving Average from Data Stream (LeetCode 346)
 * Fixed-size window over streamed integers. Queue stores the window; evict front when full; return running mean.
 */
#include <iostream>
#include <queue>

struct MovingAverage {
    int cap;
    double sum = 0;
    std::queue<int> q;

    explicit MovingAverage(int size) : cap(size) {}

    double next(int val) {
        if (static_cast<int>(q.size()) == cap) {
            sum -= static_cast<double>(q.front());
            q.pop();
        }
        q.push(val);
        sum += static_cast<double>(val);
        return sum / static_cast<double>(q.size());
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Moving Average from Data Stream\n";
    std::cout << std::string(60, '=') << "\n";

    MovingAverage ma(3);
    std::cout << "next(1)  -> " << ma.next(1) << "\n";
    std::cout << "next(10) -> " << ma.next(10) << "\n";
    std::cout << "next(3)  -> " << ma.next(3) << "\n";
    std::cout << "next(5)  -> " << ma.next(5) << "\n";
}
