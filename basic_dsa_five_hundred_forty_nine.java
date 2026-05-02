/**
 * Basic DSA Problems - One Fundamental Recursion/DP Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_forty_nine {

    // Problem 1: Fibonacci Number
    // The Fibonacci numbers form a sequence where:
    // F(0) = 0, F(1) = 1, and F(n) = F(n - 1) + F(n - 2) for n > 1.
    //
    // Given n, return F(n).
    //
    // Example:
    // n = 4 -> 3

    /**
     * Iterative DP with constant space
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer fib(int n) {
        if (n < 0) {
            return null;
        }
        if (n <= 1) {
            return n;
        }

        int prev2 = 0;
        int prev1 = 1;

        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Fibonacci Number");
        System.out.println("=".repeat(60));

        System.out.println("n = 0 -> " + fib(0));
        System.out.println("n = 1 -> " + fib(1));
        System.out.println("n = 2 -> " + fib(2));
        System.out.println("n = 4 -> " + fib(4));
        System.out.println("n = 10 -> " + fib(10));
        System.out.println("n = -1 -> " + fib(-1));
    }
}
