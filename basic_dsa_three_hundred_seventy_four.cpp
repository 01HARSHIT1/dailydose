/**
 * Basic DSA - Distribute Candies (LeetCode 575)
 * n is even; each sibling gets n/2 candies; maximize number of different kinds.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

int distributeCandies(std::vector<int>& candyType) {
    std::unordered_set<int> kinds(candyType.begin(), candyType.end());
    int n = static_cast<int>(candyType.size());
    return std::min(static_cast<int>(kinds.size()), n / 2);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Distribute Candies\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 1, 2, 2, 3, 3};
    std::cout << "[1,1,2,2,3,3] -> " << distributeCandies(v1) << "\n";

    std::vector<int> v2 = {1, 1, 2, 3};
    std::cout << "[1,1,2,3] -> " << distributeCandies(v2) << "\n";
}
