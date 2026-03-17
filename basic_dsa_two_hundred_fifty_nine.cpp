/**
 * Basic DSA - Can Place Flowers (LeetCode 605)
 * Return true if n new flowers can be planted without adjacent rule violation.
 */
#include <iostream>
#include <vector>

bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
    for (int i = 0; i < (int)flowerbed.size() && n > 0; i++) {
        if (flowerbed[i] == 0 &&
            (i == 0 || flowerbed[i - 1] == 0) &&
            (i == (int)flowerbed.size() - 1 || flowerbed[i + 1] == 0)) {
            flowerbed[i] = 1;
            n--;
        }
    }
    return n == 0;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Can Place Flowers\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 0, 0, 0, 1};
    std::cout << "[1,0,0,0,1], 1 -> " << (canPlaceFlowers(v1, 1) ? "true" : "false") << "\n";

    std::vector<int> v2 = {1, 0, 0, 0, 1};
    std::cout << "[1,0,0,0,1], 2 -> " << (canPlaceFlowers(v2, 2) ? "true" : "false") << "\n";

    std::vector<int> v3 = {0, 0, 1, 0, 1};
    std::cout << "[0,0,1,0,1], 1 -> " << (canPlaceFlowers(v3, 1) ? "true" : "false") << "\n";
}
