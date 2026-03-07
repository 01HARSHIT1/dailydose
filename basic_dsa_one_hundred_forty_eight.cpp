/**
 * Basic DSA - Letter Combinations of a Phone Number (LeetCode 17)
 * All letter combinations for digit string (2-9 maps to letters).
 */
#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> letterCombinations(std::string digits) {
    if (digits.empty()) return {};
    static const std::string map[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::vector<std::string> ans = {""};
    for (char d : digits) {
        std::vector<std::string> next;
        for (const auto& s : ans)
            for (char c : map[d - '0'])
                next.push_back(s + c);
        ans = std::move(next);
    }
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Letter Combinations of a Phone Number\n";
    std::cout << std::string(60, '=') << "\n";

    auto r1 = letterCombinations("23");
    std::cout << "\"23\" -> ";
    for (size_t i = 0; i < r1.size(); i++) std::cout << (i ? "," : "") << r1[i];
    std::cout << "\n";

    auto r2 = letterCombinations("");
    std::cout << "\"\" -> (empty)\n";

    auto r3 = letterCombinations("2");
    std::cout << "\"2\" -> ";
    for (size_t i = 0; i < r3.size(); i++) std::cout << (i ? "," : "") << r3[i];
    std::cout << "\n";
}
