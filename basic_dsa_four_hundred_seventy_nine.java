import java.util.HashSet;
import java.util.Set;

/**
 * Basic DSA Problems - One Fundamental Hashing Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_seventy_nine {

    // Problem 1: Contains Duplicate
    // Given an integer array nums, return true if any value appears at least twice in the array,
    // and return false if every element is distinct.
    //
    // Example:
    // nums = [1,2,3,1] -> true
    // nums = [1,2,3,4] -> false

    /**
     * Hash set: first repeated insert fails
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static Boolean containsDuplicate(int[] nums) {
        if (nums == null) {
            return null;
        }

        Set<Integer> seen = new HashSet<>();
        for (int x : nums) {
            if (!seen.add(x)) {
                return true;
            }
        }
        return false;
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
            if (i > 0) {
                sb.append(", ");
            }
            sb.append(arr[i]);
        }
        sb.append("]");
        return sb.toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Contains Duplicate");
        System.out.println("=".repeat(60));

        int[] a1 = {1, 2, 3, 1};
        System.out.println("nums: " + arrayToString(a1));
        System.out.println("Contains duplicate: " + containsDuplicate(a1));

        int[] a2 = {1, 2, 3, 4};
        System.out.println("\nnums: " + arrayToString(a2));
        System.out.println("Contains duplicate: " + containsDuplicate(a2));

        int[] a3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
        System.out.println("\nnums: " + arrayToString(a3));
        System.out.println("Contains duplicate: " + containsDuplicate(a3));

        int[] a4 = {42};
        System.out.println("\nnums: " + arrayToString(a4));
        System.out.println("Contains duplicate: " + containsDuplicate(a4));

        int[] a5 = {};
        System.out.println("\nnums: " + arrayToString(a5));
        System.out.println("Contains duplicate: " + containsDuplicate(a5));

        System.out.println("\nnums: null");
        System.out.println("Contains duplicate: " + containsDuplicate(null));
    }
}
