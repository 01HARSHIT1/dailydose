/**
 * Basic DSA - Water Bottles (LeetCode 1518)
 * Start with numBottles full; numExchange empties become one full bottle.
 */
#include <iostream>
#include <string>

int numWaterBottles(int numBottles, int numExchange) {
    int total = numBottles;
    int empty = numBottles;
    while (empty >= numExchange) {
        int fresh = empty / numExchange;
        total += fresh;
        empty = empty % numExchange + fresh;
    }
    return total;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Water Bottles\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "bottles=9, exchange=3 -> " << numWaterBottles(9, 3) << "\n";
    std::cout << "bottles=15, exchange=4 -> " << numWaterBottles(15, 4) << "\n";
}
