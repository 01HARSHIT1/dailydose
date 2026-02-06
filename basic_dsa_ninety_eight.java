/**
 * Basic DSA Problems - Two Sum
 * Find two indices such that their values add up to target
 */
import java.util.*;

public class basic_dsa_ninety_eight {

    // Problem: Given an array of integers nums and target, return indices of the two numbers
    // such that they add up to target. Assume exactly one solution exists.

    /**
     * One pass: store (value -> index) in map; for each num check if (target - num) exists.
     * Time O(n), Space O(n)
     */
    public static int[] twoSum(int[] nums, int target) {
        if (nums == null || nums.length < 2) return new int[] { -1, -1 };
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            int need = target - nums[i];
            if (map.containsKey(need)) {
                return new int[] { map.get(need), i };
            }
            map.put(nums[i], i);
        }
        return new int[] { -1, -1 };
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Two Sum");
        System.out.println("=".repeat(60));

        int[] a = { 2, 7, 11, 15 };
        int[] r1 = twoSum(a, 9);
        System.out.println("nums = [2,7,11,15], target = 9 -> " + Arrays.toString(r1));

        int[] b = { 3, 2, 4 };
        int[] r2 = twoSum(b, 6);
        System.out.println("nums = [3,2,4], target = 6 -> " + Arrays.toString(r2));

        int[] c = { 3, 3 };
        int[] r3 = twoSum(c, 6);
        System.out.println("nums = [3,3], target = 6 -> " + Arrays.toString(r3));
    }
}
