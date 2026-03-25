/**
 * Basic DSA - 1-bit and 2-bit Characters (LeetCode 717)
 * bits ends with 0; 0 is one-bit, 10 and 11 are two-bit. Is the last char one-bit?
 */
#include <iostream>
#include <string>
#include <vector>

bool isOneBitCharacter(std::vector<int>& bits) {
    int i = 0;
    int n = static_cast<int>(bits.size());
    while (i < n - 1) {
        if (bits[i] == 0)
            ++i;
        else
            i += 2;
    }
    return i == n - 1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: 1-bit and 2-bit Characters\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 0, 0};
    std::cout << "[1,0,0] -> " << (isOneBitCharacter(v1) ? "true" : "false") << "\n";

    std::vector<int> v2 = {1, 1, 1, 0};
    std::cout << "[1,1,1,0] -> " << (isOneBitCharacter(v2) ? "true" : "false") << "\n";
}
