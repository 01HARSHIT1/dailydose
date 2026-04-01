/**
 * Basic DSA - Number of Senior Citizens (LeetCode 2678)
 * Each record: 10-digit phone, gender char, then two-digit age at zero-based indices 11..12.
 */
#include <iostream>
#include <string>
#include <vector>

int countSeniors(std::vector<std::string>& details) {
    int ans = 0;
    for (const std::string& s : details) {
        int age = (s[11] - '0') * 10 + (s[12] - '0');
        if (age > 60)
            ++ans;
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Number of Senior Citizens\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<std::string> d1 = {"7868190130M7522", "5303914400F6521", "9273338290F4010"};
    std::cout << "example 1 -> " << countSeniors(d1) << "\n";

    std::vector<std::string> d2 = {"1313579440F2036", "2921522980M5644"};
    std::cout << "example 2 -> " << countSeniors(d2) << "\n";
}
