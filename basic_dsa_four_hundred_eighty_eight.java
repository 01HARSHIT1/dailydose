/**
 * Basic DSA Problems - One Fundamental Array Two-Pointer Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_eighty_eight {
    
    // Problem 1: Merge Sorted Array
    // You are given two integer arrays nums1 and nums2, sorted in non-decreasing order,
    // and two integers m and n, representing the number of elements in nums1 and nums2 respectively.
    // Merge nums2 into nums1 as one sorted array. nums1 has size m + n, with the last n elements as 0 placeholders.
    //
    // Example:
    // nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3 -> [1,2,2,3,5,6]
    
    /**
     * Merge from the back using two pointers
     * Time Complexity: O(m + n)
     * Space Complexity: O(1)
     */
    public static boolean mergeSorted(int[] nums1, int m, int[] nums2, int n) {
        if (nums1 == null || nums2 == null) {
            return false;
        }
        if (m < 0 || n < 0 || m + n != nums1.length || n != nums2.length) {
            return false;
        }
        
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        
        return true;
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
    
    private static int[] copyOf(int[] src) {
        if (src == null) return null;
        int[] out = new int[src.length];
        System.arraycopy(src, 0, out, 0, src.length);
        return out;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Merge Sorted Array");
        System.out.println("=".repeat(60));
        
        // Test Case 1
        int[] a1 = {1, 2, 3, 0, 0, 0};
        int[] b1 = {2, 5, 6};
        int[] t1 = copyOf(a1);
        System.out.println("nums1 before: " + arrayToString(t1) + ", m=3");
        System.out.println("nums2      : " + arrayToString(b1) + ", n=3");
        System.out.println("ok: " + mergeSorted(t1, 3, b1, 3));
        System.out.println("nums1 after : " + arrayToString(t1));
        
        // Test Case 2 - nums2 empty
        int[] a2 = {1};
        int[] b2 = {};
        int[] t2 = copyOf(a2);
        System.out.println("\nnums1 before: " + arrayToString(t2) + ", m=1");
        System.out.println("nums2      : " + arrayToString(b2) + ", n=0");
        System.out.println("ok: " + mergeSorted(t2, 1, b2, 0));
        System.out.println("nums1 after : " + arrayToString(t2));
        
        // Test Case 3 - nums1 has no initial elements
        int[] a3 = {0, 0, 0};
        int[] b3 = {2, 5, 6};
        int[] t3 = copyOf(a3);
        System.out.println("\nnums1 before: " + arrayToString(t3) + ", m=0");
        System.out.println("nums2      : " + arrayToString(b3) + ", n=3");
        System.out.println("ok: " + mergeSorted(t3, 0, b3, 3));
        System.out.println("nums1 after : " + arrayToString(t3));
        
        // Test Case 4 - invalid lengths
        int[] a4 = {1, 0};
        int[] b4 = {2};
        int[] t4 = copyOf(a4);
        System.out.println("\nnums1 before: " + arrayToString(t4) + ", m=1");
        System.out.println("nums2      : " + arrayToString(b4) + ", n=1");
        System.out.println("ok: " + mergeSorted(t4, 0, b4, 1)); // invalid m
        System.out.println("nums1 after : " + arrayToString(t4));
        
        // Test Case 5 - null input
        System.out.println("\nnums1: null, nums2: [1]");
        System.out.println("ok: " + mergeSorted(null, 0, new int[]{1}, 1));
    }
}

