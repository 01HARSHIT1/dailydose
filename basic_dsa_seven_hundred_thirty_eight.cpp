/**
 * Basic DSA - Find Minimum Cost to Remove Array Elements (LeetCode 3469)
 * Remove elements using first-three pairs or final cleanup; minimize total cost.
 */

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int minCost(const std::vector<int>& nums) {
    const int n = static_cast<int>(nums.size());
    std::vector<std::vector<int>> memo(n + 1, std::vector<int>(n + 1, -1));

    std::function<int(int, int)> dfs = [&](int last, int i) -> int {
        if (i == n)
            return nums[last];
        if (i == n - 1)
            return std::max(nums[last], nums[i]);
        if (memo[i][last] != -1)
            return memo[i][last];

        const int optionA = std::max(nums[i], nums[i + 1]) + dfs(last, i + 2);
        const int optionB = std::max(nums[last], nums[i]) + dfs(i + 1, i + 2);
        const int optionC = std::max(nums[last], nums[i + 1]) + dfs(i, i + 2);

        return memo[i][last] = std::min({optionA, optionB, optionC});
    };

    return dfs(0, 1);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Minimum Cost to Remove Array Elements\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minCost({6, 2, 8, 4}) << "\n";
    std::cout << "sample 2 -> " << minCost({2, 1, 3, 3}) << "\n";
}
