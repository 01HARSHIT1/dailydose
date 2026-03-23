/**
 * Basic DSA - House Robber (LeetCode 198)
 * Max money robbing linear street (no two adjacent houses).
 */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int rob(std::vector<int>& nums) {
    int prev2 = 0, prev1 = 0;
    for (int x : nums) {
        int cur = std::max(prev1, prev2 + x);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: House Robber\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 2, 3, 1};
    std::cout << "[1,2,3,1] -> " << rob(v1) << "\n";

    std::vector<int> v2 = {2, 7, 9, 3, 1};
    std::cout << "[2,7,9,3,1] -> " << rob(v2) << "\n";
}
