/**
 * Basic DSA - Range Module (LeetCode 715)
 * Track covered half-open intervals [left, right). `map` keyed by start; addRange merges overlaps; queryRange checks coverage.
 */
#include <algorithm>
#include <iostream>
#include <map>
#include <utility>

struct RangeModule {
    std::map<int, int> iv; // start -> end (exclusive)

    void addRange(int left, int right) {
        auto it = iv.upper_bound(left);
        if (it != iv.begin())
            --it;
        if (it != iv.end() && it->second < left)
            ++it;
        int l = left;
        int r = right;
        while (it != iv.end() && it->first <= right) {
            l = std::min(l, it->first);
            r = std::max(r, it->second);
            it = iv.erase(it);
        }
        iv[l] = r;
    }

    bool queryRange(int left, int right) const {
        auto it = iv.upper_bound(left);
        if (it == iv.begin())
            return false;
        --it;
        return it->first <= left && it->second >= right;
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Range Module\n";
    std::cout << std::string(60, '=') << "\n";

    RangeModule rm;
    rm.addRange(10, 20);
    std::cout << "query [10,15) -> " << (rm.queryRange(10, 15) ? "true" : "false") << "\n";
    std::cout << "query [10,20) -> " << (rm.queryRange(10, 20) ? "true" : "false") << "\n";
    std::cout << "query [15,20) -> " << (rm.queryRange(15, 20) ? "true" : "false") << "\n";
    rm.addRange(15, 25);
    std::cout << "query [15,25) after merge -> " << (rm.queryRange(15, 25) ? "true" : "false") << "\n";
}
