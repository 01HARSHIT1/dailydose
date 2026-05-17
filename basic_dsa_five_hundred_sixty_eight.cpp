/**
 * Basic DSA - My Calendar I (LeetCode 729)
 * Book [start, end) if it does not intersect an existing booking. `map` of intervals by start; check predecessor against `end`.
 */
#include <iostream>
#include <map>
#include <utility>

struct MyCalendar {
    std::map<int, int> iv; // start -> end

    bool book(int start, int end) {
        auto it = iv.lower_bound(end);
        if (it != iv.begin()) {
            auto prev = std::prev(it);
            if (prev->second > start)
                return false;
        }
        iv[start] = end;
        return true;
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: My Calendar I\n";
    std::cout << std::string(60, '=') << "\n";

    MyCalendar cal;
    std::cout << "[10,20) -> " << (cal.book(10, 20) ? "true" : "false") << "\n";
    std::cout << "[15,25) -> " << (cal.book(15, 25) ? "true" : "false") << "\n";
    std::cout << "[20,30) -> " << (cal.book(20, 30) ? "true" : "false") << "\n";
}
