/**
 * Basic DSA Problems - One Fundamental Array/XOR Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_seventy_six {

    // Problem 1: Missing Number
    // Given an array nums containing n distinct numbers in the range [0, n], return the only
    // number in the range that is missing from the array.
    //
    // Example:
    // nums = [3,0,1] -> 2
    // nums = [0,1] -> 2
    // nums = [9,6,4,2,3,5,7,0,1] -> 8

    /**
     * XOR all indices 0..n with all array values; the missing number remains
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer missingNumber(int[] nums) {
        if (nums == null) {
            return null;
        }

        int n = nums.length;
        int xor = 0;
        for (int i = 0; i < n; i++) {
            xor ^= i ^ nums[i];
        }
        xor ^= n;
        return xor;
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

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Missing Number");
        System.out.println("=".repeat(60));

        int[] a1 = {3, 0, 1};
        System.out.println("nums: " + arrayToString(a1));
        System.out.println("Missing: " + missingNumber(a1));

        int[] a2 = {0, 1};
        System.out.println("\nnums: " + arrayToString(a2));
        System.out.println("Missing: " + missingNumber(a2));

        int[] a3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
        System.out.println("\nnums: " + arrayToString(a3));
        System.out.println("Missing: " + missingNumber(a3));

        int[] a4 = {0};
        System.out.println("\nnums: " + arrayToString(a4));
        System.out.println("Missing: " + missingNumber(a4));

        int[] a5 = {};
        System.out.println("\nnums: " + arrayToString(a5));
        System.out.println("Missing: " + missingNumber(a5));

        System.out.println("\nnums: null");
        System.out.println("Missing: " + missingNumber(null));
    }
}
