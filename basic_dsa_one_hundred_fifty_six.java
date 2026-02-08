/**
 * Basic DSA Problems - Climbing Stairs
 * Number of distinct ways to climb n steps (1 or 2 steps at a time)
 */
public class basic_dsa_one_hundred_fifty_six {

    // Problem: Climb n steps. Each time you can climb 1 or 2 steps. Return number of distinct ways.

    /**
     * dp[i] = ways to reach step i. dp[i] = dp[i-1] + dp[i-2]. Same as Fibonacci.
     * Time O(n), Space O(1)
     */
    public static int climbStairs(int n) {
        if (n <= 2) return n;
        int a = 1, b = 2;
        for (int i = 3; i <= n; i++) {
            int next = a + b;
            a = b;
            b = next;
        }
        return b;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Climbing Stairs");
        System.out.println("=".repeat(60));

        System.out.println("2 -> " + climbStairs(2));
        System.out.println("3 -> " + climbStairs(3));
        System.out.println("5 -> " + climbStairs(5));
    }
}
