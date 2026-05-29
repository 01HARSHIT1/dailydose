/**
 * Basic DSA - Maximum Difference Between Even and Odd Frequency I (LeetCode 3442)
 * Return max odd frequency minus min even frequency across characters in s.
 */
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int maxDifference(const std::string& s) {
    std::vector<int> count(26, 0);
    for (char c : s)
        ++count[c - 'a'];

    int maxOdd = 0;
    int minEven = static_cast<int>(s.size());
    for (int freq : count) {
        if (freq == 0)
            continue;
        if (freq % 2 == 0)
            minEven = std::min(minEven, freq);
        else
            maxOdd = std::max(maxOdd, freq);
    }
    return maxOdd - minEven;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Difference Between Even and Odd Frequency I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxDifference("aaaaabbc") << "\n";
    std::cout << "sample 2 -> " << maxDifference("abcabcab") << "\n";
}
