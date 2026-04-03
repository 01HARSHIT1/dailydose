/**
 * Basic DSA - Happy Number (LeetCode 202)
 * Replace n by sum of squares of its digits; happy iff process eventually reaches 1.
 * Floyd cycle: slow = one step, fast = two steps on the digit-square map.
 */
#include <iostream>

int sumSquareDigits(int n) {
    int s = 0;
    while (n > 0) {
        int d = n % 10;
        s += d * d;
        n /= 10;
    }
    return s;
}

bool isHappy(int n) {
    int slow = n;
    int fast = n;
    do {
        slow = sumSquareDigits(slow);
        fast = sumSquareDigits(sumSquareDigits(fast));
    } while (slow != fast);
    return slow == 1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Happy Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "19 -> " << isHappy(19) << "\n";
    std::cout << "2 -> " << isHappy(2) << "\n";
}
