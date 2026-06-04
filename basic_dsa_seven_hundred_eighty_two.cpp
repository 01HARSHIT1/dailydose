/**
 * Basic DSA - Number of Unique XOR Triplets II (LeetCode 3514)
 * Enumerate pair XORs, combine with each value, and count distinct triplet XORs.
 */

#include <iostream>
#include <unordered_set>
#include <vector>

int uniqueXorTriplets(const std::vector<int>& values) {
    const int count = static_cast<int>(values.size());
    if (count == 1)
        return 1;

    std::unordered_set<int> pairXors;
    for (int left = 0; left < count; ++left) {
        for (int right = left + 1; right < count; ++right)
            pairXors.insert(values[left] ^ values[right]);
    }

    std::unordered_set<int> tripletXors;
    for (const int pairXor : pairXors) {
        for (const int value : values)
            tripletXors.insert(pairXor ^ value);
    }

    return static_cast<int>(tripletXors.size());
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Number of Unique XOR Triplets II\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << uniqueXorTriplets({1, 3}) << "\n";
    std::cout << "sample 2 -> " << uniqueXorTriplets({6, 7, 8, 9}) << "\n";
}
