/**
 * Basic DSA - Random Pick with Blacklist (LeetCode 710)
 * Uniform pick from [0,n) minus blacklist. Let sz = n - |B|; remap first sz indices that hit blacklist to safe IDs pulled from the tail.
 */
#include <iostream>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct PickWithBlacklist {
    int sz;
    std::unordered_map<int, int> remap;

    PickWithBlacklist(int n, std::vector<int> blacklist) {
        std::unordered_set<int> banned(blacklist.begin(), blacklist.end());
        sz = n - static_cast<int>(blacklist.size());
        int hi = n - 1;
        for (int b : blacklist) {
            if (b < sz) {
                while (banned.count(hi))
                    --hi;
                remap[b] = hi;
                --hi;
            }
        }
    }

    int pick(std::mt19937& gen) const {
        std::uniform_int_distribution<int> dist(0, sz - 1);
        int x = dist(gen);
        auto it = remap.find(x);
        return it == remap.end() ? x : it->second;
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Random Pick with Blacklist\n";
    std::cout << std::string(60, '=') << "\n";

    PickWithBlacklist pwb(4, {0, 2});
    std::mt19937 gen(999);
    std::cout << "n=4 blacklist {0,2}, 8 picks: ";
    for (int i = 0; i < 8; ++i)
        std::cout << pwb.pick(gen) << (i < 7 ? " " : "");
    std::cout << "\n";
}
