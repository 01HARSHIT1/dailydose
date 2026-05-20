/**
 * Basic DSA - Largest Palindromic Number (LeetCode 2384)
 * Count digits, build the left half from 9 down using pairs, optional middle digit, mirror; strip leading zeros.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

std::string largestPalindromic(const std::string& num) {
    std::vector<int> cnt(10, 0);
    for (char ch : num)
        ++cnt[ch - '0'];

    std::string half;
    for (int d = 9; d >= 0; --d) {
        int pairs = cnt[static_cast<size_t>(d)] / 2;
        if (pairs == 0)
            continue;
        if (d == 0 && half.empty())
            continue;
        half += std::string(static_cast<size_t>(pairs), static_cast<char>('0' + d));
    }

    int mid = -1;
    for (int d = 9; d >= 0; --d) {
        if (cnt[static_cast<size_t>(d)] % 2) {
            mid = d;
            break;
        }
    }

    std::string result = half;
    if (mid >= 0)
        result += static_cast<char>('0' + mid);
    std::string rev = half;
    std::reverse(rev.begin(), rev.end());
    result += rev;

    size_t start = 0;
    while (start + 1 < result.size() && result[start] == '0')
        ++start;
    result = result.substr(start);
    return result.empty() ? "0" : result;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Largest Palindromic Number\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << largestPalindromic("444947137") << "\n";
    std::cout << "sample 2 -> " << largestPalindromic("00009") << "\n";
    std::cout << "sample 3 -> " << largestPalindromic("0000") << "\n";
}
