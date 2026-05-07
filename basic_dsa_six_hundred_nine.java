/**
 * Basic DSA Problems - One Fundamental Dynamic Programming Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_nine {

    // Problem 1: House Robber
    // nums[i] is money in house i in a line; cannot rob two adjacent houses.
    // Maximize total money robbed.

    /**
     * dp[i] = max money up to house i = max(dp[i-1], dp[i-2] + nums[i])
     * Time Complexity: O(n)
     * Space Complexity: O(1) with two variables
     */
    public static Integer rob(int[] nums) {
        if (nums == null) {
            return null;
        }
        if (nums.length == 0) {
            return 0;
        }

        int takePrev = 0;
        int skipPrev = 0;

        for (int x : nums) {
            int newSkip = Math.max(skipPrev, takePrev);
            takePrev = skipPrev + x;
            skipPrev = newSkip;
        }

        return Math.max(skipPrev, takePrev);
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: House Robber");
        System.out.println("=".repeat(60));

        int[] a = {1, 2, 3, 1};
        System.out.println("[1,2,3,1] -> " + rob(a));

        int[] b = {2, 7, 9, 3, 1};
        System.out.println("[2,7,9,3,1] -> " + rob(b));

        int[] c = {5};
        System.out.println("[5] -> " + rob(c));

        System.out.println("empty -> " + rob(new int[0]));
        System.out.println("null -> " + rob(null));
    }
}
