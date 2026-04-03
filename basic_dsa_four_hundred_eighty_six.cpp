/**
 * Basic DSA - Best Time to Buy and Sell Stock (LeetCode 121)
 * One buy and one sell; maximize profit. Prices given in day order.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int maxProfit(const std::vector<int>& prices) {
    if (prices.empty())
        return 0;
    int minPrice = prices[0];
    int best = 0;
    for (size_t i = 1; i < prices.size(); ++i) {
        best = std::max(best, prices[i] - minPrice);
        minPrice = std::min(minPrice, prices[i]);
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Best Time to Buy and Sell Stock\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[7,1,5,3,6,4] -> " << maxProfit({7, 1, 5, 3, 6, 4}) << "\n";
    std::cout << "[7,6,4,3,1] -> " << maxProfit({7, 6, 4, 3, 1}) << "\n";
}
