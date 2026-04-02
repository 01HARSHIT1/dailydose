/**
 * Basic DSA - Count Odd Numbers in an Interval Range (LeetCode 1523)
 * Return how many odd integers lie in [low, high] inclusive.
 */
#include <iostream>

int countOdds(int low, int high) {
    return (high + 1) / 2 - low / 2;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count Odd Numbers in an Interval Range\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "low=3, high=7 -> " << countOdds(3, 7) << "\n";
    std::cout << "low=8, high=10 -> " << countOdds(8, 10) << "\n";
}
