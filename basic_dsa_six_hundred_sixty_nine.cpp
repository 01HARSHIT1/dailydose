/**
 * Basic DSA - Minimum Number of Pushes to Type Word II (LeetCode 3016)
 * Greedily assign the most frequent letters the cheapest key positions (1,2,3,... presses).
 */
#include <algorithm>
#include <array>
#include <iostream>
#include <string>

int minimumPushes(const std::string& word) {
    std::array<int, 26> freq{};
    for (char ch : word)
        ++freq[static_cast<size_t>(ch - 'a')];

    std::sort(freq.begin(), freq.end(), std::greater<int>());

    int total = 0;
    for (int i = 0; i < 26; ++i) {
        if (freq[static_cast<size_t>(i)] == 0)
            break;
        total += (i / 8 + 1) * freq[static_cast<size_t>(i)];
    }
    return total;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Number of Pushes to Type Word II\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minimumPushes("abcde") << "\n";
    std::cout << "sample 2 -> " << minimumPushes("xyzxyzxyzxyz") << "\n";
    std::cout << "sample 3 -> " << minimumPushes("aabbccddeeffgghhiiiiii") << "\n";
}
