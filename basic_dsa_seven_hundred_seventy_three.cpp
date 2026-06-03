/**
 * Basic DSA - Find Closest Person (LeetCode 3516)
 * Compare absolute distances from persons 1 and 2 to fixed person 3.
 */

#include <cstdlib>
#include <iostream>

int findClosest(int firstPosition, int secondPosition, int targetPosition) {
    const int firstDistance = std::abs(firstPosition - targetPosition);
    const int secondDistance = std::abs(secondPosition - targetPosition);

    if (firstDistance == secondDistance)
        return 0;

    return firstDistance < secondDistance ? 1 : 2;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Find Closest Person\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << findClosest(2, 7, 4) << "\n";
    std::cout << "sample 2 -> " << findClosest(1, 5, 3) << "\n";
}
