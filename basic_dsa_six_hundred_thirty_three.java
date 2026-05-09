/**
 * Basic DSA Problems - One Fundamental Sieve Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_thirty_three {

    // Problem 1: Count Primes
    // Return how many prime numbers are strictly less than n.

    /**
     * Sieve of Eratosthenes: mark multiples of each prime starting at i*i
     * Time Complexity: O(n log log n)
     * Space Complexity: O(n)
     */
    public static int countPrimes(int n) {
        if (n <= 2) {
            return 0;
        }

        boolean[] composite = new boolean[n];
        int count = 0;

        for (int i = 2; i < n; i++) {
            if (!composite[i]) {
                count++;
                if ((long) i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        composite[j] = true;
                    }
                }
            }
        }

        return count;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Count Primes");
        System.out.println("=".repeat(60));

        System.out.println("n=10 -> " + countPrimes(10));
        System.out.println("n=0 -> " + countPrimes(0));
        System.out.println("n=2 -> " + countPrimes(2));
        System.out.println("n=100 -> " + countPrimes(100));
    }
}
