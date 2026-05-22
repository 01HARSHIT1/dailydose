/**
 * Basic DSA - Number of Ways to Earn Points (LeetCode 2585)
 * Bounded knapsack: dp[p] = ways to reach exactly p points; per type iterate counts 0..count and marks.
 */
#include <iostream>
#include <vector>

int waysToReachTarget(int target, const std::vector<std::vector<int>>& types) {
    const int MOD = 1000000007;
    std::vector<long long> dp(static_cast<size_t>(target) + 1, 0);
    dp[0] = 1;

    for (const auto& type : types) {
        int count = type[0];
        int marks = type[1];
        for (int p = target; p >= 0; --p) {
            for (int used = 1; used <= count && used * marks <= p; ++used)
                dp[static_cast<size_t>(p)] =
                    (dp[static_cast<size_t>(p)] + dp[static_cast<size_t>(p - used * marks)]) % MOD;
        }
    }
    return static_cast<int>(dp[static_cast<size_t>(target)]);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Number of Ways to Earn Points\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << waysToReachTarget(6, {{6, 1}, {3, 2}, {2, 3}}) << "\n";
    std::cout << "sample 2 -> " << waysToReachTarget(5, {{50, 1}, {50, 2}, {50, 5}}) << "\n";
    std::cout << "sample 3 -> " << waysToReachTarget(18, {{6, 1}, {3, 2}, {2, 3}}) << "\n";
}
