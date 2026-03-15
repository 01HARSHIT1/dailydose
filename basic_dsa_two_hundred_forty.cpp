/**
 * Basic DSA - Fair Candy Swap (LeetCode 888)
 * Return values to swap so both arrays have equal sum.
 */
#include <iostream>
#include <vector>
#include <unordered_set>

std::vector<int> fairCandySwap(std::vector<int>& aliceSizes, std::vector<int>& bobSizes) {
    int sumA = 0, sumB = 0;
    for (int x : aliceSizes) sumA += x;
    for (int x : bobSizes) sumB += x;
    int diff = (sumA - sumB) / 2;
    std::unordered_set<int> setA(aliceSizes.begin(), aliceSizes.end());
    for (int b : bobSizes) {
        if (setA.count(b + diff)) return {b + diff, b};
    }
    return {};
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Fair Candy Swap\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> a1 = {1, 1}, b1 = {2, 2};
    auto r1 = fairCandySwap(a1, b1);
    std::cout << "[1,1], [2,2] -> [" << r1[0] << "," << r1[1] << "]\n";

    std::vector<int> a2 = {1, 2}, b2 = {2, 3};
    auto r2 = fairCandySwap(a2, b2);
    std::cout << "[1,2], [2,3] -> [" << r2[0] << "," << r2[1] << "]\n";

    std::vector<int> a3 = {2}, b3 = {1, 3};
    auto r3 = fairCandySwap(a3, b3);
    std::cout << "[2], [1,3] -> [" << r3[0] << "," << r3[1] << "]\n";
}
