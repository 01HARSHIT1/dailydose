/**
 * Basic DSA Problems - One Fundamental Dynamic Programming Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_thirty_three {

    // Problem 1: Climbing Stairs
    // You are climbing a staircase. It takes n steps to reach the top.
    // Each time you can either climb 1 or 2 steps.
    //
    // Return how many distinct ways you can climb to the top.
    //
    // Example:
    // n = 2 -> 2
    // n = 3 -> 3

    /**
     * Bottom-up Fibonacci-style DP with O(1) extra space
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer climbStairs(int n) {
        if (n < 0) {
            return null;
        }
        if (n <= 2) {
            return n;
        }

        int first = 1;
        int second = 2;

        for (int i = 3; i <= n; i++) {
            int current = first + second;
            first = second;
            second = current;
        }

        return second;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Climbing Stairs");
        System.out.println("=".repeat(60));

        System.out.println("n = 1 -> " + climbStairs(1));
        System.out.println("n = 2 -> " + climbStairs(2));
        System.out.println("n = 3 -> " + climbStairs(3));
        System.out.println("n = 5 -> " + climbStairs(5));
        System.out.println("n = 10 -> " + climbStairs(10));
        System.out.println("n = -1 -> " + climbStairs(-1));
    }
}
