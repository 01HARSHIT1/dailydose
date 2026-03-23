/**
 * Basic DSA - Best Time to Buy and Sell Stock (LeetCode 121)
 * Max profit from one buy then one sell.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices) {
    int mn = prices[0], ans = 0;
    for (int i = 1; i < (int)prices.size(); i++) {
        ans = std::max(ans, prices[i] - mn);
        mn = std::min(mn, prices[i]);
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Best Time to Buy and Sell Stock\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {7, 1, 5, 3, 6, 4};
    std::cout << "[7,1,5,3,6,4] -> " << maxProfit(v1) << "\n";

    std::vector<int> v2 = {7, 6, 4, 3, 1};
    std::cout << "[7,6,4,3,1] -> " << maxProfit(v2) << "\n";
}
