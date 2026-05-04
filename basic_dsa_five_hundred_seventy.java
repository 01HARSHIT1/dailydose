/**
 * Basic DSA Problems - One Fundamental Array Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_seventy {

    // Problem 1: Monotonic Array
    // An array is monotonic if it is either monotone increasing or monotone decreasing.
    //
    // Return true if the given array is monotonic, otherwise false.
    //
    // Example:
    // nums = [1,2,2,3] -> true
    // nums = [1,3,2] -> false

    /**
     * Track whether array can still be non-decreasing and/or non-increasing
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Boolean isMonotonic(int[] nums) {
        if (nums == null) {
            return null;
        }
        if (nums.length <= 2) {
            return true;
        }

        boolean nonDecreasing = true;
        boolean nonIncreasing = true;

        for (int i = 1; i < nums.length; i++) {
            if (nums[i] < nums[i - 1]) {
                nonDecreasing = false;
            }
            if (nums[i] > nums[i - 1]) {
                nonIncreasing = false;
            }
        }

        return nonDecreasing || nonIncreasing;
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
        System.out.println("Problem 1: Monotonic Array");
        System.out.println("=".repeat(60));

        int[] a1 = {1, 2, 2, 3};
        System.out.println("nums = " + arrayToString(a1) + " -> " + isMonotonic(a1));

        int[] a2 = {6, 5, 4, 4};
        System.out.println("nums = " + arrayToString(a2) + " -> " + isMonotonic(a2));

        int[] a3 = {1, 3, 2};
        System.out.println("nums = " + arrayToString(a3) + " -> " + isMonotonic(a3));

        int[] a4 = {};
        System.out.println("nums = " + arrayToString(a4) + " -> " + isMonotonic(a4));

        System.out.println("nums = null -> " + isMonotonic(null));
    }
}
