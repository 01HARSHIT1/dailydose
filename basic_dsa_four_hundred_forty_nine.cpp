/**
 * Basic DSA - Minimum Cost to Move Chips to The Same Position (LeetCode 1217)
 * Moving two steps costs 0; moving one step costs 1. Minimize total cost.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int minCostToMoveChips(std::vector<int>& position) {
    int even = 0, odd = 0;
    for (int p : position) {
        if (p % 2 == 0)
            ++even;
        else
            ++odd;
    }
    return std::min(even, odd);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Cost to Move Chips to The Same Position\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 3};
    std::cout << "[1,2,3] -> " << minCostToMoveChips(a1) << "\n";

    std::vector<int> a2 = {2, 2, 2, 3, 3};
    std::cout << "[2,2,2,3,3] -> " << minCostToMoveChips(a2) << "\n";

    std::vector<int> a3 = {1, 1000000000};
    std::cout << "[1,1000000000] -> " << minCostToMoveChips(a3) << "\n";
}
