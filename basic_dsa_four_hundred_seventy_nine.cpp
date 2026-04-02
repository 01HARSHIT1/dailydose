/**
 * Basic DSA - Number of Steps to Reduce a Number to Zero (LeetCode 1342)
 * If even, divide by 2; if odd, subtract 1. Count steps until the value is 0.
 */
#include <iostream>

int numberOfSteps(int num) {
    int steps = 0;
    while (num > 0) {
        if (num % 2 == 0)
            num /= 2;
        else
            --num;
        ++steps;
    }
    return steps;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Number of Steps to Reduce a Number to Zero\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "14 -> " << numberOfSteps(14) << "\n";
    std::cout << "8 -> " << numberOfSteps(8) << "\n";
    std::cout << "123 -> " << numberOfSteps(123) << "\n";
}
