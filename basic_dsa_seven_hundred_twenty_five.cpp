/**
 * Basic DSA - Find Special Substring of Length K (LeetCode 3456)
 * Return true if s has a length-k run of one char isolated from same neighbors.
 */

#include <iostream>
#include <string>

bool hasSpecialSubstring(const std::string& s, int k) {
    const int n = static_cast<int>(s.size());
    int left = 0;

    while (left < n) {
        int right = left;
        while (right < n && s[right] == s[left])
            ++right;
        if (right - left == k)
            return true;
        left = right;
    }
    return false;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Special Substring of Length K\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> " << hasSpecialSubstring("aaabaaa", 3) << "\n";
    std::cout << "sample 2 -> " << hasSpecialSubstring("abc", 2) << "\n";
    std::cout << "sample 3 -> " << hasSpecialSubstring("aabaaba", 1) << "\n";
}
