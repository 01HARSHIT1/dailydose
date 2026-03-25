/**
 * Basic DSA - Jewels and Stones (LeetCode 771)
 * Count stones that are also jewels (case-sensitive).
 */
#include <iostream>
#include <string>
#include <unordered_set>

int numJewelsInStones(const std::string& jewels, const std::string& stones) {
    std::unordered_set<char> j(jewels.begin(), jewels.end());
    int c = 0;
    for (char ch : stones) {
        if (j.count(ch))
            ++c;
    }
    return c;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Jewels and Stones\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "jewels=aA, stones=aAAbbbb -> " << numJewelsInStones("aA", "aAAbbbb") << "\n";
    std::cout << "jewels=z, stones=ZZ -> " << numJewelsInStones("z", "ZZ") << "\n";
}
