/**
 * Basic DSA - Number of Good Pairs (LeetCode 1512)
 * Count pairs (i,j) where i<j and nums[i]==nums[j].
 */
#include <iostream>
#include <vector>
#include <unordered_map>

int numIdenticalPairs(std::vector<int>& nums) {
    std::unordered_map<int, int> count;
    int pairs = 0;
    for (int x : nums) {
        pairs += count[x];
        count[x]++;
    }
    return pairs;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Number of Good Pairs\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 2, 3, 1, 1, 3};
    std::cout << "[1,2,3,1,1,3] -> " << numIdenticalPairs(a1) << "\n";

    std::vector<int> a2 = {1, 1, 1, 1};
    std::cout << "[1,1,1,1] -> " << numIdenticalPairs(a2) << "\n";

    std::vector<int> a3 = {1, 2, 3};
    std::cout << "[1,2,3] -> " << numIdenticalPairs(a3) << "\n";
}
