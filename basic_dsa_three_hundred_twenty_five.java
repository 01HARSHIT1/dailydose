/**
 * Basic DSA Problems - Remove Duplicates from Sorted Array
 * Remove duplicates in-place, return new length
 */
public class basic_dsa_three_hundred_twenty_five {

    // Problem: Sorted array nums. Remove duplicates in-place. Return count of unique elements.

    /**
     * Two pointers: w writes next unique; r scans. Copy when nums[r] != nums[r-1].
     * Time O(n), Space O(1)
     */
    public static int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;
        int w = 1;
        for (int r = 1; r < nums.length; r++) {
            if (nums[r] != nums[r - 1]) nums[w++] = nums[r];
        }
        return w;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Remove Duplicates from Sorted Array");
        System.out.println("=".repeat(60));

        int[] a = {1, 1, 2};
        System.out.println("[1,1,2] -> k=" + removeDuplicates(a) + ", nums=" + java.util.Arrays.toString(java.util.Arrays.copyOf(a, 2)));

        int[] b = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        System.out.println("[0,0,1,1,1,2,2,3,3,4] -> k=" + removeDuplicates(b));
    }
}
