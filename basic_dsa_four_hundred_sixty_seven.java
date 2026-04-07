/**
 * Basic DSA Problems - One Fundamental Bit Manipulation Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_sixty_seven {

    // Problem 1: Single Number
    // Given a non-empty array of integers where every element appears twice except for one,
    // find that single one. You must use O(1) extra space (bitwise XOR approach).
    //
    // Example:
    // nums = [4,1,2,1,2] -> 4

    /**
     * XOR all elements; pairs cancel (a ^ a == 0)
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer singleNumber(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }

        int result = 0;
        for (int n : nums) {
            result ^= n;
        }
        return result;
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
        System.out.println("Problem 1: Single Number");
        System.out.println("=".repeat(60));

        int[] a1 = {4, 1, 2, 1, 2};
        System.out.println("nums: " + arrayToString(a1));
        System.out.println("Single: " + singleNumber(a1));

        int[] a2 = {2, 2, 1};
        System.out.println("\nnums: " + arrayToString(a2));
        System.out.println("Single: " + singleNumber(a2));

        int[] a3 = {1};
        System.out.println("\nnums: " + arrayToString(a3));
        System.out.println("Single: " + singleNumber(a3));

        int[] a4 = {};
        System.out.println("\nnums: " + arrayToString(a4));
        System.out.println("Single: " + singleNumber(a4));

        System.out.println("\nnums: null");
        System.out.println("Single: " + singleNumber(null));
    }
}
