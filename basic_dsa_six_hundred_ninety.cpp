/**
 * Basic DSA - Find the K-th Character in String Game I (LeetCode 3304)
 * The k-th character equals 'a' plus the number of set bits in (k - 1).
 */
#include <iostream>

int popcount(int x) {
    int count = 0;
    while (x > 0) {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

char kthCharacter(int k) {
    return static_cast<char>('a' + popcount(k - 1));
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the K-th Character in String Game I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << kthCharacter(5) << "\n";
    std::cout << "sample 2 -> " << kthCharacter(10) << "\n";
    std::cout << "sample 3 -> " << kthCharacter(1) << "\n";
}
