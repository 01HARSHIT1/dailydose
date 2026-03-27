/**
 * Basic DSA - Greatest Common Divisor of Strings (LeetCode 1071)
 * Largest string x such that str1 and str2 are concatenations of copies of x.
 */
#include <iostream>
#include <string>

static int gcd_len(int a, int b) {
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

std::string gcdOfStrings(const std::string& str1, const std::string& str2) {
    if (str1 + str2 != str2 + str1)
        return "";
    int g = gcd_len(static_cast<int>(str1.size()), static_cast<int>(str2.size()));
    return str1.substr(0, static_cast<std::size_t>(g));
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Greatest Common Divisor of Strings\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "ABCABC, ABC -> " << gcdOfStrings("ABCABC", "ABC") << "\n";
    std::cout << "ABABAB, ABAB -> " << gcdOfStrings("ABABAB", "ABAB") << "\n";
    std::cout << "LEET, CODE -> \"" << gcdOfStrings("LEET", "CODE") << "\"\n";
}
