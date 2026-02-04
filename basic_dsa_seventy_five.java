/**
 * Basic DSA Problems - Contains Duplicate
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_seventy_five {

    // Problem: Given an integer array, return true if any value appears at least twice
    // Example: [1,2,3,1] -> true, [1,2,3,4] -> false

    /**
     * Using HashSet — O(n) time, O(n) space
     */
    public static boolean containsDuplicate(int[] nums) {
        if (nums == null || nums.length <= 1) return false;
        Set<Integer> seen = new HashSet<>();
        for (int x : nums) {
            if (!seen.add(x)) return true;
        }
        return false;
    }

    /**
     * Using sort — O(n log n) time, O(1) space (ignoring sort space)
     */
    public static boolean containsDuplicateSort(int[] nums) {
        if (nums == null || nums.length <= 1) return false;
        int[] copy = nums.clone();
        Arrays.sort(copy);
        for (int i = 1; i < copy.length; i++) {
            if (copy[i] == copy[i - 1]) return true;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Contains Duplicate");
        System.out.println("=".repeat(60));

        int[] a1 = { 1, 2, 3, 1 };
        System.out.println("Array: " + Arrays.toString(a1) + " -> " + containsDuplicate(a1));

        int[] a2 = { 1, 2, 3, 4 };
        System.out.println("Array: " + Arrays.toString(a2) + " -> " + containsDuplicate(a2));

        int[] a3 = { 1, 1, 1, 3, 3, 4, 3, 2, 4, 2 };
        System.out.println("Array: " + Arrays.toString(a3) + " -> " + containsDuplicate(a3));
    }
}
