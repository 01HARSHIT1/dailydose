/**
 * Basic DSA - Number of Unique XOR Triplets I (LeetCode 3513)
 * Permutation of 1..n yields 2^(floor(log2(n)) + 1) distinct XOR triplets when n >= 3.
 */

#include <cmath>
#include <iostream>
#include <vector>

int uniqueXorTriplets(const std::vector<int>& values) {
    const int size = static_cast<int>(values.size());

    if (size < 3)
        return size;

    return 1 << (static_cast<int>(std::log2(size)) + 1);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Number of Unique XOR Triplets I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << uniqueXorTriplets({1, 2}) << "\n";
    std::cout << "sample 2 -> " << uniqueXorTriplets({3, 1, 2}) << "\n";
}
