/**
 * Basic DSA - Check if Strings Can be Made Equal With Operations I (LeetCode 2839)
 * Swaps connect even indices together and odd indices together; the two parity multisets must match.
 */
#include <algorithm>
#include <iostream>
#include <string>

bool canBeEqual(const std::string& s1, const std::string& s2) {
    std::string evenA, oddA, evenB, oddB;
    for (size_t i = 0; i < 4; ++i) {
        if (i % 2 == 0) {
            evenA += s1[i];
            evenB += s2[i];
        } else {
            oddA += s1[i];
            oddB += s2[i];
        }
    }
    std::sort(evenA.begin(), evenA.end());
    std::sort(evenB.begin(), evenB.end());
    std::sort(oddA.begin(), oddA.end());
    std::sort(oddB.begin(), oddB.end());
    return evenA == evenB && oddA == oddB;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Check if Strings Can be Made Equal With Operations I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> " << canBeEqual("abcd", "cdab") << "\n";
    std::cout << "sample 2 -> " << canBeEqual("abcd", "dacb") << "\n";
}
