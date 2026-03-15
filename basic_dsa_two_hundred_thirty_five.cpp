/**
 * Basic DSA - Flipping an Image (LeetCode 832)
 * Flip image horizontally, then invert (0->1, 1->0).
 */
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> flipAndInvertImage(std::vector<std::vector<int>>& image) {
    for (auto& row : image) {
        std::reverse(row.begin(), row.end());
        for (int& x : row) x ^= 1;
    }
    return image;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Flipping an Image\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::vector<int>> m1 = {{1,1,0},{1,0,1},{0,0,0}};
    flipAndInvertImage(m1);
    std::cout << "[[1,1,0],[1,0,1],[0,0,0]] -> ";
    for (const auto& r : m1) { std::cout << "["; for (int x : r) std::cout << x; std::cout << "] "; }
    std::cout << "\n";

    std::vector<std::vector<int>> m2 = {{1,1,0,0},{1,0,0,1},{0,1,1,1},{1,0,1,0}};
    flipAndInvertImage(m2);
    std::cout << "4x4 flipped and inverted\n";
}
