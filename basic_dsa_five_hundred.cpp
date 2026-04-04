/**
 * Basic DSA - Reverse String (LeetCode 344)
 * Reverse the array of characters in-place with O(1) extra memory.
 */
#include <iostream>
#include <string>
#include <utility>

void reverseString(std::string& s) {
    size_t i = 0;
    size_t j = s.size();
    if (j == 0)
        return;
    --j;
    while (i < j)
        std::swap(s[i++], s[j--]);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Reverse String\n";
    std::cout << std::string(60, '=') << "\n";

    std::string a = "hello";
    std::cout << a << " -> ";
    reverseString(a);
    std::cout << a << "\n";

    std::string b = "Hannah";
    std::cout << b << " -> ";
    reverseString(b);
    std::cout << b << "\n";
}
