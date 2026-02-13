/**
 * Basic DSA Problems - Find All Duplicates in an Array
 * Find all elements that appear twice (1 to n, each appears once or twice)
 */
public class basic_dsa_two_hundred_fifty_two {

    // Problem: nums of length n, values in [1,n]. Each appears once or twice.
    // Return all elements that appear twice. O(n) time, O(1) extra space.

    /**
     * Use array as hash: mark nums[abs(x)-1] negative when seen. If already negative, it's duplicate.
     * Time O(n), Space O(1)
     */
    public static java.util.List<Integer> findDuplicates(int[] nums) {
        java.util.List<Integer> out = new java.util.ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            int idx = Math.abs(nums[i]) - 1;
            if (nums[idx] < 0) out.add(idx + 1);
            else nums[idx] = -nums[idx];
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Find All Duplicates in an Array");
        System.out.println("=".repeat(60));

        System.out.println("[4,3,2,7,8,2,3,1] -> " + findDuplicates(new int[]{4, 3, 2, 7, 8, 2, 3, 1}));
        System.out.println("[1,1,2] -> " + findDuplicates(new int[]{1, 1, 2}));
    }
}
