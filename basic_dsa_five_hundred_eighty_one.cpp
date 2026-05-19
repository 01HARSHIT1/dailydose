/**
 * Basic DSA - Insert Delete GetRandom O(1) (LeetCode 380)
 * Vector holds values; map value -> index. Delete swaps target with last element for O(1) erase.
 */
#include <iostream>
#include <random>
#include <unordered_map>
#include <vector>

struct RandomizedSet {
    std::vector<int> vals;
    std::unordered_map<int, int> idx;
    std::mt19937 gen{42};

    bool insert(int val) {
        if (idx.count(val))
            return false;
        idx[val] = static_cast<int>(vals.size());
        vals.push_back(val);
        return true;
    }

    bool remove(int val) {
        if (!idx.count(val))
            return false;
        int i = idx[val];
        int last = vals.back();
        vals[static_cast<size_t>(i)] = last;
        idx[last] = i;
        vals.pop_back();
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
    std::cout << "Problem: Insert Delete GetRandom O(1)\n";
    std::cout << std::string(60, '=') << "\n";

    RandomizedSet rs;
    std::cout << "insert(1)  -> " << (rs.insert(1) ? "true" : "false") << "\n";
    std::cout << "remove(2)  -> " << (rs.remove(2) ? "true" : "false") << "\n";
    std::cout << "insert(2)  -> " << (rs.insert(2) ? "true" : "false") << "\n";
    std::cout << "getRandom  -> " << rs.getRandom() << "\n";
    std::cout << "remove(1)  -> " << (rs.remove(1) ? "true" : "false") << "\n";
    std::cout << "insert(2)  -> " << (rs.insert(2) ? "true" : "false") << "\n";
    std::cout << "getRandom  -> " << rs.getRandom() << "\n";
}
