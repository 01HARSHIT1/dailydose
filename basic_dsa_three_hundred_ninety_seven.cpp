/**
 * Basic DSA - X of a Kind in a Deck of Cards (LeetCode 914)
 * Partition into groups of equal size X>=2; each group has the same integer.
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

static int gcd_int(int a, int b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b != 0) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

bool hasGroupsSizeX(std::vector<int>& deck) {
    std::unordered_map<int, int> cnt;
    for (int x : deck)
        ++cnt[x];
    int g = 0;
    for (const auto& p : cnt)
        g = gcd_int(g, p.second);
    return g >= 2;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: X of a Kind in a Deck of Cards\n";
    std::cout << std::string(60, '=') << "\n";

    std::vector<int> v1 = {1, 1, 1, 1, 2, 2, 2, 2};
    std::cout << "[1,1,1,1,2,2,2,2] -> " << (hasGroupsSizeX(v1) ? "true" : "false") << "\n";

    std::vector<int> v2 = {1, 1, 1, 2, 2, 2, 3, 3};
    std::cout << "[1,1,1,2,2,2,3,3] -> " << (hasGroupsSizeX(v2) ? "true" : "false") << "\n";
}
