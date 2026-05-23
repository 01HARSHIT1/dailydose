/**
 * Basic DSA - Minimum Time to Repair Cars (LeetCode 2594)
 * Mechanic with rank r fixes c cars in r*c^2 time; binary search the minimum time to cover all cars.
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

long long carsRepaired(const std::vector<int>& ranks, long long time) {
    long long total = 0;
    for (int r : ranks)
        total += static_cast<long long>(std::sqrt(static_cast<double>(time) / r));
    return total;
}

long long repairCars(const std::vector<int>& ranks, int cars) {
    long long lo = 1;
    long long hi = static_cast<long long>(ranks[0]) * cars * cars;
    for (int r : ranks)
        hi = std::min(hi, static_cast<long long>(r) * cars * cars);

    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (carsRepaired(ranks, mid) >= cars)
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Minimum Time to Repair Cars\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << repairCars({4, 2, 3, 1}, 10) << "\n";
    std::cout << "sample 2 -> " << repairCars({5, 1, 8}, 6) << "\n";
}
