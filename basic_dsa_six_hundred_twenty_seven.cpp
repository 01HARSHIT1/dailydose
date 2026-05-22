/**
 * Basic DSA - Count Total Number of Colored Cells (LeetCode 2579)
 * After n minutes the colored region is a diamond; total cells = 2*n*(n-1) + 1.
 */
#include <iostream>

long long coloredCells(int n) {
    long long ln = n;
    return 2 * ln * (ln - 1) + 1;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count Total Number of Colored Cells\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << coloredCells(1) << "\n";
    std::cout << "sample 2 -> " << coloredCells(2) << "\n";
    std::cout << "sample 3 -> " << coloredCells(3) << "\n";
}
