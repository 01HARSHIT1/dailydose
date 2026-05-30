/**
 * Basic DSA - Minimum Array Changes to Make Differences Equal (LeetCode 3441)
 * Make all symmetric pairs share the same absolute difference with minimum changes.
 */

#include <algorithm>
#include <iostream>
#include <vector>

int minChanges(const std::vector<int>& nums, int k) {
    std::vector<int> diff(k + 2, 0);
    const int n = static_cast<int>(nums.size());

    for (int i = 0; i < n / 2; ++i) {
        const int x = std::min(nums[i], nums[n - i - 1]);
        const int y = std::max(nums[i], nums[n - i - 1]);
        const int limit = std::max(y, k - x);

        diff[0] += 1;
        diff[y - x] -= 1;
        diff[y - x + 1] += 1;
        diff[limit + 1] -= 1;
        diff[limit + 1] += 2;
    }

    int ans = n;
    int prefix = 0;
    for (int delta : diff) {
        prefix += delta;
        ans = std::min(ans, prefix);
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Array Changes to Make Differences Equal\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minChanges({1, 0, 1, 2, 4, 3}, 4) << "\n";
    std::cout << "sample 2 -> " << minChanges({0, 1, 2, 3, 3, 6, 5, 4}, 6) << "\n";
}
