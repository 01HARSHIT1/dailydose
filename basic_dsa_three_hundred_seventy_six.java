/**
 * Basic DSA Problems - Wiggle Subsequence (LeetCode 376)
 * Longest subsequence where diff alternates positive/negative
 */
public class basic_dsa_three_hundred_seventy_six {

    // Problem: Longest wiggle subsequence (alternating < > < > or > < > <).

    /**
     * Greedy: track up/down length. When trend flips, extend.
     * Time O(n), Space O(1)
     */
    public static int wiggleMaxLength(int[] nums) {
        if (nums.length < 2) return nums.length;
        int up = 1, down = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] > nums[i - 1]) up = down + 1;
            else if (nums[i] < nums[i - 1]) down = up + 1;
        }
        return Math.max(up, down);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Wiggle Subsequence");
        System.out.println("=".repeat(60));

        System.out.println("[1,7,4,9,2,5] -> " + wiggleMaxLength(new int[]{1,7,4,9,2,5}));
        System.out.println("[1,17,5,10,13,15,10,5,16,8] -> " + wiggleMaxLength(new int[]{1,17,5,10,13,15,10,5,16,8}));
    }
}
