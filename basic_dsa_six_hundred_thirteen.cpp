/**
 * Basic DSA - Check if Point Is Reachable (LeetCode 2543)
 * Allowed moves preserve gcd except doubling; reachable iff gcd(targetX, targetY) is a power of two.
 */
#include <iostream>

int gcdInt(int a, int b) {
    while (b != 0) {
        int rem = a % b;
        a = b;
        b = rem;
    }
    return a;
}

bool isReachable(int targetX, int targetY) {
    int g = gcdInt(targetX, targetY);
    return g > 0 && (g & (g - 1)) == 0;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Check if Point Is Reachable\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << std::boolalpha;
    std::cout << "sample 1 -> " << isReachable(6, 9) << "\n";
    std::cout << "sample 2 -> " << isReachable(4, 7) << "\n";
    std::cout << "sample 3 -> " << isReachable(6, 6) << "\n";
}
