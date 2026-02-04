/**
 * Basic DSA Problems - Move Zeroes
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_seventy_three {

    // Problem: Move all zeroes to the end of the array (in-place)
    // Preserve the relative order of non-zero elements
    // Example: [0,1,0,3,12] -> [1,3,12,0,0]

    /**
     * Move zeroes to end using two-pointer (write index)
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static void moveZeroes(int[] nums) {
        if (nums == null || nums.length <= 1) return;

        int write = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                if (write != i) {
                    nums[write] = nums[i];
                    nums[i] = 0;
                }
                write++;
            }
        }
    }

    /**
     * Return new array with zeroes at end (does not modify input)
     */
    public static int[] moveZeroesCopy(int[] nums) {
        if (nums == null) return new int[0];
        int[] res = new int[nums.length];
        int j = 0;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) res[j++] = nums[i];
        }
        return res;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Move Zeroes");
        System.out.println("=".repeat(60));

        // Test 1
        int[] a1 = { 0, 1, 0, 3, 12 };
        System.out.println("Before: " + Arrays.toString(a1));
        moveZeroes(a1);
        System.out.println("After:  " + Arrays.toString(a1));

        // Test 2
        int[] a2 = { 0 };
        System.out.println("\nBefore: " + Arrays.toString(a2));
        moveZeroes(a2);
        System.out.println("After:  " + Arrays.toString(a2));

        // Test 3
        int[] a3 = { 1, 2, 3 };
        System.out.println("\nBefore: " + Arrays.toString(a3));
        moveZeroes(a3);
        System.out.println("After:  " + Arrays.toString(a3));
    }
}
