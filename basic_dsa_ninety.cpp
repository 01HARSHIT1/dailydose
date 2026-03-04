/**
 * Basic DSA - Maximum 69 Number (LeetCode 1323)
 * Change at most one digit (6->9) to get maximum number.
 */
#include <iostream>
#include <string>

int maximum69Number(int num) {
    std::string s = std::to_string(num);
    for (char& c : s) {
        if (c == '6') { c = '9'; break; }
    }
    return std::stoi(s);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum 69 Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "9669 -> " << maximum69Number(9669) << "\n";
    std::cout << "9996 -> " << maximum69Number(9996) << "\n";
    std::cout << "9999 -> " << maximum69Number(9999) << "\n";
}
