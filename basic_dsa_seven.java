/**
 * Basic DSA Problems - One Fundamental Array/DP Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_seven {
    
    // Problem 1: Maximum Subarray Sum (Kadane's Algorithm)
    // Given an integer array nums, find the contiguous subarray (containing at least one number)
    // which has the largest sum and return its sum.
    //
    // Example:
    // Input: [-2,1,-3,4,-1,2,1,-5,4] -> 6 (subarray [4,-1,2,1])
    
    /**
     * Kadane's algorithm to find maximum subarray sum
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer maxSubarraySum(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }
        
        int best = nums[0];
        int current = nums[0];
        
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
            if (i > 0) sb.append(", ");
            sb.append(arr[i]);
        }
        sb.append("]");
        return sb.toString();
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Maximum Subarray Sum (Kadane's Algorithm)");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Classic example
        int[] a1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        System.out.println("Array: " + arrayToString(a1));
        System.out.println("Max Subarray Sum: " + maxSubarraySum(a1));
        
        // Test Case 2 - All positive
        int[] a2 = {1, 2, 3, 4};
        System.out.println("\nArray: " + arrayToString(a2));
        System.out.println("Max Subarray Sum: " + maxSubarraySum(a2));
        
        // Test Case 3 - All negative (should pick the largest single element)
        int[] a3 = {-8, -3, -6, -2, -5, -4};
        System.out.println("\nArray: " + arrayToString(a3));
        System.out.println("Max Subarray Sum: " + maxSubarraySum(a3));
        
        // Test Case 4 - Single element
        int[] a4 = {7};
        System.out.println("\nArray: " + arrayToString(a4));
        System.out.println("Max Subarray Sum: " + maxSubarraySum(a4));
        
        // Test Case 5 - Contains zeros
        int[] a5 = {0, -3, 5, -2, 0, 3, -1};
        System.out.println("\nArray: " + arrayToString(a5));
        System.out.println("Max Subarray Sum: " + maxSubarraySum(a5));
        
        // Test Case 6 - Empty array
        int[] a6 = {};
        System.out.println("\nArray: " + arrayToString(a6));
        System.out.println("Max Subarray Sum: " + maxSubarraySum(a6));
        
        // Test Case 7 - Null array
        int[] a7 = null;
        System.out.println("\nArray: " + arrayToString(a7));
        System.out.println("Max Subarray Sum: " + maxSubarraySum(a7));
    }
}
