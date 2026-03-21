/**
 * Basic DSA - Contains Duplicate (LeetCode 217)
 * Return true if any value appears at least twice.
 */
#include <iostream>
#include <vector>
#include <unordered_set>

bool containsDuplicate(std::vector<int>& nums) {
    std::unordered_set<int> s;
    for (int x : nums) {
        if (s.count(x)) return true;
        s.insert(x);
    }
    return false;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Contains Duplicate\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 2, 3, 1};
    std::cout << "[1,2,3,1] -> " << (containsDuplicate(v1) ? "true" : "false") << "\n";

    std::vector<int> v2 = {1, 2, 3, 4};
    std::cout << "[1,2,3,4] -> " << (containsDuplicate(v2) ? "true" : "false") << "\n";

    std::vector<int> v3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
    std::cout << "[1,1,1,3,3,4,3,2,4,2] -> " << (containsDuplicate(v3) ? "true" : "false") << "\n";
}
