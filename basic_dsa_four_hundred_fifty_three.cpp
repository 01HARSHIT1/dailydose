/**
 * Basic DSA - Sum of Unique Elements (LeetCode 1748)
 * Sum of numbers that appear exactly once in nums.
 */
#include <iostream>
#include <unordered_map>
#include <vector>

int sumOfUnique(const std::vector<int>& nums) {
    std::unordered_map<int, int> cnt;
    for (int x : nums)
        ++cnt[x];
    int s = 0;
    for (const auto& p : cnt) {
        if (p.second == 1)
            s += p.first;
    }
    return s;
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
    std::cout << "Problem: Sum of Unique Elements\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 3, 2};
    printVec(a1);
    std::cout << " -> " << sumOfUnique(a1) << "\n";

    std::vector<int> a2 = {1, 1, 1, 1, 1};
    printVec(a2);
    std::cout << " -> " << sumOfUnique(a2) << "\n";

    std::vector<int> a3 = {1, 2, 3, 4, 5};
    printVec(a3);
    std::cout << " -> " << sumOfUnique(a3) << "\n";
}
