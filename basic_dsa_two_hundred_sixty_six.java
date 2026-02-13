/**
 * Basic DSA Problems - Climbing Stairs
 * Count distinct ways to reach top
 */
public class basic_dsa_two_hundred_sixty_six {

    // Problem: n steps. Each step you climb 1 or 2. Return number of distinct ways to reach top.

    /**
     * Fibonacci: ways(n) = ways(n-1) + ways(n-2). DP with O(1) space.
     * Time O(n), Space O(1)
     */
    public static int climbStairs(int n) {
        if (n <= 2) return n;
        int a = 1, b = 2;
        for (int i = 3; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Climbing Stairs");
        System.out.println("=".repeat(60));

        System.out.println("2 -> " + climbStairs(2));
        System.out.println("3 -> " + climbStairs(3));
        System.out.println("4 -> " + climbStairs(4));
    }
}
