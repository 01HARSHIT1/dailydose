/**
 * Basic DSA - Pass the Pillow (LeetCode 2582)
 * One full sweep takes n-1 seconds; direction flips each sweep. Use modulo to find position.
 */
#include <iostream>

int passThePillow(int n, int time) {
    int rounds = time / (n - 1);
    int remainder = time % (n - 1);
    return (rounds % 2 == 0) ? (1 + remainder) : (n - remainder);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Pass the Pillow\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << passThePillow(4, 5) << "\n";
    std::cout << "sample 2 -> " << passThePillow(3, 2) << "\n";
}
