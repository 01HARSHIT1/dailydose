/**
 * Basic DSA - Find the Minimum Amount of Time to Brew Potions (LeetCode 3494)
 * Track each wizard's finish time for the previous potion, sync per mana batch.
 */

#include <algorithm>
#include <iostream>
#include <vector>

long long minTime(const std::vector<int>& skill, const std::vector<int>& mana) {
    const int wizardCount = static_cast<int>(skill.size());
    std::vector<long long> finishTime(wizardCount, 0);

    for (const int manaValue : mana) {
        long long current = finishTime[0];

        for (int wizard = 1; wizard < wizardCount; ++wizard) {
            current = std::max(
                current + static_cast<long long>(skill[wizard - 1]) * manaValue,
                finishTime[wizard]);
        }

        finishTime[wizardCount - 1] =
            current + static_cast<long long>(skill[wizardCount - 1]) * manaValue;

        for (int wizard = wizardCount - 2; wizard >= 0; --wizard) {
            finishTime[wizard] =
                finishTime[wizard + 1] -
                static_cast<long long>(skill[wizard + 1]) * manaValue;
        }
    }

    return finishTime[wizardCount - 1];
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find the Minimum Amount of Time to Brew Potions\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minTime({1, 5, 2, 4}, {5, 1, 4, 2}) << "\n";
    std::cout << "sample 2 -> " << minTime({1, 1, 1}, {1, 1, 1}) << "\n";
}
