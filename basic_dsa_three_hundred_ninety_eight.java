/**
 * Basic DSA Problems - Random Pick Index (LeetCode 398)
 * pick(target) returns random index of target with equal probability
 */
public class basic_dsa_three_hundred_ninety_eight {

    // Problem: pick(target) - random index where nums[i]==target. Equal prob.

    static class Solution {
        int[] nums;
        java.util.Random rnd = new java.util.Random();

        Solution(int[] nums) { this.nums = nums; }

        /**
         * Reservoir sampling: for each match, replace with prob 1/count.
         * Time O(n), Space O(1)
         */
        public int pick(int target) {
            int idx = -1;
            int count = 0;
            for (int i = 0; i < nums.length; i++) {
                if (nums[i] != target) continue;
                count++;
                if (rnd.nextInt(count) == 0) idx = i;
            }
            return idx;
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Random Pick Index");
        System.out.println("=".repeat(60));

        Solution sol = new Solution(new int[]{1, 2, 3, 3, 3});
        System.out.println("pick(3) x3: " + sol.pick(3) + " " + sol.pick(3) + " " + sol.pick(3));
    }
}
