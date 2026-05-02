/**
 * Basic DSA Problems - One Fundamental Sliding Window Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_thirty_nine {

    // Problem 1: Maximum Average Subarray I
    // Given an integer array nums consisting of n elements, and an integer k,
    // find a contiguous subarray whose length is equal to k that has the maximum average value.
    //
    // Return this maximum average value.
    //
    // Example:
    // nums = [1,12,-5,-6,50,3], k = 4 -> 12.75

    /**
     * Fixed-size sliding window
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Double findMaxAverage(int[] nums, int k) {
        if (nums == null || k <= 0 || k > nums.length) {
            return null;
        }

        long windowSum = 0;
        for (int i = 0; i < k; i++) {
            windowSum += nums[i];
        }

        long maxSum = windowSum;
        for (int i = k; i < nums.length; i++) {
            windowSum += nums[i] - nums[i - k];
            if (windowSum > maxSum) {
                maxSum = windowSum;
            }
        }

        return (double) maxSum / k;
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
        System.out.println("Problem 1: Maximum Average Subarray I");
        System.out.println("=".repeat(60));

        int[] a1 = {1, 12, -5, -6, 50, 3};
        System.out.println("nums = " + arrayToString(a1) + ", k = 4 -> " + findMaxAverage(a1, 4));

        int[] a2 = {5};
        System.out.println("nums = " + arrayToString(a2) + ", k = 1 -> " + findMaxAverage(a2, 1));

        int[] a3 = {0, 4, 0, 3, 2};
        System.out.println("nums = " + arrayToString(a3) + ", k = 1 -> " + findMaxAverage(a3, 1));

        System.out.println("nums = null, k = 2 -> " + findMaxAverage(null, 2));
        System.out.println("nums = [1,2], k = 3 -> " + findMaxAverage(new int[]{1, 2}, 3));
    }
}
