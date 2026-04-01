/**
 * Basic DSA - Maximum Number of Pairs in Array (LeetCode 2341)
 * Form disjoint pairs of equal values; return {pair count, unpaired count}.
 */
#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> numberOfPairs(std::vector<int>& nums) {
    std::unordered_map<int, int> cnt;
    for (int x : nums)
        ++cnt[x];
    int pairs = 0;
    for (const auto& p : cnt)
        pairs += p.second / 2;
    int leftover = static_cast<int>(nums.size()) - 2 * pairs;
    return {pairs, leftover};
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Number of Pairs in Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 3, 2, 1, 3, 2, 1};
    printVec(a1);
    std::cout << " -> ";
    printVec(numberOfPairs(a1));
    std::cout << "\n";

    std::vector<int> a2 = {1, 1};
    printVec(a2);
    std::cout << " -> ";
    printVec(numberOfPairs(a2));
    std::cout << "\n";

    std::vector<int> a3 = {0};
    printVec(a3);
    std::cout << " -> ";
    printVec(numberOfPairs(a3));
    std::cout << "\n";
}
