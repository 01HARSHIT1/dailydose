/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_seventy_one {

    // Problem: Contains Duplicate
    // Given an integer array, return true if any value appears at least twice.
    // Example: [1,2,3,1] -> true, [1,2,3,4] -> false

    /**
     * Check if array contains any duplicate
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static boolean containsDuplicate(int[] nums) {
        if (nums == null || nums.length < 2) return false;
        Set<Integer> seen = new HashSet<>();
        for (int n : nums) {
            if (!seen.add(n)) return true;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Contains Duplicate");
        System.out.println("=".repeat(60));

        int[] a1 = { 1, 2, 3, 1 };
        System.out.println("nums = " + Arrays.toString(a1) + " -> " + containsDuplicate(a1));

        int[] a2 = { 1, 2, 3, 4 };
        System.out.println("nums = " + Arrays.toString(a2) + " -> " + containsDuplicate(a2));

        int[] a3 = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
        System.out.println("nums = " + Arrays.toString(a3) + " -> " + containsDuplicate(a3));
    }
}
