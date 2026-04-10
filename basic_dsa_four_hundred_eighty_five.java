/**
 * Basic DSA Problems - One Fundamental Two-Pointer Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_eighty_five {
    
    // Problem 1: Two Sum II (Input Array Is Sorted)
    // Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order,
    // find two numbers such that they add up to a specific target number.
    // Return the indices of the two numbers (1-indexed) as an int[2]. If no solution, return null.
    //
    // Example:
    // numbers = [2,7,11,15], target = 9 -> [1,2]
    
    /**
     * Two pointers from both ends
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int[] twoSumSorted(int[] numbers, int target) {
        if (numbers == null || numbers.length < 2) {
            return null;
        }
        
        int left = 0;
        int right = numbers.length - 1;
        
        while (left < right) {
            int sum = numbers[left] + numbers[right];
            if (sum == target) {
                return new int[]{left + 1, right + 1}; // 1-indexed
            } else if (sum < target) {
                left++;
            } else {
                right--;
            }
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
        System.out.println("Problem 1: Two Sum II (Input Array Is Sorted)");
        System.out.println("=".repeat(60));
        
        int[] a1 = {2, 7, 11, 15};
        int t1 = 9;
        System.out.println("numbers: " + arrayToString(a1));
        System.out.println("target: " + t1);
        System.out.println("answer: " + arrayToString(twoSumSorted(a1, t1)));
        
        int[] a2 = {2, 3, 4};
        int t2 = 6;
        System.out.println("\nnumbers: " + arrayToString(a2));
        System.out.println("target: " + t2);
        System.out.println("answer: " + arrayToString(twoSumSorted(a2, t2)));
        
        int[] a3 = {-1, 0};
        int t3 = -1;
        System.out.println("\nnumbers: " + arrayToString(a3));
        System.out.println("target: " + t3);
        System.out.println("answer: " + arrayToString(twoSumSorted(a3, t3)));
        
        int[] a4 = {1, 2, 3, 4, 5};
        int t4 = 10;
        System.out.println("\nnumbers: " + arrayToString(a4));
        System.out.println("target: " + t4);
        System.out.println("answer: " + arrayToString(twoSumSorted(a4, t4)));
        
        int[] a5 = {};
        System.out.println("\nnumbers: " + arrayToString(a5));
        System.out.println("target: 1");
        System.out.println("answer: " + arrayToString(twoSumSorted(a5, 1)));
        
        System.out.println("\nnumbers: null");
        System.out.println("target: 1");
        System.out.println("answer: " + arrayToString(twoSumSorted(null, 1)));
    }
}

