/**
 * Basic DSA Problems - One Fundamental Array + Hashing Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_twenty_five {

    // Problem 1: Two Sum
    // Given an array of integers nums and an integer target, return indices of the two numbers
    // such that they add up to target.
    //
    // You may assume that each input has exactly one solution, and you may not use the same
    // element twice.
    //
    // Example:
    // nums = [2,7,11,15], target = 9 -> [0,1]

    /**
     * One-pass hash table storing value -> index
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static int[] twoSum(int[] nums, int target) {
        if (nums == null) {
            return null;
        }

        java.util.HashMap<Integer, Integer> seen = new java.util.HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (seen.containsKey(complement)) {
                return new int[]{seen.get(complement), i};
            }
            seen.put(nums[i], i);
        }

        return null;
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
        System.out.println("Problem 1: Two Sum");
        System.out.println("=".repeat(60));

        int[] nums1 = {2, 7, 11, 15};
        System.out.println("nums = " + arrayToString(nums1) + ", target = 9 -> "
                + arrayToString(twoSum(nums1, 9)));

        int[] nums2 = {3, 2, 4};
        System.out.println("nums = " + arrayToString(nums2) + ", target = 6 -> "
                + arrayToString(twoSum(nums2, 6)));

        int[] nums3 = {3, 3};
        System.out.println("nums = " + arrayToString(nums3) + ", target = 6 -> "
                + arrayToString(twoSum(nums3, 6)));

        System.out.println("nums = null, target = 10 -> " + arrayToString(twoSum(null, 10)));
    }
}
