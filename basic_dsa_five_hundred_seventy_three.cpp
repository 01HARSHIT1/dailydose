/**
 * Basic DSA - Hand of Straights (LeetCode 846)
 * Partition into groups of size groupSize of consecutive integers. Greedy from smallest card; map counts consumption.
 */
#include <iostream>
#include <map>
#include <vector>

bool isNStraightHand(const std::vector<int>& hand, int groupSize) {
    if (static_cast<int>(hand.size()) % groupSize != 0)
        return false;
    std::map<int, int> cnt;
    for (int x : hand)
        ++cnt[x];
    while (!cnt.empty()) {
        int start = cnt.begin()->first;
        for (int x = start; x < start + groupSize; ++x) {
            auto it = cnt.find(x);
            if (it == cnt.end())
                return false;
            if (--it->second == 0)
                cnt.erase(it);
        }
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Hand of Straights\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> h = {1, 2, 3, 6, 2, 3, 4, 7, 8};
    std::cout << "sample W=3 -> " << (isNStraightHand(h, 3) ? "true" : "false") << "\n";
    std::cout << "bad        -> " << (isNStraightHand({1, 2, 3, 4, 5}, 4) ? "true" : "false") << "\n";
}
