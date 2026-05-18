/**
 * Basic DSA - Design Hit Counter (LeetCode 362)
 * Count hits in the past 300 seconds from a given time. Queue of (timestamp, count) batches; drop entries older than t-300 before answering.
 */
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

struct HitCounter {
    std::queue<std::pair<int, int>> window; // time -> hits at that second (merged)
    int total = 0;

    void hit(int timestamp) {
        if (!window.empty() && window.back().first == timestamp)
            ++window.back().second;
        else
            window.push({timestamp, 1});
        ++total;
    }

    void prune(int timestamp) {
        int cutoff = timestamp - 300;
        while (!window.empty() && window.front().first <= cutoff) {
            total -= window.front().second;
            window.pop();
        }
    }

    int getHits(int timestamp) {
        prune(timestamp);
        return total;
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Design Hit Counter\n";
    std::cout << std::string(60, '=') << "\n";

    HitCounter h;
    h.hit(1);
    h.hit(2);
    h.hit(3);
    std::cout << "past 5m at t=4  -> " << h.getHits(4) << "\n";
    h.hit(300);
    std::cout << "past 5m at t=300 -> " << h.getHits(300) << "\n";
    std::cout << "past 5m at t=301 -> " << h.getHits(301) << "\n";
}
