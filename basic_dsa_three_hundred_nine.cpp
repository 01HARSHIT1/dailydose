/**
 * Basic DSA - Sum of Two Integers (LeetCode 371)
 * Return a + b without using + or -.
 */
#include <iostream>

int getSum(int a, int b) {
    while (b != 0) {
        unsigned carry = (unsigned)(a & b) << 1;
        a ^= b;
        b = (int)carry;
    }
    return a;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sum of Two Integers\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "1 + 2 -> " << getSum(1, 2) << "\n";
    std::cout << "2 + 3 -> " << getSum(2, 3) << "\n";
}
