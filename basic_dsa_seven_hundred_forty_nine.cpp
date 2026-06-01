/**
 * Basic DSA - Maximize Active Section with Trade I (LeetCode 3499)
 * Count ones plus the largest merge of two adjacent zero blocks after one trade.
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>

int maxActiveSectionsAfterTrade(const std::string& s) {
    const int n = static_cast<int>(s.size());
    int answer = 0;
    int index = 0;
    int previousZeroBlock = INT_MIN;
    int maxZeroMerge = 0;

    while (index < n) {
        int next = index + 1;
        while (next < n && s[next] == s[index])
            ++next;

        const int blockLength = next - index;
        if (s[index] == '1')
            answer += blockLength;
        else {
            maxZeroMerge = std::max(maxZeroMerge, previousZeroBlock + blockLength);
            previousZeroBlock = blockLength;
        }

        index = next;
    }

    return answer + maxZeroMerge;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximize Active Section with Trade I\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxActiveSectionsAfterTrade("01") << "\n";
    std::cout << "sample 2 -> " << maxActiveSectionsAfterTrade("0100") << "\n";
    std::cout << "sample 3 -> " << maxActiveSectionsAfterTrade("1000100") << "\n";
}
