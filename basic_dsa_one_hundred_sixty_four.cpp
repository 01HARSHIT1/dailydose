/**
 * Basic DSA - Majority Element (LeetCode 169)
 * Find element that appears more than n/2 times (Boyer-Moore voting).
 */
#include <iostream>
#include <vector>

int majorityElement(std::vector<int>& nums) {
    int cand = 0, count = 0;
    for (int x : nums) {
        if (count == 0) cand = x;
        count += (x == cand) ? 1 : -1;
    }
    return cand;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Majority Element\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {3, 2, 3};
    std::cout << "[3,2,3] -> " << majorityElement(a1) << "\n";

    std::vector<int> a2 = {2, 2, 1, 1, 1, 2, 2};
    std::cout << "[2,2,1,1,1,2,2] -> " << majorityElement(a2) << "\n";

    std::vector<int> a3 = {6, 5, 5};
    std::cout << "[6,5,5] -> " << majorityElement(a3) << "\n";
}
