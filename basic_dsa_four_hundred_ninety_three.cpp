/**
 * Basic DSA - Majority Element (LeetCode 169)
 * Value that appears strictly more than n/2 times exists; find it (Boyer–Moore vote).
 */
#include <iostream>
#include <vector>

int majorityElement(const std::vector<int>& nums) {
    int cand = 0;
    int votes = 0;
    for (int x : nums) {
        if (votes == 0)
            cand = x;
        votes += (x == cand) ? 1 : -1;
    }
    return cand;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Majority Element\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[3,2,3] -> " << majorityElement({3, 2, 3}) << "\n";
    std::cout << "[2,2,1,1,1,2,2] -> " << majorityElement({2, 2, 1, 1, 1, 2, 2}) << "\n";
}
