/**
 * Basic DSA - Generate a String With Characters That Have Odd Counts (LeetCode 1374)
 * Length n; every letter that appears must occur an odd number of times.
 */
#include <iostream>
#include <string>

std::string generateTheString(int n) {
    if (n % 2 == 1)
        return std::string(static_cast<size_t>(n), 'a');
    return std::string(static_cast<size_t>(n - 1), 'a') + 'b';
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Generate a String With Characters That Have Odd Counts\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "n=4 -> " << generateTheString(4) << "\n";
    std::cout << "n=7 -> " << generateTheString(7) << "\n";
}
