/**
 * Basic DSA - Unique Number of Occurrences (LeetCode 1207)
 * True iff every value's frequency is unique across the multiset.
 */
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

bool uniqueOccurrences(const std::vector<int>& arr) {
    std::unordered_map<int, int> cnt;
    for (int x : arr)
        ++cnt[x];
    std::unordered_set<int> seen;
    for (const auto& p : cnt) {
        if (!seen.insert(p.second).second)
            return false;
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Unique Number of Occurrences\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 2, 2, 1, 1, 3};
    std::cout << "[1,2,2,1,1,3] -> " << (uniqueOccurrences(v1) ? "true" : "false") << "\n";

    std::vector<int> v2 = {1, 2};
    std::cout << "[1,2] -> " << (uniqueOccurrences(v2) ? "true" : "false") << "\n";
}
