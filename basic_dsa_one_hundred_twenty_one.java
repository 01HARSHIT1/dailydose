/**
 * Basic DSA Problems - Climbing Stairs
 * Number of distinct ways to climb n steps (1 or 2 steps at a time)
 */
public class basic_dsa_one_hundred_twenty_one {

    // Problem: You are climbing stairs. You can take 1 or 2 steps. In how many distinct ways can you climb n steps?

    /**
     * Same as Fibonacci: ways(n) = ways(n-1) + ways(n-2). Iterative DP.
     * Time O(n), Space O(1)
     */
    public static int climbStairs(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;
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

        System.out.println("n=2 -> " + climbStairs(2));
        System.out.println("n=3 -> " + climbStairs(3));
        System.out.println("n=4 -> " + climbStairs(4));
    }
}
