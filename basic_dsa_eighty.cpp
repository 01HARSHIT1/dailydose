/**
 * Basic DSA - Hamming Distance (LeetCode 461)
 * Number of positions where bits differ between x and y.
 */
#include <iostream>
#include <cstdint>

int hammingDistance(int x, int y) {
    int d = x ^ y, count = 0;
    while (d) {
        count += d & 1;
        d >>= 1;
    }
    return count;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Hamming Distance\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "1, 4 -> " << hammingDistance(1, 4) << "\n";
    std::cout << "3, 1 -> " << hammingDistance(3, 1) << "\n";
    std::cout << "0, 15 -> " << hammingDistance(0, 15) << "\n";
}
