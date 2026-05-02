/**
 * Basic DSA Problems - One Fundamental Prefix Sum Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_forty_six {

    // Problem 1: Find Pivot Index
    // Given an array of integers nums, calculate the pivot index.
    // The pivot index is the index where the sum of all numbers strictly to the left
    // equals the sum of all numbers strictly to the right.
    //
    // If no such index exists, return -1.
    //
    // Example:
    // nums = [1,7,3,6,5,6] -> 3

    /**
     * Prefix sum with running left sum
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer pivotIndex(int[] nums) {
        if (nums == null) {
            return null;
        }

        int total = 0;
        for (int n : nums) {
            total += n;
        }

        int left = 0;
        for (int i = 0; i < nums.length; i++) {
            int right = total - left - nums[i];
            if (left == right) {
                return i;
            }
            left += nums[i];
        }

        return -1;
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
        System.out.println("Problem 1: Find Pivot Index");
        System.out.println("=".repeat(60));

        int[] a1 = {1, 7, 3, 6, 5, 6};
        System.out.println("nums = " + arrayToString(a1) + " -> " + pivotIndex(a1));

        int[] a2 = {1, 2, 3};
        System.out.println("nums = " + arrayToString(a2) + " -> " + pivotIndex(a2));

        int[] a3 = {2, 1, -1};
        System.out.println("nums = " + arrayToString(a3) + " -> " + pivotIndex(a3));

        int[] a4 = {};
        System.out.println("nums = " + arrayToString(a4) + " -> " + pivotIndex(a4));

        System.out.println("nums = null -> " + pivotIndex(null));
    }
}
