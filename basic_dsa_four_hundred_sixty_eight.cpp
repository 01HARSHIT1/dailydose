/**
 * Basic DSA - Find Closest Number to Zero (LeetCode 2239)
 * Minimize absolute value; tie-break by choosing the larger integer.
 */
#include <cstdlib>
#include <iostream>
#include <vector>

int findClosestNumber(std::vector<int>& nums) {
    int best = nums[0];
    for (int x : nums) {
        int ax = std::abs(x);
        int ab = std::abs(best);
        if (ax < ab || (ax == ab && x > best))
            best = x;
    }
    return best;
}

void printVec(const std::vector<int>& v) {
    std::cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        if (i)
            std::cout << ", ";
        std::cout << v[i];
    }
    std::cout << "]";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Closest Number to Zero\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {-4, -2, 1, 4, 8};
    printVec(a1);
    std::cout << " -> " << findClosestNumber(a1) << "\n";

    std::vector<int> a2 = {2, -1, -1};
    printVec(a2);
    std::cout << " -> " << findClosestNumber(a2) << "\n";
}
