/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_sixty_nine {

    // Problem: Two Sum
    // Given an array of integers and a target, return indices of two numbers that add up to target.
    // Assume exactly one solution exists; same element may not be used twice.
    // Example: nums = [2,7,11,15], target = 9 -> [0, 1]

    /**
     * Find two indices such that nums[i] + nums[j] = target
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static int[] twoSum(int[] nums, int target) {
        if (nums == null || nums.length < 2) return new int[0];
        Map<Integer, Integer> seen = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int need = target - nums[i];
            if (seen.containsKey(need)) {
                return new int[] { seen.get(need), i };
            }
            seen.put(nums[i], i);
        }
        return new int[0];
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Two Sum");
        System.out.println("=".repeat(60));

        int[] nums1 = { 2, 7, 11, 15 };
        int target1 = 9;
        System.out.println("nums = " + Arrays.toString(nums1) + ", target = " + target1);
        System.out.println(" -> " + Arrays.toString(twoSum(nums1, target1)));

        int[] nums2 = { 3, 2, 4 };
        int target2 = 6;
        System.out.println("nums = " + Arrays.toString(nums2) + ", target = " + target2);
        System.out.println(" -> " + Arrays.toString(twoSum(nums2, target2)));

        int[] nums3 = { 3, 3 };
        int target3 = 6;
        System.out.println("nums = " + Arrays.toString(nums3) + ", target = " + target3);
        System.out.println(" -> " + Arrays.toString(twoSum(nums3, target3)));
    }
}
