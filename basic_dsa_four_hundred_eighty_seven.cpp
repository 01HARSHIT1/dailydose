/**
 * Basic DSA - Contains Duplicate (LeetCode 217)
 * Return true if any value appears at least twice in the array.
 */
#include <iostream>
#include <unordered_set>
#include <vector>

bool containsDuplicate(const std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int x : nums) {
        if (!seen.insert(x).second)
            return true;
    }
    return false;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Contains Duplicate\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "[1,2,3,1] -> " << containsDuplicate({1, 2, 3, 1}) << "\n";
    std::cout << "[1,2,3,4] -> " << containsDuplicate({1, 2, 3, 4}) << "\n";
    std::cout << "[1,1,1,3,3,4,3,2,4,2] -> "
              << containsDuplicate({1, 1, 1, 3, 3, 4, 3, 2, 4, 2}) << "\n";
}
