/**
 * Basic DSA - Palindrome Number (LeetCode 9)
 * Check if integer is a palindrome without converting to string.
 */
#include <iostream>

bool isPalindrome(int x) {
    if (x < 0 || (x != 0 && x % 10 == 0)) return false;
    int half = 0;
    while (x > half) {
        half = half * 10 + x % 10;
        x /= 10;
    }
    return x == half || x == half / 10;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Palindrome Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "121 -> " << (isPalindrome(121) ? "true" : "false") << "\n";
    std::cout << "-121 -> " << (isPalindrome(-121) ? "true" : "false") << "\n";
    std::cout << "10 -> " << (isPalindrome(10) ? "true" : "false") << "\n";
    std::cout << "0 -> " << (isPalindrome(0) ? "true" : "false") << "\n";
}
