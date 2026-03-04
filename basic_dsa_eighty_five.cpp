/**
 * Basic DSA - Gas Station (LeetCode 134)
 * Find starting index to complete circular route; gas[i]=fuel, cost[i]=cost to next.
 */
#include <iostream>
#include <vector>

int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
    int total = 0, tank = 0, start = 0;
    for (int i = 0; i < (int)gas.size(); i++) {
        total += gas[i] - cost[i];
        tank += gas[i] - cost[i];
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }
    return total >= 0 ? start : -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Gas Station\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> g1 = {1, 2, 3, 4, 5};
    std::vector<int> c1 = {3, 4, 5, 1, 2};
    std::cout << "gas=[1,2,3,4,5], cost=[3,4,5,1,2] -> " << canCompleteCircuit(g1, c1) << "\n";

    std::vector<int> g2 = {2, 3, 4};
    std::vector<int> c2 = {3, 4, 3};
    std::cout << "gas=[2,3,4], cost=[3,4,3] -> " << canCompleteCircuit(g2, c2) << "\n";

    std::vector<int> g3 = {5, 1, 2, 3, 4};
    std::vector<int> c3 = {4, 4, 1, 5, 1};
    std::cout << "gas=[5,1,2,3,4], cost=[4,4,1,5,1] -> " << canCompleteCircuit(g3, c3) << "\n";
}
