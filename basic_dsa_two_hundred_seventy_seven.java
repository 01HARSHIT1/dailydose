/**
 * Basic DSA Problems - Count Primes
 * Count primes less than n (Sieve of Eratosthenes)
 */
public class basic_dsa_two_hundred_seventy_seven {

    // Problem: Return count of prime numbers less than n.

    /**
     * Sieve of Eratosthenes: mark multiples of primes as composite.
     * Time O(n log log n), Space O(n)
     */
    public static int countPrimes(int n) {
        if (n <= 2) return 0;
        boolean[] notPrime = new boolean[n];
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (!notPrime[i]) {
                count++;
                for (int j = i * 2; j < n; j += i) notPrime[j] = true;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Count Primes");
        System.out.println("=".repeat(60));

        System.out.println("10 -> " + countPrimes(10));
        System.out.println("0 -> " + countPrimes(0));
        System.out.println("2 -> " + countPrimes(2));
    }
}
