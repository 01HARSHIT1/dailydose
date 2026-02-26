/**
 * Basic DSA - Best Time to Buy and Sell Stock (LeetCode 121)
 * Find max profit from one buy and one sell.
 */
#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices) {
    int minPrice = prices[0], profit = 0;
    for (int p : prices) {
        minPrice = std::min(minPrice, p);
        profit = std::max(profit, p - minPrice);
    }
    return profit;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Best Time to Buy and Sell Stock\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {7, 1, 5, 3, 6, 4};
    std::cout << "[7,1,5,3,6,4] -> " << maxProfit(a1) << "\n";

    std::vector<int> a2 = {7, 6, 4, 3, 1};
    std::cout << "[7,6,4,3,1] -> " << maxProfit(a2) << "\n";

    std::vector<int> a3 = {2, 4, 1};
    std::cout << "[2,4,1] -> " << maxProfit(a3) << "\n";
}
