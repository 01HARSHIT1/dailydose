/**
 * Basic DSA Problems - One Fundamental Two-Pointer Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_sixty_five {
    
    // Problem 1: Remove Duplicates from Sorted Array
    // Given a sorted integer array nums, remove the duplicates in-place such that each unique
    // element appears only once. Return the number of unique elements.
    //
    // Approach: Two pointers
    // Time Complexity: O(n)
    // Space Complexity: O(1)
    //
    // Example:
    // nums = [0,0,1,1,1,2,2,3,3,4] -> k = 5, nums starts with [0,1,2,3,4,...]
    
    public static Integer removeDuplicates(int[] nums) {
        if (nums == null) {
            return null;
        }
        if (nums.length == 0) {
            return 0;
        }
        
        int write = 1;
        for (int read = 1; read < nums.length; read++) {
            if (nums[read] != nums[write - 1]) {
                nums[write] = nums[read];
                write++;
            }
        }
        
        return write;
    }
    
    private static String arrayToStringPrefix(int[] arr, int k) {
        if (arr == null) return "null";
        if (k <= 0) return "[]";
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < k && i < arr.length; i++) {
            if (i > 0) sb.append(", ");
            sb.append(arr[i]);
        }
        sb.append("]");
        return sb.toString();
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Remove Duplicates from Sorted Array");
        System.out.println("=".repeat(60));
        
        // Test Case 1 - Typical case
        int[] a1 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
        Integer k1 = removeDuplicates(a1);
        System.out.println("k = " + k1);
        System.out.println("Unique prefix: " + arrayToStringPrefix(a1, k1 != null ? k1 : 0));
        
        // Test Case 2 - Already unique
        int[] a2 = {1, 2, 3, 4};
        Integer k2 = removeDuplicates(a2);
        System.out.println("\nk = " + k2);
        System.out.println("Unique prefix: " + arrayToStringPrefix(a2, k2 != null ? k2 : 0));
        
        // Test Case 3 - All duplicates
        int[] a3 = {7, 7, 7, 7};
        Integer k3 = removeDuplicates(a3);
        System.out.println("\nk = " + k3);
        System.out.println("Unique prefix: " + arrayToStringPrefix(a3, k3 != null ? k3 : 0));
        
        // Test Case 4 - Single element
        int[] a4 = {5};
        Integer k4 = removeDuplicates(a4);
        System.out.println("\nk = " + k4);
        System.out.println("Unique prefix: " + arrayToStringPrefix(a4, k4 != null ? k4 : 0));
        
        // Test Case 5 - Empty array
        int[] a5 = {};
        Integer k5 = removeDuplicates(a5);
        System.out.println("\nk = " + k5);
        System.out.println("Unique prefix: " + arrayToStringPrefix(a5, k5 != null ? k5 : 0));
        
        // Test Case 6 - Null
        int[] a6 = null;
        Integer k6 = removeDuplicates(a6);
        System.out.println("\nk = " + k6);
        System.out.println("Unique prefix: " + arrayToStringPrefix(a6, 0));
    }
}

