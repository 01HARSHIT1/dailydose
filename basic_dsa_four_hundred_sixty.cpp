/**
 * Basic DSA - Minimum Sum of Four Digit Number After Splitting Digits (LeetCode 2160)
 * Split the four digits of num into two two-digit numbers; minimize their sum.
 */
#include <algorithm>
#include <iostream>
#include <vector>

int minimumSum(int num) {
    std::vector<int> d(4);
    int x = num;
    for (int i = 0; i < 4; ++i) {
        d[i] = x % 10;
        x /= 10;
    }
    std::sort(d.begin(), d.end());
    return 10 * (d[0] + d[1]) + d[2] + d[3];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Sum of Four Digit Number After Splitting Digits\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "2932 -> " << minimumSum(2932) << "\n";
    std::cout << "4006 -> " << minimumSum(4006) << "\n";
}
