/**
 * Basic DSA - Hamming Distance (LeetCode 461)
 * Count differing bits between two integers.
 */
#include <iostream>

int hammingDistance(int x, int y) {
    int z = x ^ y, cnt = 0;
    while (z) {
        cnt += z & 1;
        z >>= 1;
    }
    return cnt;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Hamming Distance\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "1, 4 -> " << hammingDistance(1, 4) << "\n";
    std::cout << "3, 1 -> " << hammingDistance(3, 1) << "\n";
}
