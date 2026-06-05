/**
 * Basic DSA - Minimum Deletions for At Most K Distinct Characters (LeetCode 3545)
 * Remove lowest-frequency characters until at most k distinct letters remain.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int minDeletion(const std::string& text, int maxDistinct) {
    int counts[26] = {};

    for (const char character : text)
        ++counts[character - 'a'];

    std::vector<int> frequencies;
    for (const int count : counts) {
        if (count > 0)
            frequencies.push_back(count);
    }

    if (static_cast<int>(frequencies.size()) <= maxDistinct)
        return 0;

    std::sort(frequencies.begin(), frequencies.end());

    int deletions = 0;
    const int removeCount = static_cast<int>(frequencies.size()) - maxDistinct;
    for (int index = 0; index < removeCount; ++index)
        deletions += frequencies[index];

    return deletions;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Deletions for At Most K Distinct Characters\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minDeletion("abc", 2) << "\n";
    std::cout << "sample 2 -> " << minDeletion("aabb", 2) << "\n";
    std::cout << "sample 3 -> " << minDeletion("yyyzz", 1) << "\n";
}
