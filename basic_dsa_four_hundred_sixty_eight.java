/**
 * Basic DSA Problems - One Fundamental Dynamic Programming Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_sixty_eight {

    // Problem 1: Climbing Stairs
    // You are climbing a staircase. It takes n steps to reach the top.
    // Each time you can climb 1 or 2 steps. In how many distinct ways can you reach the top?
    //
    // This equals the (n+1)th Fibonacci number: ways(n) = ways(n-1) + ways(n-2)
    //
    // Example:
    // n = 3 -> 3 (1+1+1, 1+2, 2+1)

    /**
     * Iterative DP with O(1) space
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Long climbStairs(int n) {
        if (n <= 0) {
            return null;
        }
        if (n == 1) {
            return 1L;
        }

        long oneStepBefore = 1;
        long twoStepsBefore = 1;

        for (int i = 2; i <= n; i++) {
            long current = oneStepBefore + twoStepsBefore;
            twoStepsBefore = oneStepBefore;
            oneStepBefore = current;
        }

        return oneStepBefore;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Climbing Stairs");
        System.out.println("=".repeat(60));

        for (int n : new int[] {1, 2, 3, 4, 5, 8}) {
            System.out.println("n = " + n + " -> ways = " + climbStairs(n));
        }

        System.out.println("\nn = 0 -> ways = " + climbStairs(0));
        System.out.println("n = -1 -> ways = " + climbStairs(-1));
    }
}
