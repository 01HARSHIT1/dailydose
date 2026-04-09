/**
 * Basic DSA Problems - One Fundamental Two-Pointer Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_seventy_one {

    // Problem 1: Move Zeroes
    // Given an integer array nums, move all 0's to the end while keeping the relative order
    // of the non-zero elements. You must do this in-place.
    //
    // Example:
    // nums = [0,1,0,3,12] -> [1,3,12,0,0]

    /**
     * Single pass: write non-zeros to the front, then fill rest with zeros
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static void moveZeroes(int[] nums) {
        if (nums == null || nums.length == 0) {
            return;
        }

        int write = 0;
        for (int read = 0; read < nums.length; read++) {
            if (nums[read] != 0) {
                nums[write++] = nums[read];
            }
        }
        while (write < nums.length) {
            nums[write++] = 0;
        }
    }

    private static String arrayToString(int[] arr) {
        if (arr == null) {
            return "null";
        }
        if (arr.length == 0) {
            return "[]";
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < arr.length; i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append(arr[i]);
        }
        sb.append("]");
        return sb.toString();
    }

    private static int[] copyOf(int[] src) {
        if (src == null) {
            return null;
        }
        int[] c = new int[src.length];
        System.arraycopy(src, 0, c, 0, src.length);
        return c;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Move Zeroes");
        System.out.println("=".repeat(60));

        int[] a1 = {0, 1, 0, 3, 12};
        int[] t1 = copyOf(a1);
        System.out.println("Before: " + arrayToString(t1));
        moveZeroes(t1);
        System.out.println("After : " + arrayToString(t1));

        int[] a2 = {0};
        int[] t2 = copyOf(a2);
        System.out.println("\nBefore: " + arrayToString(t2));
        moveZeroes(t2);
        System.out.println("After : " + arrayToString(t2));

        int[] a3 = {1, 2, 3};
        int[] t3 = copyOf(a3);
        System.out.println("\nBefore: " + arrayToString(t3));
        moveZeroes(t3);
        System.out.println("After : " + arrayToString(t3));

        int[] a4 = {};
        int[] t4 = copyOf(a4);
        System.out.println("\nBefore: " + arrayToString(t4));
        moveZeroes(t4);
        System.out.println("After : " + arrayToString(t4));

        System.out.println("\nBefore: null");
        moveZeroes(null);
        System.out.println("After : (no change)");
    }
}
