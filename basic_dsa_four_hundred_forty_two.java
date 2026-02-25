/**
 * Basic DSA Problems - Find All Duplicates in an Array (LeetCode 442)
 * Array [1,n], each appears 1 or 2 times. Find duplicates. O(n), O(1) extra.
 */
public class basic_dsa_four_hundred_forty_two {

    // Problem: nums in [1,n]. Find all appearing twice.

    /**
     * Cycle sort: put nums[i] at index nums[i]-1. After, nums[i]!=i+1 => duplicate.
     * Time O(n), Space O(1) excluding output
     */
    public static java.util.List<Integer> findDuplicates(int[] nums) {
        int n = nums.length;
        for (int i = 0; i < n; i++) {
            while (nums[i] != nums[nums[i] - 1]) {
                int t = nums[i];
                nums[i] = nums[t - 1];
                nums[t - 1] = t;
            }
        }
        java.util.List<Integer> ans = new java.util.ArrayList<>();
        for (int i = 0; i < n; i++)
            if (nums[i] != i + 1) ans.add(nums[i]);
        return ans;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Find All Duplicates in an Array");
        System.out.println("=".repeat(60));

        System.out.println("[4,3,2,7,8,2,3,1] -> " + findDuplicates(new int[]{4,3,2,7,8,2,3,1}));
        System.out.println("[1,1,2] -> " + findDuplicates(new int[]{1,1,2}));
        System.out.println("[1] -> " + findDuplicates(new int[]{1}));
    }
}
