/**
 * Basic DSA Problems - House Robber
 * Max sum of non-adjacent elements
 */
public class basic_dsa_one_hundred_fifty_nine {

    // Problem: Array = money in each house. Rob max sum; cannot rob two adjacent houses.

    /**
     * dp: at each house, max = (rob this + best up to i-2) or (skip = best up to i-1). Roll with two vars.
     * Time O(n), Space O(1)
     */
    public static int rob(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        if (nums.length == 1) return nums[0];
        int prev = nums[0], cur = Math.max(nums[0], nums[1]);
        for (int i = 2; i < nums.length; i++) {
            int next = Math.max(cur, prev + nums[i]);
            prev = cur;
            cur = next;
        }
        return cur;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: House Robber");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,3,1] -> " + rob(new int[]{1, 2, 3, 1}));
        System.out.println("[2,7,9,3,1] -> " + rob(new int[]{2, 7, 9, 3, 1}));
    }
}
