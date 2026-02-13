/**
 * Basic DSA Problems - Ugly Number II
 * Find nth ugly number (factors only 2, 3, 5)
 */
public class basic_dsa_two_hundred_sixty_three {

    // Problem: Return nth ugly number. 1 is first ugly. 2,3,4,5,6,8,9,10...
    // Ugly = only prime factors 2, 3, 5.

    /**
     * Three pointers: track next multiples of 2, 3, 5. Pick minimum each step.
     * Time O(n), Space O(n)
     */
    public static int nthUglyNumber(int n) {
        int[] dp = new int[n];
        dp[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        for (int i = 1; i < n; i++) {
            int n2 = dp[i2] * 2, n3 = dp[i3] * 3, n5 = dp[i5] * 5;
            dp[i] = Math.min(n2, Math.min(n3, n5));
            if (dp[i] == n2) i2++;
            if (dp[i] == n3) i3++;
            if (dp[i] == n5) i5++;
        }
        return dp[n - 1];
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Ugly Number II");
        System.out.println("=".repeat(60));

        System.out.println("10 -> " + nthUglyNumber(10));
        System.out.println("1 -> " + nthUglyNumber(1));
        System.out.println("7 -> " + nthUglyNumber(7));
    }
}
