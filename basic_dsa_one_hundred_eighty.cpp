/**
 * Basic DSA - Roman to Integer (LeetCode 13)
 * Convert Roman numeral string to integer.
 */
#include <iostream>
#include <string>
#include <unordered_map>

int romanToInt(std::string s) {
    std::unordered_map<char, int> m = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int ans = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (i + 1 < s.size() && m[s[i]] < m[s[i+1]])
            ans -= m[s[i]];
        else
            ans += m[s[i]];
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Roman to Integer\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "III -> " << romanToInt("III") << "\n";
    std::cout << "LVIII -> " << romanToInt("LVIII") << "\n";
    std::cout << "MCMXCIV -> " << romanToInt("MCMXCIV") << "\n";
}
