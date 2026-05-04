/**
 * Basic DSA Problems - One Fundamental Hashing + Sliding Window Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_sixty_two {

    // Problem 1: Contains Duplicate II
    // Given an integer array nums and an integer k, return true if there are two distinct indices
    // i and j such that nums[i] == nums[j] and abs(i - j) <= k.
    //
    // Example:
    // nums = [1,2,3,1], k = 3 -> true

    /**
     * Track the most recent index for each value
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static Boolean containsNearbyDuplicate(int[] nums, int k) {
        if (nums == null || k < 0) {
            return null;
        }

        java.util.HashMap<Integer, Integer> lastIndex = new java.util.HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            Integer prev = lastIndex.get(nums[i]);
            if (prev != null && i - prev <= k) {
                return true;
            }
            lastIndex.put(nums[i], i);
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
        System.out.println("Problem 1: Contains Duplicate II");
        System.out.println("=".repeat(60));

        int[] a1 = {1, 2, 3, 1};
        System.out.println("nums = " + arrayToString(a1) + ", k = 3 -> " + containsNearbyDuplicate(a1, 3));

        int[] a2 = {1, 0, 1, 1};
        System.out.println("nums = " + arrayToString(a2) + ", k = 1 -> " + containsNearbyDuplicate(a2, 1));

        int[] a3 = {1, 2, 3, 1, 2, 3};
        System.out.println("nums = " + arrayToString(a3) + ", k = 2 -> " + containsNearbyDuplicate(a3, 2));

        int[] a4 = {};
        System.out.println("nums = " + arrayToString(a4) + ", k = 0 -> " + containsNearbyDuplicate(a4, 0));

        System.out.println("nums = null, k = 1 -> " + containsNearbyDuplicate(null, 1));
    }
}
