/**
 * Basic DSA - Happy Number (LeetCode 202)
 * Determine if n is happy (sum of squares of digits eventually reaches 1).
 */
#include <iostream>
#include <unordered_set>

int digitSquareSum(int n) {
    int sum = 0;
    while (n) {
        int d = n % 10;
        sum += d * d;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    std::unordered_set<int> seen;
    while (n != 1 && !seen.count(n)) {
        seen.insert(n);
        n = digitSquareSum(n);
    }
    return n == 1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Happy Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "19 -> " << (isHappy(19) ? "true" : "false") << "\n";
    std::cout << "2 -> " << (isHappy(2) ? "true" : "false") << "\n";
    std::cout << "7 -> " << (isHappy(7) ? "true" : "false") << "\n";
}
