/**
 * Basic DSA - Find Numbers with Even Number of Digits (LeetCode 1295)
 * Count elements whose decimal representation has an even number of digits.
 */
#include <iostream>
#include <string>
#include <vector>

static int numDigits(int x) {
    int d = 0;
    do {
        x /= 10;
        ++d;
    } while (x > 0);
    return d;
}

int findNumbers(const std::vector<int>& nums) {
    int c = 0;
    for (int x : nums) {
        if (numDigits(x) % 2 == 0)
            ++c;
    }
    return c;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Numbers with Even Number of Digits\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {12, 345, 2, 6, 7896};
    std::cout << "[12,345,2,6,7896] -> " << findNumbers(v1) << "\n";

    std::vector<int> v2 = {555, 901, 482, 1771};
    std::cout << "[555,901,482,1771] -> " << findNumbers(v2) << "\n";
}
