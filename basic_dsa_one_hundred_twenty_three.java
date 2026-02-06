/**
 * Basic DSA Problems - House Robber
 * Maximum sum of non-adjacent elements in array
 */
public class basic_dsa_one_hundred_twenty_three {

    // Problem: Given integer array nums (house money), can't rob two adjacent houses.
    // Return maximum amount you can rob.

    /**
     * DP: rob[i] = max(rob[i-1], nums[i] + rob[i-2]). Use two variables.
     * Time O(n), Space O(1)
     */
    public static int rob(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        if (nums.length == 1) return nums[0];
        int prev2 = 0, prev1 = nums[0];
        for (int i = 1; i < nums.length; i++) {
            int curr = Math.max(prev1, nums[i] + prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: House Robber");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,3,1] -> " + rob(new int[] { 1, 2, 3, 1 }));
        System.out.println("[2,7,9,3,1] -> " + rob(new int[] { 2, 7, 9, 3, 1 }));
    }
}
