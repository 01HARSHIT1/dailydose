/**
 * Basic DSA - Distinct Prime Factors of Product of Array (LeetCode 2521)
 * Factor each element; collect distinct prime divisors without multiplying the full product.
 */
#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

int distinctPrimeFactors(const std::vector<int>& nums) {
    std::unordered_set<int> primes;
    for (int value : nums) {
        int x = value;
        for (int p = 2; p * p <= x; ++p) {
            if (x % p == 0) {
                primes.insert(p);
                while (x % p == 0)
                    x /= p;
            }
        }
        if (x > 1)
            primes.insert(x);
    }
    return static_cast<int>(primes.size());
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Distinct Prime Factors of Product of Array\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << distinctPrimeFactors({2, 4, 3, 7, 10, 6}) << "\n";
    std::cout << "sample 2 -> " << distinctPrimeFactors({2, 4, 8, 16}) << "\n";
}
