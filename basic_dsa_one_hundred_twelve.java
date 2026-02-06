/**
 * Basic DSA Problems - Remove Duplicates from Sorted Array
 * Remove duplicates in-place, return new length
 */
import java.util.Arrays;

public class basic_dsa_one_hundred_twelve {

    // Problem: Given sorted integer array nums, remove duplicates in-place so each element
    // appears once. Return the number of unique elements (first k elements are the result).

    /**
     * Two pointers: write index for next unique; scan and copy when different from previous.
     * Time O(n), Space O(1)
     */
    public static int removeDuplicates(int[] nums) {
        if (nums == null || nums.length == 0) return 0;
        int write = 1;
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] != nums[i - 1]) {
                nums[write++] = nums[i];
            }
        }
        return write;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Remove Duplicates from Sorted Array");
        System.out.println("=".repeat(60));

        int[] a = { 1, 1, 2 };
        int k1 = removeDuplicates(a);
        System.out.println("[1,1,2] -> k=" + k1 + ", nums=" + Arrays.toString(Arrays.copyOf(a, k1)));

        int[] b = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
        int k2 = removeDuplicates(b);
        System.out.println("[0,0,1,1,1,2,2,3,3,4] -> k=" + k2 + ", nums=" + Arrays.toString(Arrays.copyOf(b, k2)));
    }
}
