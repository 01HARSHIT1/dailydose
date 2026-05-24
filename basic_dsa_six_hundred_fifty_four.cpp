/**
 * Basic DSA - Faulty Keyboard (LeetCode 2810)
 * Typing 'i' reverses the current text; build the result, reversing on each 'i'.
 */
#include <algorithm>
#include <iostream>
#include <string>

std::string finalString(const std::string& s) {
    std::string result;
    for (char ch : s) {
        if (ch == 'i')
            std::reverse(result.begin(), result.end());
        else
            result += ch;
    }
    return result;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Faulty Keyboard\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << finalString("string") << "\n";
    std::cout << "sample 2 -> " << finalString("poiinter") << "\n";
}
