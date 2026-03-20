/**
 * Basic DSA - Integer to Roman (LeetCode 12)
 * Convert integer 1..3999 to Roman numeral.
 */
#include <iostream>
#include <string>
#include <vector>

std::string intToRoman(int num) {
    std::vector<std::pair<int, std::string>> v = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    std::string ans;
    for (auto& p : v) {
        while (num >= p.first) {
            ans += p.second;
            num -= p.first;
        }
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Integer to Roman\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "3 -> " << intToRoman(3) << "\n";
    std::cout << "58 -> " << intToRoman(58) << "\n";
    std::cout << "1994 -> " << intToRoman(1994) << "\n";
}
