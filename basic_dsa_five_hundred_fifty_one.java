/**
 * Basic DSA Problems - One Fundamental Bit Manipulation Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_fifty_one {

    // Problem 1: Single Number
    // Given a non-empty array of integers nums, every element appears twice except for one.
    // Find that single one.
    //
    // Example:
    // nums = [2,2,1] -> 1

    /**
     * XOR cancels equal values: a ^ a = 0, 0 ^ b = b
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer singleNumber(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }

        int ans = 0;
        for (int num : nums) {
            ans ^= num;
        }
        return ans;
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

        int[] a1 = {2, 2, 1};
        System.out.println("nums = " + arrayToString(a1) + " -> " + singleNumber(a1));

        int[] a2 = {4, 1, 2, 1, 2};
        System.out.println("nums = " + arrayToString(a2) + " -> " + singleNumber(a2));

        int[] a3 = {1};
        System.out.println("nums = " + arrayToString(a3) + " -> " + singleNumber(a3));

        int[] a4 = {};
        System.out.println("nums = " + arrayToString(a4) + " -> " + singleNumber(a4));

        System.out.println("nums = null -> " + singleNumber(null));
    }
}
