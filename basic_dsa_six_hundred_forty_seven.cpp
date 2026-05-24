/**
 * Basic DSA - Determine the Winner of a Bowling Game (LeetCode 2660)
 * A turn doubles if either of the previous two frames was a strike (10 pins); compare both players' totals.
 */
#include <iostream>
#include <vector>

int scoreOf(const std::vector<int>& rolls) {
    int total = 0;
    for (int i = 0; i < static_cast<int>(rolls.size()); ++i) {
        int multiplier = 1;
        if ((i >= 1 && rolls[static_cast<size_t>(i - 1)] == 10) ||
            (i >= 2 && rolls[static_cast<size_t>(i - 2)] == 10))
            multiplier = 2;
        total += multiplier * rolls[static_cast<size_t>(i)];
    }
    return total;
}

int isWinner(const std::vector<int>& player1, const std::vector<int>& player2) {
    int s1 = scoreOf(player1);
    int s2 = scoreOf(player2);
    if (s1 > s2)
        return 1;
    if (s2 > s1)
        return 2;
    return 0;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Determine the Winner of a Bowling Game\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << isWinner({4, 10, 7, 9}, {6, 5, 2, 3}) << "\n";
    std::cout << "sample 2 -> " << isWinner({3, 5, 7, 6}, {8, 10, 10, 2}) << "\n";
    std::cout << "sample 3 -> " << isWinner({2, 3}, {4, 1}) << "\n";
}
