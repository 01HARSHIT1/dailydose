/**
 * Basic DSA - Contains Duplicate (LeetCode 217)
 * Check if array contains any duplicate element.
 */
#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> seen;
    for (int x : nums) {
        if (seen.count(x)) return true;
        seen.insert(x);
    }
    return false;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Contains Duplicate\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 3, 1};
    std::cout << "[1,2,3,1] -> " << (containsDuplicate(a1) ? "true" : "false") << "\n";

    std::vector<int> a2 = {1, 2, 3, 4};
    std::cout << "[1,2,3,4] -> " << (containsDuplicate(a2) ? "true" : "false") << "\n";

    std::vector<int> a3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    std::cout << "[1,1,1,3,3,4,3,2,4,2] -> " << (containsDuplicate(a3) ? "true" : "false") << "\n";
}
