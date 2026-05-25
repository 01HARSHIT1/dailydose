/**
 * Basic DSA - Best Poker Hand (LeetCode 2347)
 * Decide the best hand from rank/suit counts: flush > three of a kind > pair > high card.
 */
#include <array>
#include <iostream>
#include <string>
#include <vector>

std::string bestHand(const std::vector<int>& ranks, const std::vector<char>& suits) {
    bool flush = true;
    for (size_t i = 1; i < suits.size(); ++i) {
        if (suits[i] != suits[0]) {
            flush = false;
            break;
        }
    }
    if (flush)
        return "Flush";

    std::array<int, 14> rankCount{};
    int maxSame = 0;
    for (int r : ranks)
        maxSame = std::max(maxSame, ++rankCount[static_cast<size_t>(r)]);

    if (maxSame >= 3)
        return "Three of a Kind";
    if (maxSame == 2)
        return "Pair";
    return "High Card";
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Best Poker Hand\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << bestHand({13, 2, 3, 1, 9}, {'a', 'a', 'a', 'a', 'a'}) << "\n";
    std::cout << "sample 2 -> " << bestHand({4, 4, 2, 4, 4}, {'d', 'a', 'a', 'b', 'c'}) << "\n";
    std::cout << "sample 3 -> " << bestHand({10, 10, 2, 12, 13}, {'a', 'b', 'c', 'a', 'd'}) << "\n";
}
