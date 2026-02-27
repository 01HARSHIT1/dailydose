/**
 * Basic DSA - Majority Element (LeetCode 169)
 * Find element appearing more than n/2 times.
 */
#include <iostream>
#include <vector>

int majorityElement(std::vector<int>& nums) {
    int cand = nums[0], count = 1;
    for (size_t i = 1; i < nums.size(); i++) {
        if (count == 0) cand = nums[i];
        count += (nums[i] == cand) ? 1 : -1;
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
}
