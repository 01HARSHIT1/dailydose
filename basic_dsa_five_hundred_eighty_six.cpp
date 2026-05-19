/**
 * Basic DSA - My Calendar III (LeetCode 732)
 * After each book(start,end), return max concurrent events. Sweep line: +1 at start, -1 at end; prefix max over sorted times.
 */
#include <algorithm>
#include <iostream>
#include <map>

struct MyCalendarThree {
    std::map<int, int> delta;

    int book(int start, int end) {
        ++delta[start];
        --delta[end];
        int cur = 0;
        int best = 0;
        for (const auto& p : delta) {
            cur += p.second;
            best = std::max(best, cur);
        }
        return best;
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: My Calendar III\n";
    std::cout << std::string(60, '=') << "\n";

    MyCalendarThree cal;
    std::cout << "[10,20) -> max " << cal.book(10, 20) << "\n";
    std::cout << "[50,60) -> max " << cal.book(50, 60) << "\n";
    std::cout << "[10,40) -> max " << cal.book(10, 40) << "\n";
    std::cout << "[5,15)  -> max " << cal.book(5, 15) << "\n";
    std::cout << "[5,10)  -> max " << cal.book(5, 10) << "\n";
    std::cout << "[25,55) -> max " << cal.book(25, 55) << "\n";
}
