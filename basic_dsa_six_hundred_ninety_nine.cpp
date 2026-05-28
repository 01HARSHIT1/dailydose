/**
 * Basic DSA - Count Substrings With K-Frequency Characters I (LeetCode 3325)
 * Sliding window: for each right end, count left starts where some char appears at least k times.
 */
#include <array>
#include <iostream>
#include <string>

int numberOfSubstrings(const std::string& s, int k) {
    int answer = 0;
    int left = 0;
    std::array<int, 26> count{};

    for (char ch : s) {
        ++count[static_cast<size_t>(ch - 'a')];
        while (count[static_cast<size_t>(ch - 'a')] >= k) {
            --count[static_cast<size_t>(s[static_cast<size_t>(left)] - 'a')];
            ++left;
        }
        answer += left;
    }
    return answer;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count Substrings With K-Frequency Characters I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << numberOfSubstrings("abacb", 2) << "\n";
    std::cout << "sample 2 -> " << numberOfSubstrings("abcde", 1) << "\n";
}
