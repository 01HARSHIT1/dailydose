/**
 * Basic DSA - Separate Squares I (LeetCode 3453)
 * Find minimum y of a horizontal line that splits total square area in half.
 */

#include <algorithm>
#include <iostream>
#include <vector>

double areaBelow(const std::vector<std::vector<int>>& squares, double y) {
    double total = 0;
    for (const auto& square : squares) {
        double bottom = square[1];
        double side = square[2];
        if (y <= bottom)
            continue;
        total += side * std::min(y - bottom, side);
    }
    return total;
}

double separateSquares(const std::vector<std::vector<int>>& squares) {
    double totalArea = 0;
    double hi = 0;

    for (const auto& square : squares) {
        totalArea += 1.0 * square[2] * square[2];
        hi = std::max(hi, square[1] + square[2] * 1.0);
    }

    double lo = 0;
    const double half = totalArea / 2.0;
    while (hi - lo > 1e-5) {
        double mid = (lo + hi) / 2.0;
        if (areaBelow(squares, mid) >= half)
            hi = mid;
        else
            lo = mid;
    }
    return hi;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Separate Squares I\n";
    std::cout << std::string(60, '=') << "\n";
    std::cout << std::fixed;
    std::cout.precision(5);

    std::cout << "sample 1 -> " << separateSquares({{0, 0, 1}, {2, 2, 1}}) << "\n";
    std::cout << "sample 2 -> " << separateSquares({{0, 0, 2}, {1, 1, 1}}) << "\n";
    std::cout << "sample 3 -> " << separateSquares({{0, 0, 4}}) << "\n";
}
