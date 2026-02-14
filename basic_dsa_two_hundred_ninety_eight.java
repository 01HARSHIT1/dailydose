/**
 * Basic DSA Problems - Move Zeroes
 * Move all zeros to the end while maintaining relative order of non-zero elements
 */
public class basic_dsa_two_hundred_ninety_eight {

    // Problem: Given integer array, move all 0's to the end in-place.
    // Maintain relative order of non-zero elements.

    /**
     * Two pointers: write index + scan. Overwrite zeros with non-zeros, fill rest with 0.
     * Time O(n), Space O(1)
     */
    public static void moveZeroes(int[] nums) {
        int w = 0;
        for (int i = 0; i < nums.length; i++)
            if (nums[i] != 0) nums[w++] = nums[i];
        while (w < nums.length) nums[w++] = 0;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Move Zeroes");
        System.out.println("=".repeat(60));

        int[] a = {0, 1, 0, 3, 12};
        moveZeroes(a);
        System.out.println("[0,1,0,3,12] -> " + java.util.Arrays.toString(a));

        int[] b = {0};
        moveZeroes(b);
        System.out.println("[0] -> " + java.util.Arrays.toString(b));
    }
}
