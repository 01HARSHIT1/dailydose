/**
 * Basic DSA - Richest Customer Wealth (LeetCode 1672)
 * For each customer (row), sum their wealth across banks; return the maximum sum.
 */
#include <iostream>
#include <vector>

int maximumWealth(const std::vector<std::vector<int>>& accounts) {
    int best = 0;
    for (const auto& customer : accounts) {
        int sum = 0;
        for (int w : customer)
            sum += w;
        if (sum > best)
            best = sum;
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Richest Customer Wealth\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> a1 = {{1, 2, 3}, {3, 2, 1}};
    std::cout << "[[1,2,3],[3,2,1]] -> " << maximumWealth(a1) << "\n";

    std::vector<std::vector<int>> a2 = {{1, 5}, {7, 3}, {3, 5}};
    std::cout << "[[1,5],[7,3],[3,5]] -> " << maximumWealth(a2) << "\n";
}
