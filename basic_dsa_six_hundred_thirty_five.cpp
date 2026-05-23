/**
 * Basic DSA - Number of Even and Odd Bits (LeetCode 2595)
 * Walk the bits; count set bits at even indices and at odd indices separately.
 */
#include <iostream>
#include <vector>

std::vector<int> evenOddBit(int n) {
    int even = 0;
    int odd = 0;
    int index = 0;
    while (n > 0) {
        if (n & 1) {
            if (index % 2 == 0)
                ++even;
            else
                ++odd;
        }
        n >>= 1;
        ++index;
    }
    return {even, odd};
}

void printVec(const std::vector<int>& v) {
    std::cout << "[" << v[0] << "," << v[1] << "]\n";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Number of Even and Odd Bits\n";
    std::cout << std::string(60, '=') << "\n";

    printVec(evenOddBit(17));
    printVec(evenOddBit(2));
}
