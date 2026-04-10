/**
 * Basic DSA Problems - One Fundamental Sliding Window Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_eighty_seven {
    
    // Problem 1: Maximum Average Subarray I
    // Given an array nums consisting of n elements and an integer k, find a contiguous subarray
    // of length k that has the maximum average value and return that average.
    //
    // Example:
    // nums = [1,12,-5,-6,50,3], k = 4 -> 12.75
    
    /**
     * Sliding window sum of size k
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
        
        long bestSum = windowSum;
        for (int i = k; i < nums.length; i++) {
            windowSum += nums[i] - nums[i - k];
            if (windowSum > bestSum) {
                bestSum = windowSum;
            }
        }
        
        return bestSum / (double) k;
    }
    
    private static String arrayToString(int[] arr) {
        if (arr == null) return "null";
        if (arr.length == 0) return "[]";
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
        System.out.println("Problem 1: Maximum Average Subarray I");
        System.out.println("=".repeat(60));
        
        int[] a1 = {1, 12, -5, -6, 50, 3};
        int k1 = 4;
        System.out.println("nums: " + arrayToString(a1));
        System.out.println("k: " + k1);
        System.out.println("Max average: " + findMaxAverage(a1, k1));
        
        int[] a2 = {5};
        int k2 = 1;
        System.out.println("\nnums: " + arrayToString(a2));
        System.out.println("k: " + k2);
        System.out.println("Max average: " + findMaxAverage(a2, k2));
        
        int[] a3 = {-1, -2, -3, -4};
        int k3 = 2;
        System.out.println("\nnums: " + arrayToString(a3));
        System.out.println("k: " + k3);
        System.out.println("Max average: " + findMaxAverage(a3, k3));
        
        int[] a4 = {};
        System.out.println("\nnums: " + arrayToString(a4));
        System.out.println("k: 1");
        System.out.println("Max average: " + findMaxAverage(a4, 1));
        
        System.out.println("\nnums: null");
        System.out.println("k: 1");
        System.out.println("Max average: " + findMaxAverage(null, 1));
    }
}

