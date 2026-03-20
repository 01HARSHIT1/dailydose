/**
 * Basic DSA - Excel Sheet Column Title (LeetCode 168)
 * Convert 1-based column number to Excel title (A, B, ..., Z, AA, ...).
 */
#include <iostream>
#include <string>
#include <algorithm>

std::string convertToTitle(int columnNumber) {
    std::string s;
    while (columnNumber > 0) {
        columnNumber--;
        s.push_back('A' + (columnNumber % 26));
        columnNumber /= 26;
    }
    std::reverse(s.begin(), s.end());
    return s;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Excel Sheet Column Title\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "1 -> " << convertToTitle(1) << "\n";
    std::cout << "28 -> " << convertToTitle(28) << "\n";
    std::cout << "701 -> " << convertToTitle(701) << "\n";
}
