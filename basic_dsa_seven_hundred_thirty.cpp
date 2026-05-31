/**
 * Basic DSA - Check If Digits Are Equal in String After Operations I (LeetCode 3461)
 * Repeatedly sum adjacent digits mod 10 until two digits remain; check if equal.
 */

#include <iostream>
#include <string>

bool hasSameDigits(std::string s) {
    const int n = static_cast<int>(s.size());

    for (int k = n - 1; k > 1; --k) {
        for (int i = 0; i < k; ++i)
            s[i] = static_cast<char>((s[i] - '0' + s[i + 1] - '0') % 10 + '0');
    }
    return s[0] == s[1];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Check If Digits Are Equal in String After Operations I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> " << hasSameDigits("3902") << "\n";
    std::cout << "sample 2 -> " << hasSameDigits("34789") << "\n";
}
