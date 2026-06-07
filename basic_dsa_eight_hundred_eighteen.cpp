/**
 * Basic DSA - Find Minimum Log Transportation Cost (LeetCode 3560)
 * Cut the longer log once if it exceeds k; minimum cost is k * (max(n, m) - k).
 */

#include <algorithm>
#include <iostream>

long long minimumLogTransportCost(int firstLogLength, int secondLogLength, int truckCapacity) {
    const int longerLog = std::max(firstLogLength, secondLogLength);
    if (longerLog <= truckCapacity)
        return 0;
    return 1LL * truckCapacity * (longerLog - truckCapacity);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Minimum Log Transportation Cost\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minimumLogTransportCost(6, 5, 5) << "\n";
    std::cout << "sample 2 -> " << minimumLogTransportCost(4, 4, 6) << "\n";
}
