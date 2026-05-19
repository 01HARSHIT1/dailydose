/**
 * Basic DSA - Insert Delete GetRandom O(1) - Duplicates Allowed (LeetCode 381)
 * Same swap-delete trick as #380; each value maps to a set of indices in the backing vector.
 */
#include <iostream>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <vector>

struct RandomizedCollection {
    std::vector<int> vals;
    std::unordered_map<int, std::unordered_set<int>> idx;
    std::mt19937 gen{42};

    bool insert(int val) {
        idx[val].insert(static_cast<int>(vals.size()));
        vals.push_back(val);
        return idx[val].size() == 1;
    }

    bool remove(int val) {
        if (!idx.count(val))
            return false;
        int i = *idx[val].begin();
        int last = vals.back();
        vals[static_cast<size_t>(i)] = last;
        idx[last].erase(static_cast<int>(vals.size()) - 1);
        idx[last].insert(i);
        vals.pop_back();
        idx[val].erase(i);
        if (idx[val].empty())
            idx.erase(val);
        return true;
    }

    int getRandom() {
        std::uniform_int_distribution<int> dist(0, static_cast<int>(vals.size()) - 1);
        return vals[static_cast<size_t>(dist(gen))];
    }
};

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Randomized Collection (duplicates allowed)\n";
    std::cout << std::string(60, '=') << "\n";

    RandomizedCollection rc;
    std::cout << "insert(1) -> " << (rc.insert(1) ? "true" : "false") << "\n";
    std::cout << "insert(1) -> " << (rc.insert(1) ? "true" : "false") << "\n";
    std::cout << "insert(2) -> " << (rc.insert(2) ? "true" : "false") << "\n";
    std::cout << "getRandom -> " << rc.getRandom() << "\n";
    std::cout << "remove(1)  -> " << (rc.remove(1) ? "true" : "false") << "\n";
    std::cout << "getRandom -> " << rc.getRandom() << "\n";
}
