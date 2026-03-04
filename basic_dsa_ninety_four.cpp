/**
 * Basic DSA - Richest Customer Wealth (LeetCode 1672)
 * Return max sum of any row in accounts (grid of bank balances).
 */
#include <iostream>
#include <vector>
#include <algorithm>

int maximumWealth(std::vector<std::vector<int>>& accounts) {
    int maxW = 0;
    for (auto& row : accounts) {
        int sum = 0;
        for (int x : row) sum += x;
        maxW = std::max(maxW, sum);
    }
    return maxW;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Richest Customer Wealth\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> a1 = {{1, 2, 3}, {3, 2, 1}};
    std::cout << "[[1,2,3],[3,2,1]] -> " << maximumWealth(a1) << "\n";

    std::vector<std::vector<int>> a2 = {{1, 5}, {7, 3}, {3, 5}};
    std::cout << "[[1,5],[7,3],[3,5]] -> " << maximumWealth(a2) << "\n";

    std::vector<std::vector<int>> a3 = {{2, 8, 7}, {7, 1, 3}, {1, 9, 5}};
    std::cout << "[[2,8,7],[7,1,3],[1,9,5]] -> " << maximumWealth(a3) << "\n";
}
