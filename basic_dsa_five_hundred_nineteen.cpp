/**
 * Basic DSA - Majority Element (LeetCode 169)
 * One value appears strictly more than n/2 times; find it with Boyer-Moore voting.
 * Time: O(n), Space: O(1).
 */
#include <iostream>
#include <vector>

int majorityElement(const std::vector<int>& nums) {
    int cand = 0;
    int cnt = 0;
    for (int x : nums) {
        if (cnt == 0) {
            cand = x;
            cnt = 1;
        } else if (x == cand) {
            ++cnt;
        } else {
            --cnt;
        }
    }
    return cand;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Majority Element\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "[3,2,3] -> " << majorityElement({3, 2, 3}) << "\n";
    std::cout << "[2,2,1,1,1,2,2] -> " << majorityElement({2, 2, 1, 1, 1, 2, 2}) << "\n";
    std::cout << "[1] -> " << majorityElement({1}) << "\n";
}
