/**
 * Basic DSA Problems - One Fundamental Prefix Sum Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_thirty_seven {

    // Problem 1: Running Sum of 1d Array
    // Given an array nums, define runningSum[i] as sum(nums[0]...nums[i]).
    // Return the running sum of nums.
    //
    // Example:
    // nums = [1,2,3,4] -> [1,3,6,10]

    /**
     * In-place prefix accumulation
     * Time Complexity: O(n)
     * Space Complexity: O(1) extra
     */
    public static int[] runningSum(int[] nums) {
        if (nums == null) {
            return null;
        }

        for (int i = 1; i < nums.length; i++) {
            nums[i] += nums[i - 1];
        }
        return nums;
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
        System.out.println("Problem 1: Running Sum of 1d Array");
        System.out.println("=".repeat(60));

        int[] a1 = {1, 2, 3, 4};
        System.out.println("nums = [1, 2, 3, 4] -> " + arrayToString(runningSum(a1)));

        int[] a2 = {1, 1, 1, 1, 1};
        System.out.println("nums = [1, 1, 1, 1, 1] -> " + arrayToString(runningSum(a2)));

        int[] a3 = {3, 1, 2, 10, 1};
        System.out.println("nums = [3, 1, 2, 10, 1] -> " + arrayToString(runningSum(a3)));

        int[] a4 = {};
        System.out.println("nums = [] -> " + arrayToString(runningSum(a4)));

        System.out.println("nums = null -> " + arrayToString(runningSum(null)));
    }
}
