/**
 * Basic DSA Problems - One Fundamental Array + Hashing Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_thirty {

    // Problem 1: Contains Duplicate
    // Given an integer array nums, return true if any value appears at least twice in the array,
    // and return false if every element is distinct.
    //
    // Example:
    // nums = [1,2,3,1] -> true
    // nums = [1,2,3,4] -> false

    /**
     * Use a hash set to track seen values
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static Boolean containsDuplicate(int[] nums) {
        if (nums == null) {
            return null;
        }

        java.util.HashSet<Integer> seen = new java.util.HashSet<>();
        for (int num : nums) {
            if (seen.contains(num)) {
                return true;
            }
            seen.add(num);
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

        int[] nums1 = {1, 2, 3, 1};
        System.out.println("nums = " + arrayToString(nums1) + " -> " + containsDuplicate(nums1));

        int[] nums2 = {1, 2, 3, 4};
        System.out.println("nums = " + arrayToString(nums2) + " -> " + containsDuplicate(nums2));

        int[] nums3 = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
        System.out.println("nums = " + arrayToString(nums3) + " -> " + containsDuplicate(nums3));

        int[] nums4 = {};
        System.out.println("nums = " + arrayToString(nums4) + " -> " + containsDuplicate(nums4));

        System.out.println("nums = null -> " + containsDuplicate(null));
    }
}
