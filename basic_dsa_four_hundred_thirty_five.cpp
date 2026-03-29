/**
 * Basic DSA - Thousand Separator (LeetCode 1556)
 * Insert '.' between groups of three digits from the right (no leading dot).
 */
#include <iostream>
#include <string>

std::string thousandSeparator(int n) {
    std::string s = std::to_string(n);
    std::string t;
    const int len = static_cast<int>(s.size());
    for (int i = 0; i < len; ++i) {
        if (i > 0 && (len - i) % 3 == 0)
            t += '.';
        t += s[static_cast<size_t>(i)];
    }
    return t;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Thousand Separator\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "987 -> " << thousandSeparator(987) << "\n";
    std::cout << "123456789 -> " << thousandSeparator(123456789) << "\n";
}
