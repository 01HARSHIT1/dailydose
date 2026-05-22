/**
 * Basic DSA - Maximum Difference by Remapping a Digit (LeetCode 2566)
 * Max: replace first non-9 digit with 9 everywhere. Min: replace first digit with 0 everywhere.
 */
#include <iostream>
#include <string>

int minMaxDifference(int num) {
    std::string s = std::to_string(num);

    std::string high = s;
    char toNine = '\0';
    for (char ch : high) {
        if (ch != '9') {
            toNine = ch;
            break;
        }
    }
    if (toNine != '\0') {
        for (char& ch : high)
            if (ch == toNine)
                ch = '9';
    }

    std::string low = s;
    char toZero = low[0];
    for (char& ch : low)
        if (ch == toZero)
            ch = '0';

    return std::stoi(high) - std::stoi(low);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Difference by Remapping a Digit\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minMaxDifference(11891) << "\n";
    std::cout << "sample 2 -> " << minMaxDifference(90) << "\n";
}
