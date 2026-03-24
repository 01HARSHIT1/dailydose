/**
 * Basic DSA - Array Nesting (LeetCode 565)
 * nums[i] in [0, n-1]. From any start index, follow nums[i]; max cycle length.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int arrayNesting(std::vector<int>& nums) {
    int n = static_cast<int>(nums.size());
    int best = 0;
    std::vector<bool> vis(n);
    for (int i = 0; i < n; ++i) {
        if (vis[i])
            continue;
        int c = 0;
        for (int j = i; !vis[j]; j = nums[j]) {
            vis[j] = true;
            ++c;
        }
        best = std::max(best, c);
    }
    return best;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Array Nesting\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {5, 4, 0, 3, 1, 6, 2};
    std::cout << "[5,4,0,3,1,6,2] -> " << arrayNesting(v1) << "\n";

    std::vector<int> v2 = {0, 2, 1};
    std::cout << "[0,2,1] -> " << arrayNesting(v2) << "\n";
}
