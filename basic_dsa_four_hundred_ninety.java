/**
 * Basic DSA Problems - One Fundamental Prefix Sum Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_ninety {
    
    // Problem 1: Range Sum Query - Immutable
    // Given an integer array nums, handle multiple queries of the form:
    // sumRange(left, right) = sum of elements nums[left..right] (inclusive).
    //
    // Approach: prefix sums
    // Time per query: O(1), Preprocessing: O(n)
    //
    // Example:
    // nums = [-2, 0, 3, -5, 2, -1]
    // sumRange(0,2) -> 1
    // sumRange(2,5) -> -1
    // sumRange(0,5) -> -3
    
    public static class NumArray {
        private final long[] prefix; // prefix[i+1] = sum of nums[0..i]
        
        public NumArray(int[] nums) {
            if (nums == null) {
                this.prefix = null;
                return;
            }
            this.prefix = new long[nums.length + 1];
            for (int i = 0; i < nums.length; i++) {
                this.prefix[i + 1] = this.prefix[i] + nums[i];
            }
        }
        
        public Long sumRange(int left, int right) {
            if (prefix == null) {
                return null;
            }
            if (left < 0 || right < 0 || left > right || right >= prefix.length - 1) {
                return null;
            }
            return prefix[right + 1] - prefix[left];
        }
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
        System.out.println("Problem 1: Range Sum Query - Immutable");
        System.out.println("=".repeat(60));
        
        int[] nums = {-2, 0, 3, -5, 2, -1};
        System.out.println("nums: " + arrayToString(nums));
        
        NumArray na = new NumArray(nums);
        System.out.println("sumRange(0, 2): " + na.sumRange(0, 2));
        System.out.println("sumRange(2, 5): " + na.sumRange(2, 5));
        System.out.println("sumRange(0, 5): " + na.sumRange(0, 5));
        
        // Edge cases
        System.out.println("\nsumRange(0, 0): " + na.sumRange(0, 0));
        System.out.println("sumRange(5, 5): " + na.sumRange(5, 5));
        System.out.println("sumRange(-1, 2): " + na.sumRange(-1, 2));
        System.out.println("sumRange(2, 6): " + na.sumRange(2, 6));
        System.out.println("sumRange(4, 3): " + na.sumRange(4, 3));
        
        System.out.println("\nnums: null");
        NumArray nb = new NumArray(null);
        System.out.println("sumRange(0, 0): " + nb.sumRange(0, 0));
    }
}

