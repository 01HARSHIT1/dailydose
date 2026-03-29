/**
 * Basic DSA - Number of Steps to Reduce a Number to Zero (LeetCode 1342)
 * If even divide by 2; if odd subtract 1. Count steps until zero.
 */
#include <iostream>
#include <string>

int numberOfSteps(int num) {
    int s = 0;
    while (num != 0) {
        if (num % 2 == 1)
            --num;
        else
            num /= 2;
        ++s;
    }
    return s;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Number of Steps to Reduce a Number to Zero\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "n=14 -> " << numberOfSteps(14) << "\n";
    std::cout << "n=8 -> " << numberOfSteps(8) << "\n";
}
