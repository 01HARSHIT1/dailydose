/**
 * Basic DSA - Alternating Digit Sum (LeetCode 2544)
 * Sum digits of n from most to least significant, alternating signs starting with +.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int alternateDigitSum(int n) {
    std::vector<int> digits;
    while (n > 0) {
        digits.push_back(n % 10);
        n /= 10;
    }
    std::reverse(digits.begin(), digits.end());
    int sum = 0, sign = 1;
    for (int d : digits) {
        sum += sign * d;
        sign = -sign;
    }
    return sum;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Alternating Digit Sum\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "521 -> " << alternateDigitSum(521) << "\n";
    std::cout << "111 -> " << alternateDigitSum(111) << "\n";
    std::cout << "886996 -> " << alternateDigitSum(886996) << "\n";
}
