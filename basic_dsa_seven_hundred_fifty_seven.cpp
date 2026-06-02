/**
 * Basic DSA - Maximum Containers on a Ship (LeetCode 3492)
 * Limit by deck cells and total weight capacity.
 */

#include <algorithm>
#include <iostream>

int maxContainers(int n, int w, int maxWeight) {
    return std::min(n * n, maxWeight / w);
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Maximum Containers on a Ship\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << maxContainers(2, 3, 15) << "\n";
    std::cout << "sample 2 -> " << maxContainers(3, 5, 20) << "\n";
    std::cout << "sample 3 -> " << maxContainers(3, 10, 50) << "\n";
}
