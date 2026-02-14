/**
 * Basic DSA Problems - Contains Duplicate
 * Check if array contains any duplicate element
 */
public class basic_dsa_two_hundred_ninety_six {

    // Problem: Given integer array nums, return true if any value appears at least twice.

    /**
     * Use HashSet to track seen elements.
     * Time O(n), Space O(n)
     */
    public static boolean containsDuplicate(int[] nums) {
        java.util.Set<Integer> seen = new java.util.HashSet<>();
        for (int n : nums) {
            if (seen.contains(n)) return true;
            seen.add(n);
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Contains Duplicate");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,3,1] -> " + containsDuplicate(new int[]{1, 2, 3, 1}));
        System.out.println("[1,2,3,4] -> " + containsDuplicate(new int[]{1, 2, 3, 4}));
        System.out.println("[1,1,1,3,3,4,3,2,4,2] -> " + containsDuplicate(new int[]{1, 1, 1, 3, 3, 4, 3, 2, 4, 2}));
    }
}
