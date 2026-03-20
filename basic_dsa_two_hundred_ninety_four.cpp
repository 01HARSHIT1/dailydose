/**
 * Basic DSA - Add Strings (LeetCode 415)
 * Return sum of two non-negative integer strings without built-in BigInt.
 */
#include <iostream>
#include <string>
#include <algorithm>

std::string addStrings(std::string num1, std::string num2) {
    std::string ans;
    int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
    while (i >= 0 || j >= 0 || carry) {
        int d1 = i >= 0 ? num1[i--] - '0' : 0;
        int d2 = j >= 0 ? num2[j--] - '0' : 0;
        int s = d1 + d2 + carry;
        ans.push_back('0' + (s % 10));
        carry = s / 10;
    }
    std::reverse(ans.begin(), ans.end());
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Add Strings\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "11 + 123 -> " << addStrings("11", "123") << "\n";
    std::cout << "456 + 77 -> " << addStrings("456", "77") << "\n";
    std::cout << "0 + 0 -> " << addStrings("0", "0") << "\n";
}
