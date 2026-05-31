/**
 * Basic DSA - Maximum Coin Collection (LeetCode 3466)
 * Maximize coins driving two lanes with at most 2 lane switches.
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

long long maxCoins(const std::vector<int>& lane1, const std::vector<int>& lane2) {
    const int n = static_cast<int>(lane1.size());
    const long long negInf = (long long)-1e18;
    std::vector<std::vector<std::vector<long long>>> memo(
        n, std::vector<std::vector<long long>>(2, std::vector<long long>(3, negInf)));

    std::function<long long(int, int, int)> dfs = [&](int i, int lane, int switches) -> long long {
        if (i >= n)
            return 0LL;
        if (memo[i][lane][switches] != negInf)
            return memo[i][lane][switches];

        const long long coins = lane == 0 ? lane1[i] : lane2[i];
        long long ans = std::max(coins, dfs(i + 1, lane, switches) + coins);

        if (switches > 0) {
            ans = std::max(ans, dfs(i + 1, lane ^ 1, switches - 1) + coins);
            ans = std::max(ans, dfs(i, lane ^ 1, switches - 1));
        }

        return memo[i][lane][switches] = ans;
    };

    long long result = negInf;
    for (int start = 0; start < n; ++start)
        result = std::max(result, dfs(start, 0, 2));
    return result;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Coin Collection\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxCoins({1, -2, -10, 3}, {-5, 10, 0, 1}) << "\n";
    std::cout << "sample 2 -> " << maxCoins({1, -1, -1, -1}, {0, 3, 4, -5}) << "\n";
}
