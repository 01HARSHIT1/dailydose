/**
 * Basic DSA - Count Primes (LeetCode 204)
 * Count number of prime numbers less than n (Sieve of Eratosthenes).
 */
#include <iostream>
#include <vector>

int countPrimes(int n) {
    if (n <= 2) return 0;
    std::vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i)
                isPrime[j] = false;
        }
    }
    int count = 0;
    for (int i = 2; i < n; i++) if (isPrime[i]) count++;
    return count;
}

int main() {
    std::cout << std::string(60, '=') << "\n";
    std::cout << "Problem: Count Primes\n";
    std::cout << std::string(60, '=') << "\n";

    std::cout << "n=10 -> " << countPrimes(10) << "\n";
    std::cout << "n=0 -> " << countPrimes(0) << "\n";
    std::cout << "n=1 -> " << countPrimes(1) << "\n";
    std::cout << "n=20 -> " << countPrimes(20) << "\n";
}
