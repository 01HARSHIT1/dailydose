/**
 * Basic DSA - N-Repeated Element in Size 2N Array (LeetCode 961)
 * Exactly one integer appears N times; the rest appear once. Array length is 2N.
 */
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int repeatedNTimes(std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int x : nums) {
        if (seen.count(x))
            return x;
        seen.insert(x);
    }
    return -1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: N-Repeated Element in Size 2N Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 2, 3, 3};
    std::cout << "[1,2,3,3] -> " << repeatedNTimes(v1) << "\n";

    std::vector<int> v2 = {2, 1, 2, 5, 3, 2};
    std::cout << "[2,1,2,5,3,2] -> " << repeatedNTimes(v2) << "\n";
}
