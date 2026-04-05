/**
 * Basic DSA - Happy Number (LeetCode 202)
 * Repeatedly replace n by the sum of the squares of its digits. If you reach 1, n is
 * happy; otherwise the sequence cycles without hitting 1.
 * Time: O(log n) per step (digit count), Space: O(number of visited values).
 */
#include <iostream>
#include <unordered_set>

int sumDigitSquares(int n) {
    int s = 0;
    while (n > 0) {
        int d = n % 10;
        s += d * d;
        n /= 10;
    }
    return s;
}

bool isHappy(int n) {
    std::unordered_set<int> seen;
    while (n != 1 && seen.insert(n).second)
        n = sumDigitSquares(n);
    return n == 1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Happy Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "n=19 -> " << (isHappy(19) ? "true" : "false") << "\n";
    std::cout << "n=2 -> " << (isHappy(2) ? "true" : "false") << "\n";
    std::cout << "n=1 -> " << (isHappy(1) ? "true" : "false") << "\n";
}
