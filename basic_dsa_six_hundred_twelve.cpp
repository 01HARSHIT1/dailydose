/**
 * Basic DSA - Apply Bitwise Operations to Make Strings Equal (LeetCode 2546)
 * AND/OR on two indices can spread 1-bits; reachable iff both strings contain at least one '1' (or already equal).
 */
#include <algorithm>
#include <iostream>
#include <string>

bool makeStringsEqual(const std::string& s, const std::string& target) {
    if (s == target)
        return true;
    auto hasOne = [](const std::string& value) {
        return std::count(value.begin(), value.end(), '1') > 0;
    };
    return hasOne(s) && hasOne(target);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Apply Bitwise Operations to Make Strings Equal\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> " << makeStringsEqual("1010", "0110") << "\n";
    std::cout << "sample 2 -> " << makeStringsEqual("11", "00") << "\n";
    std::cout << "sample 3 -> " << makeStringsEqual("1100", "0000") << "\n";
}
