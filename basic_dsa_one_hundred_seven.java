/**
 * Basic DSA Problems - Move Zeroes
 * Move all zeroes to the end while maintaining relative order of non-zero elements
 */
import java.util.Arrays;

public class basic_dsa_one_hundred_seven {

    // Problem: Given integer array nums, move all 0's to the end in-place while
    // maintaining the relative order of non-zero elements.

    /**
     * Two pointers: write index for next non-zero; scan and swap when we see non-zero.
     * Time O(n), Space O(1)
     */
    public static void moveZeroes(int[] nums) {
        if (nums == null || nums.length == 0) return;
        int write = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                if (i != write) {
                    nums[write] = nums[i];
                    nums[i] = 0;
                }
                write++;
            }
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Move Zeroes");
        System.out.println("=".repeat(60));

        int[] a = { 0, 1, 0, 3, 12 };
        moveZeroes(a);
        System.out.println("[0,1,0,3,12] -> " + Arrays.toString(a));

        int[] b = { 0 };
        moveZeroes(b);
        System.out.println("[0] -> " + Arrays.toString(b));

        int[] c = { 1, 2, 3 };
        moveZeroes(c);
        System.out.println("[1,2,3] -> " + Arrays.toString(c));
    }
}
