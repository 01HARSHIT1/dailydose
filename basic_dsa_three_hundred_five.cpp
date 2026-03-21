/**
 * Basic DSA - Counting Bits (LeetCode 338)
 * For each i in [0, n], return number of 1 bits in binary i.
 */
#include <iostream>
#include <vector>

std::vector<int> countBits(int n) {
    std::vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++)
        ans[i] = ans[i >> 1] + (i & 1);
    return ans;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Counting Bits\n";
    std::cout << std::string(60, '=') << "\n";

    auto r1 = countBits(2);
    std::cout << "n=2 -> [";
    for (int i = 0; i < (int)r1.size(); i++) std::cout << (i ? "," : "") << r1[i];
    std::cout << "]\n";

    auto r2 = countBits(5);
    std::cout << "n=5 -> [";
    for (int i = 0; i < (int)r2.size(); i++) std::cout << (i ? "," : "") << r2[i];
    std::cout << "]\n";
}
