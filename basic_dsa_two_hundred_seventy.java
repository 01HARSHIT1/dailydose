/**
 * Basic DSA Problems - Contains Duplicate
 * Check if array has any duplicate elements
 */
public class basic_dsa_two_hundred_seventy {

    // Problem: Return true if nums contains any value that appears at least twice.

    /**
     * Use HashSet. If add returns false, duplicate found.
     * Time O(n), Space O(n)
     */
    public static boolean containsDuplicate(int[] nums) {
        java.util.Set<Integer> set = new java.util.HashSet<>();
        for (int x : nums)
            if (!set.add(x)) return true;
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
