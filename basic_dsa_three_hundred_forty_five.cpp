/**
 * Basic DSA - Min Cost Climbing Stairs (LeetCode 746)
 * Min cost to reach top (index n) from step 0 or 1.
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int minCostClimbingStairs(std::vector<int>& cost) {
    int n = cost.size();
    int a = cost[0], b = cost[1];
    for (int i = 2; i < n; i++) {
        int c = cost[i] + std::min(a, b);
        a = b;
        b = c;
    }
    return std::min(a, b);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Min Cost Climbing Stairs\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {10, 15, 20};
    std::cout << "[10,15,20] -> " << minCostClimbingStairs(v1) << "\n";

    std::vector<int> v2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    std::cout << "long example -> " << minCostClimbingStairs(v2) << "\n";
}
