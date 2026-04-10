/**
 * Basic DSA Problems - One Fundamental Hashing Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_ninety_one {
    
    // Problem 1: Two Sum
    // Given an array of integers nums and an integer target, return indices of the two numbers
    // such that they add up to target. Return null if no solution.
    //
    // Example:
    // nums = [2,7,11,15], target = 9 -> [0,1]
    
    /**
     * Hash map from value -> index
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static int[] twoSum(int[] nums, int target) {
        if (nums == null) {
            return null;
        }
        
        java.util.HashMap<Integer, Integer> seen = new java.util.HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int need = target - nums[i];
            Integer j = seen.get(need);
            if (j != null) {
                return new int[]{j, i};
            }
            seen.put(nums[i], i);
        }
        
        return null;
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
        System.out.println("Problem 1: Two Sum");
        System.out.println("=".repeat(60));
        
        int[] a1 = {2, 7, 11, 15};
        int t1 = 9;
        System.out.println("nums: " + arrayToString(a1));
        System.out.println("target: " + t1);
        System.out.println("answer: " + arrayToString(twoSum(a1, t1)));
        
        int[] a2 = {3, 2, 4};
        int t2 = 6;
        System.out.println("\nnums: " + arrayToString(a2));
        System.out.println("target: " + t2);
        System.out.println("answer: " + arrayToString(twoSum(a2, t2)));
        
        int[] a3 = {3, 3};
        int t3 = 6;
        System.out.println("\nnums: " + arrayToString(a3));
        System.out.println("target: " + t3);
        System.out.println("answer: " + arrayToString(twoSum(a3, t3)));
        
        int[] a4 = {1, 2, 3};
        int t4 = 10;
        System.out.println("\nnums: " + arrayToString(a4));
        System.out.println("target: " + t4);
        System.out.println("answer: " + arrayToString(twoSum(a4, t4)));
        
        int[] a5 = {};
        System.out.println("\nnums: " + arrayToString(a5));
        System.out.println("target: 1");
        System.out.println("answer: " + arrayToString(twoSum(a5, 1)));
        
        System.out.println("\nnums: null");
        System.out.println("target: 1");
        System.out.println("answer: " + arrayToString(twoSum(null, 1)));
    }
}

