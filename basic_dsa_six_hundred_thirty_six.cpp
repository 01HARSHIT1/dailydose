/**
 * Basic DSA - K Items With the Maximum Sum (LeetCode 2600)
 * Take 1s first, then 0s, then forced -1s; the sum is k minus any leftover that must be -1.
 */
#include <algorithm>
#include <iostream>

int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
    int ones = std::min(numOnes, k);
    k -= ones;
    int zeros = std::min(numZeros, k);
    k -= zeros;
    int negatives = std::min(numNegOnes, k);
    return ones - negatives;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: K Items With the Maximum Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << kItemsWithMaximumSum(3, 2, 0, 2) << "\n";
    std::cout << "sample 2 -> " << kItemsWithMaximumSum(3, 2, 0, 4) << "\n";
}
