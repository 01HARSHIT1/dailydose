/**
 * Basic DSA Problems - Find All Numbers Disappeared in an Array
 * Find numbers in [1, n] missing from array of length n
 */
public class basic_dsa_two_hundred_forty_six {

    // Problem: nums of length n with values in [1, n]. Some appear twice, some missing.
    // Return list of all numbers in [1, n] that do not appear. O(n) time, O(1) extra space.

    /**
     * Use array as hash: mark nums[nums[i]-1] as negative. Indices still positive = missing.
     * Time O(n), Space O(1) excluding output
     */
    public static java.util.List<Integer> findDisappearedNumbers(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int idx = Math.abs(nums[i]) - 1;
            if (nums[idx] > 0) nums[idx] = -nums[idx];
        }
        java.util.List<Integer> out = new java.util.ArrayList<>();
        for (int i = 0; i < nums.length; i++)
            if (nums[i] > 0) out.add(i + 1);
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Find All Numbers Disappeared in an Array");
        System.out.println("=".repeat(60));

        System.out.println("[4,3,2,7,8,2,3,1] -> " + findDisappearedNumbers(new int[]{4, 3, 2, 7, 8, 2, 3, 1}));
        System.out.println("[1,1] -> " + findDisappearedNumbers(new int[]{1, 1}));
    }
}
