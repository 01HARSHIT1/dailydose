/**
 * Basic DSA - Stone Removal Game (LeetCode 3360)
 * Turns remove 10, 9, 8, ... stones; Alice wins if an odd number of moves are made.
 */
#include <iostream>

bool canAliceWin(int n) {
    int remove = 10;
    int moves = 0;
    while (remove > 0 && n >= remove) {
        n -= remove;
        --remove;
        ++moves;
    }
    return moves % 2 == 1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Stone Removal Game\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> " << canAliceWin(12) << "\n";
    std::cout << "sample 2 -> " << canAliceWin(1) << "\n";
    std::cout << "sample 3 -> " << canAliceWin(19) << "\n";
}
