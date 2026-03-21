/**
 * Basic DSA - Happy Number (LeetCode 202)
 * Return true if repeated sum of squares of digits reaches 1.
 */
#include <iostream>
#include <unordered_set>

int step(int n) {
    int s = 0;
    while (n) {
        int d = n % 10;
        s += d * d;
        n /= 10;
    }
    return s;
}

bool isHappy(int n) {
    std::unordered_set<int> seen;
    while (n != 1 && !seen.count(n)) {
        seen.insert(n);
        n = step(n);
    }
    return n == 1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Happy Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "19 -> " << (isHappy(19) ? "true" : "false") << "\n";
    std::cout << "2 -> " << (isHappy(2) ? "true" : "false") << "\n";
}
