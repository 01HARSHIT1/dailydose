/**
 * Basic DSA - Substring Matching Pattern (LeetCode 3407)
 * Split pattern at '*' and require each part to appear in order within s.
 */
#include <iostream>
#include <string>

bool hasMatch(const std::string& s, const std::string& p) {
    int index = 0;
    int start = 0;
    while (start < static_cast<int>(p.size())) {
        size_t star = p.find('*', static_cast<size_t>(start));
        std::string part;
        if (star == std::string::npos) {
            part = p.substr(static_cast<size_t>(start));
            start = static_cast<int>(p.size());
        } else {
            part = p.substr(static_cast<size_t>(start), star - static_cast<size_t>(start));
            start = static_cast<int>(star) + 1;
        }
        size_t found = s.find(part, static_cast<size_t>(index));
        if (found == std::string::npos)
            return false;
        index = static_cast<int>(found + part.size());
    }
    return true;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Substring Matching Pattern\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> " << hasMatch("leetcode", "ee*e") << "\n";
    std::cout << "sample 2 -> " << hasMatch("car", "c*v") << "\n";
    std::cout << "sample 3 -> " << hasMatch("luck", "u*") << "\n";
}
