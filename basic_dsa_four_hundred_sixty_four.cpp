/**
 * Basic DSA - Make Array Zero by Subtracting Equal Amounts (LeetCode 2357)
 * Each step subtract the current minimum of positive entries from all positives.
 * Operations needed equals the number of distinct positive values.
 */
#include <iostream>
#include <unordered_set>
#include <vector>

int minimumOperations(std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int x : nums) {
        if (x > 0)
            seen.insert(x);
    }
    return static_cast<int>(seen.size());
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
    std::cout << "Problem: Make Array Zero by Subtracting Equal Amounts\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 5, 0, 3, 5};
    printVec(a1);
    std::cout << " -> " << minimumOperations(a1) << "\n";

    std::vector<int> a2 = {0};
    printVec(a2);
    std::cout << " -> " << minimumOperations(a2) << "\n";
}
