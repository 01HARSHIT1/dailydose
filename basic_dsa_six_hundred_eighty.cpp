/**
 * Basic DSA - Find the Winning Player in Coin Game (LeetCode 3222)
 * Each turn costs 75 (one 75-coin) or 10x ten-coins; total rounds = min(x, y/4); winner by parity.
 */
#include <algorithm>
#include <iostream>
#include <string>

std::string losingPlayer(int x, int y) {
    int rounds = std::min(x, y / 4);
    return (rounds % 2 == 1) ? "Alice" : "Bob";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Winning Player in Coin Game\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << losingPlayer(2, 7) << "\n";
    std::cout << "sample 2 -> " << losingPlayer(4, 11) << "\n";
}
