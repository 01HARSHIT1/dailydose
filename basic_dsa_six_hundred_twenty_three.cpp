/**
 * Basic DSA - Minimum Operations to Reduce an Integer to 0 (LeetCode 2571)
 * Add/subtract powers of two; greedily handle trailing 1-bits: a lone bit costs 1, a run is cheaper to round up.
 */
#include <iostream>

int minOperations(int n) {
    int operations = 0;
    while (n > 0) {
        if ((n & 1) == 0) {
            n >>= 1;
        } else if ((n & 3) == 3) {
            ++n; // round the run of 1s up to the next power of two
            ++operations;
        } else {
            --n; // clear the lone trailing 1-bit
            ++operations;
        }
    }
    return operations;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Operations to Reduce an Integer to 0\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << minOperations(39) << "\n";
    std::cout << "sample 2 -> " << minOperations(54) << "\n";
}
