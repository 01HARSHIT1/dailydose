/**
 * Basic DSA Problems - Find All Numbers Disappeared in an Array (LeetCode 448)
 * Array [1,n], some appear twice. Find all that don't appear. O(n), O(1) extra.
 */
public class basic_dsa_four_hundred_forty_eight {

    // Problem: nums in [1,n]. Return missing numbers.

    /**
     * Mark presence by negating nums[abs(x)-1]. Positive at index i => i+1 missing.
     * Time O(n), Space O(1) excluding output
     */
    public static java.util.List<Integer> findDisappearedNumbers(int[] nums) {
        for (int x : nums) {
            int i = Math.abs(x) - 1;
            if (nums[i] > 0) nums[i] = -nums[i];
        }
        java.util.List<Integer> ans = new java.util.ArrayList<>();
        for (int i = 0; i < nums.length; i++)
            if (nums[i] > 0) ans.add(i + 1);
        return ans;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Find All Numbers Disappeared in an Array");
        System.out.println("=".repeat(60));

        System.out.println("[4,3,2,7,8,2,3,1] -> " + findDisappearedNumbers(new int[]{4,3,2,7,8,2,3,1}));
        System.out.println("[1,1] -> " + findDisappearedNumbers(new int[]{1,1}));
    }
}
