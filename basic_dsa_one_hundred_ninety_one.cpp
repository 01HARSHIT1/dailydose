/**
 * Basic DSA - Nim Game (LeetCode 292)
 * Two players take 1-3 stones. You start. Can you always win with n stones?
 */
#include <iostream>

bool canWinNim(int n) {
    return n % 4 != 0;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Nim Game\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "4 -> " << (canWinNim(4) ? "true" : "false") << "\n";
    std::cout << "1 -> " << (canWinNim(1) ? "true" : "false") << "\n";
    std::cout << "2 -> " << (canWinNim(2) ? "true" : "false") << "\n";
}
