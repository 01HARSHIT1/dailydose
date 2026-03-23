/**
 * Basic DSA - Coin Change (LeetCode 322)
 * Fewest coins to make amount (each coin unlimited), or -1.
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int coinChange(std::vector<int>& coins, int amount) {
    const int INF = amount + 1;
    std::vector<int> dp(amount + 1, INF);
    dp[0] = 0;
    for (int x : coins)
        for (int s = x; s <= amount; s++)
            dp[s] = std::min(dp[s], dp[s - x] + 1);
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Coin Change\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> c1 = {1, 2, 5};
    std::cout << "coins [1,2,5], 11 -> " << coinChange(c1, 11) << "\n";

    std::vector<int> c2 = {2};
    std::cout << "coins [2], 3 -> " << coinChange(c2, 3) << "\n";

    std::vector<int> c3 = {1};
    std::cout << "coins [1], 0 -> " << coinChange(c3, 0) << "\n";
}
