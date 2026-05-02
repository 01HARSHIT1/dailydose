/**
 * Basic DSA Problems - One Fundamental Dynamic Programming Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_forty_eight {

    // Problem 1: Maximum Subarray
    // Given an integer array nums, find the contiguous subarray (containing at least one number)
    // which has the largest sum, and return its sum.
    //
    // Example:
    // nums = [-2,1,-3,4,-1,2,1,-5,4] -> 6

    /**
     * Kadane's algorithm
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer maxSubArray(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }

        int current = nums[0];
        int best = nums[0];

        for (int i = 1; i < nums.length; i++) {
            current = Math.max(nums[i], current + nums[i]);
            best = Math.max(best, current);
        }

        return best;
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
        System.out.println("Problem 1: Maximum Subarray");
        System.out.println("=".repeat(60));

        int[] a1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        System.out.println("nums = " + arrayToString(a1) + " -> " + maxSubArray(a1));

        int[] a2 = {1};
        System.out.println("nums = " + arrayToString(a2) + " -> " + maxSubArray(a2));

        int[] a3 = {5, 4, -1, 7, 8};
        System.out.println("nums = " + arrayToString(a3) + " -> " + maxSubArray(a3));

        int[] a4 = {-1, -2, -3};
        System.out.println("nums = " + arrayToString(a4) + " -> " + maxSubArray(a4));

        System.out.println("nums = null -> " + maxSubArray(null));
    }
}
