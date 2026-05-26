/**
 * Basic DSA - Check Balanced String (LeetCode 3340)
 * A string is balanced if the sum of digits at even indices equals the sum at odd indices.
 */
#include <iostream>
#include <string>

bool isBalanced(const std::string& num) {
    int even = 0;
    int odd = 0;
    for (size_t i = 0; i < num.size(); ++i) {
        int digit = num[i] - '0';
        if (i % 2 == 0)
            even += digit;
        else
            odd += digit;
    }
    return even == odd;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Check Balanced String\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> " << isBalanced("1234") << "\n";
    std::cout << "sample 2 -> " << isBalanced("24123") << "\n";
}
