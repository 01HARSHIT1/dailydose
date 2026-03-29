/**
 * Basic DSA - Find N Unique Integers Sum up to Zero (LeetCode 1304)
 * Return n distinct integers that sum to 0 (any valid answer).
 */
#include <iostream>
#include <string>
#include <vector>

std::vector<int> sumZero(int n) {
    std::vector<int> ans;
    ans.reserve(static_cast<size_t>(n));
    for (int i = 1; i <= n / 2; ++i) {
        ans.push_back(i);
        ans.push_back(-i);
    }
    if (n % 2 == 1)
        ans.push_back(0);
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find N Unique Integers Sum up to Zero\n";
    std::cout << std::string(60, '=') << "\n";

    auto a1 = sumZero(5);
    std::cout << "n=5 -> ";
    for (size_t i = 0; i < a1.size(); ++i)
        std::cout << (i ? "," : "") << a1[i];
    std::cout << "\n";

    auto a2 = sumZero(4);
    std::cout << "n=4 -> ";
    for (size_t i = 0; i < a2.size(); ++i)
        std::cout << (i ? "," : "") << a2[i];
    std::cout << "\n";
}
