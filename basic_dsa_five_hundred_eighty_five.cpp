/**
 * Basic DSA - My Calendar II (LeetCode 731)
 * At most double booking allowed; triple overlap rejected. Track single-booked and double-booked sub-intervals separately.
 */
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

struct MyCalendarTwo {
    std::vector<std::pair<int, int>> single;
    std::vector<std::pair<int, int>> dbl;

    static bool overlap(int s1, int e1, int s2, int e2) {
        return std::max(s1, s2) < std::min(e1, e2);
    }

    static std::pair<int, int> intersect(int s1, int e1, int s2, int e2) {
        return {std::max(s1, s2), std::min(e1, e2)};
    }

    bool book(int start, int end) {
        for (const auto& p : dbl) {
            if (overlap(start, end, p.first, p.second))
                return false;
        }
        for (const auto& p : single) {
            if (overlap(start, end, p.first, p.second))
                dbl.push_back(intersect(start, end, p.first, p.second));
        }
        single.push_back({start, end});
        return true;
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: My Calendar II\n";
    std::cout << std::string(60, '=') << "\n";

    MyCalendarTwo cal;
    std::cout << "[10,20) -> " << (cal.book(10, 20) ? "true" : "false") << "\n";
    std::cout << "[50,60) -> " << (cal.book(50, 60) ? "true" : "false") << "\n";
    std::cout << "[10,40) -> " << (cal.book(10, 40) ? "true" : "false") << "\n";
    std::cout << "[5,15)  -> " << (cal.book(5, 15) ? "true" : "false") << "\n";
}
