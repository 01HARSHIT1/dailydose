/**
 * Basic DSA - Divide Array Into Equal Pairs (LeetCode 2206)
 * Split nums (length 2n) into n pairs where each pair has two equal numbers.
 */
#include <iostream>
#include <unordered_map>
#include <vector>

bool divideArray(std::vector<int>& nums) {
    std::unordered_map<int, int> cnt;
    for (int x : nums)
        ++cnt[x];
    for (const auto& p : cnt) {
        if (p.second % 2 != 0)
            return false;
    }
    return true;
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
    std::cout << "Problem: Divide Array Into Equal Pairs\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {3, 2, 3, 2, 2, 2};
    printVec(a1);
    std::cout << " -> " << (divideArray(a1) ? "true" : "false") << "\n";

    std::vector<int> a2 = {1, 2, 3, 4};
    printVec(a2);
    std::cout << " -> " << (divideArray(a2) ? "true" : "false") << "\n";
}
