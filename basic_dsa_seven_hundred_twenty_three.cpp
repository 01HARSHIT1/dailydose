/**
 * Basic DSA - Most Frequent Even Element (LeetCode 3092)
 * Return the most frequent even integer; on tie return the smallest. -1 if none.
 */

#include <iostream>
#include <unordered_map>
#include <vector>

int mostFrequentEven(const std::vector<int>& nums) {
    std::unordered_map<int, int> freq;
    int bestVal = -1;
    int bestFreq = 0;

    for (int x : nums) {
        if (x % 2 != 0)
            continue;
        int f = ++freq[x];
        if (f > bestFreq || (f == bestFreq && x < bestVal)) {
            bestFreq = f;
            bestVal = x;
        }
    }
    return bestVal;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Most Frequent Even Element\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << mostFrequentEven({0, 1, 2, 2}) << "\n";
    std::cout << "sample 2 -> " << mostFrequentEven({2, 2, 0, 0, 0}) << "\n";
    std::cout << "sample 3 -> " << mostFrequentEven({1, 3, 5, 7, 9}) << "\n";
}
