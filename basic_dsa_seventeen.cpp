/**
 * Basic DSA - Reverse String (LeetCode 344)
 * Reverse a char array in-place.
 */
#include <iostream>
#include <vector>
#include <algorithm>

void reverseString(std::vector<char>& s) {
    int i = 0, j = (int)s.size() - 1;
    while (i < j) {
        std::swap(s[i], s[j]);
        i++;
        j--;
    }
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Reverse String\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<char> a1 = {'h', 'e', 'l', 'l', 'o'};
    reverseString(a1);
    std::cout << "hello -> ";
    for (char c : a1) std::cout << c;
    std::cout << "\n";

    std::vector<char> a2 = {'H', 'a', 'n', 'n', 'a', 'h'};
    reverseString(a2);
    std::cout << "Hannah -> ";
    for (char c : a2) std::cout << c;
    std::cout << "\n";
}
