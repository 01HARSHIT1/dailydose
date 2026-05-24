/**
 * Basic DSA - Account Balance After Rounded Purchase (LeetCode 2806)
 * Round the purchase to the nearest multiple of 10 (ties round up), then subtract from 100.
 */
#include <iostream>

int accountBalanceAfterPurchase(int purchaseAmount) {
    int rounded = ((purchaseAmount + 5) / 10) * 10;
    return 100 - rounded;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Account Balance After Rounded Purchase\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << accountBalanceAfterPurchase(9) << "\n";
    std::cout << "sample 2 -> " << accountBalanceAfterPurchase(15) << "\n";
    std::cout << "sample 3 -> " << accountBalanceAfterPurchase(10) << "\n";
}
