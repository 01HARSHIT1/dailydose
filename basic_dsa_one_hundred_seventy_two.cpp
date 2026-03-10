/**
 * Basic DSA - Reverse String (LeetCode 344)
 * Reverse a string in-place.
 */
#include <iostream>
#include <string>
#include <algorithm>

void reverseString(std::string& s) {
    int i = 0, j = (int)s.size() - 1;
    while (i < j) std::swap(s[i++], s[j--]);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Reverse String\n";
    std::cout << std::string(60, '=') << "\n";

    std::string a1 = "hello";
    reverseString(a1);
    std::cout << "hello -> " << a1 << "\n";

    std::string a2 = "Hannah";
    reverseString(a2);
    std::cout << "Hannah -> " << a2 << "\n";

    std::string a3 = "a";
    reverseString(a3);
    std::cout << "a -> " << a3 << "\n";
}
