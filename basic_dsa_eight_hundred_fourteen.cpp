/**
 * Basic DSA - Sum of Largest Prime Substrings (LeetCode 3556)
 * Enumerate numeric substrings, collect unique primes, sum the three largest.
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

bool isPrime(long long value) {
    if (value < 2)
        return false;
    for (long long divisor = 2; divisor * divisor <= value; ++divisor) {
        if (value % divisor == 0)
            return false;
    }
    return true;
}

long long sumOfLargestPrimes(const std::string& digits) {
    std::unordered_set<long long> uniquePrimes;
    const int length = static_cast<int>(digits.size());

    for (int start = 0; start < length; ++start) {
        long long number = 0;
        for (int end = start; end < length; ++end) {
            number = number * 10 + (digits[end] - '0');
            if (isPrime(number))
                uniquePrimes.insert(number);
        }
    }

    std::vector<long long> sortedPrimes(uniquePrimes.begin(), uniquePrimes.end());
    std::sort(sortedPrimes.begin(), sortedPrimes.end());

    long long total = 0;
    const int takeCount = std::min(3, static_cast<int>(sortedPrimes.size()));
    for (int index = static_cast<int>(sortedPrimes.size()) - takeCount;
         index < static_cast<int>(sortedPrimes.size());
         ++index)
        total += sortedPrimes[index];

    return total;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Sum of Largest Prime Substrings\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "sample 1 -> " << sumOfLargestPrimes("12234") << "\n";
    std::cout << "sample 2 -> " << sumOfLargestPrimes("111") << "\n";
}
