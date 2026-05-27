/**
 * Basic DSA - Check if Two Chessboard Squares Have the Same Color (LeetCode 3274)
 * Squares share color when (file + rank) parity matches on a standard chessboard.
 */
#include <iostream>
#include <string>

bool checkTwoChessboards(const std::string& coordinate1, const std::string& coordinate2) {
    auto color = [](const std::string& c) {
        return (c[0] - 'a' + c[1] - '1') % 2;
    };
    return color(coordinate1) == color(coordinate2);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Check if Two Chessboard Squares Have the Same Color\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> " << checkTwoChessboards("a1", "c3") << "\n";
    std::cout << "sample 2 -> " << checkTwoChessboards("a1", "h3") << "\n";
}
