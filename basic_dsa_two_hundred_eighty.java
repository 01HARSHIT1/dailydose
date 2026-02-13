/**
 * Basic DSA Problems - Contains Duplicate II
 * Check if duplicate exists within k distance
 */
public class basic_dsa_two_hundred_eighty {

    // Problem: Return true if nums has duplicate values with indices difference <= k.

    /**
     * Sliding window + HashSet. Keep k recent elements. If add fails, duplicate in window.
     * Time O(n), Space O(min(n,k))
     */
    public static boolean containsNearbyDuplicate(int[] nums, int k) {
        java.util.Set<Integer> set = new java.util.HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            if (i > k) set.remove(nums[i - k - 1]);
            if (!set.add(nums[i])) return true;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Contains Duplicate II");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,3,1], k=3 -> " + containsNearbyDuplicate(new int[]{1, 2, 3, 1}, 3));
        System.out.println("[1,0,1,1], k=1 -> " + containsNearbyDuplicate(new int[]{1, 0, 1, 1}, 1));
        System.out.println("[1,2,3,1,2,3], k=2 -> " + containsNearbyDuplicate(new int[]{1, 2, 3, 1, 2, 3}, 2));
    }
}
