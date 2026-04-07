/**
 * Basic DSA Problems - One Fundamental Array Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_sixty_four {
    
    // Problem 1: Rotate Array (Right Rotate by k)
    // Given an integer array nums, rotate the array to the right by k steps.
    //
    // Approach:
    // - Reverse the whole array
    // - Reverse first k elements
    // - Reverse remaining n-k elements
    //
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    //
    // Example:
    // nums = [1,2,3,4,5,6,7], k = 3 -> [5,6,7,1,2,3,4]
    
    public static void rotateRight(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return;
        }
        
        int n = nums.length;
        k %= n;
        if (k < 0) {
            k += n; // allow negative k as left rotation
        }
        if (k == 0) {
            return;
        }
        
        reverse(nums, 0, n - 1);
        reverse(nums, 0, k - 1);
        reverse(nums, k, n - 1);
    }
    
    private static void reverse(int[] nums, int left, int right) {
        while (left < right) {
            int tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            left++;
            right--;
        }
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
        System.out.println("Problem 1: Rotate Array (Right Rotate by k)");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Classic example
        int[] a1 = {1, 2, 3, 4, 5, 6, 7};
        int k1 = 3;
        System.out.println("Before: " + arrayToString(a1) + ", k = " + k1);
        rotateRight(a1, k1);
        System.out.println("After : " + arrayToString(a1));
        
        // Test Case 2 - k larger than n
        int[] a2 = {1, 2, 3, 4};
        int k2 = 10;
        System.out.println("\nBefore: " + arrayToString(a2) + ", k = " + k2);
        rotateRight(a2, k2);
        System.out.println("After : " + arrayToString(a2));
        
        // Test Case 3 - k = 0
        int[] a3 = {9, 8, 7};
        int k3 = 0;
        System.out.println("\nBefore: " + arrayToString(a3) + ", k = " + k3);
        rotateRight(a3, k3);
        System.out.println("After : " + arrayToString(a3));
        
        // Test Case 4 - Single element
        int[] a4 = {5};
        int k4 = 2;
        System.out.println("\nBefore: " + arrayToString(a4) + ", k = " + k4);
        rotateRight(a4, k4);
        System.out.println("After : " + arrayToString(a4));
        
        // Test Case 5 - Empty array
        int[] a5 = {};
        int k5 = 3;
        System.out.println("\nBefore: " + arrayToString(a5) + ", k = " + k5);
        rotateRight(a5, k5);
        System.out.println("After : " + arrayToString(a5));
        
        // Test Case 6 - Null array
        int[] a6 = null;
        int k6 = 3;
        System.out.println("\nBefore: " + arrayToString(a6) + ", k = " + k6);
        rotateRight(a6, k6);
        System.out.println("After : " + arrayToString(a6));
        
        // Test Case 7 - Negative k (treated as left rotation)
        int[] a7 = {1, 2, 3, 4, 5};
        int k7 = -2;
        System.out.println("\nBefore: " + arrayToString(a7) + ", k = " + k7);
        rotateRight(a7, k7);
        System.out.println("After : " + arrayToString(a7));
    }
}

