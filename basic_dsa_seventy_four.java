/**
 * Basic DSA Problems - Majority Element (Boyer-Moore Voting)
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_seventy_four {

    // Problem: Find the majority element — appears more than n/2 times
    // Assume majority always exists
    // Example: [3,2,3] -> 3, [2,2,1,1,1,2,2] -> 2

    /**
     * Boyer-Moore majority vote — O(n) time, O(1) space
     */
    public static int majorityElement(int[] nums) {
        if (nums == null || nums.length == 0) return -1;

        int candidate = nums[0], count = 1;
        for (int i = 1; i < nums.length; i++) {
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            } else if (nums[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }
        return candidate;
    }

    /**
     * Verify that candidate is actually majority (optional check)
     */
    public static boolean isMajority(int[] nums, int candidate) {
        int c = 0;
        for (int x : nums) if (x == candidate) c++;
        return c > nums.length / 2;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Majority Element");
        System.out.println("=".repeat(60));

        int[] a1 = { 3, 2, 3 };
        int m1 = majorityElement(a1);
        System.out.println("Array: " + Arrays.toString(a1) + " -> Majority: " + m1);

        int[] a2 = { 2, 2, 1, 1, 1, 2, 2 };
        int m2 = majorityElement(a2);
        System.out.println("Array: " + Arrays.toString(a2) + " -> Majority: " + m2);

        int[] a3 = { 1 };
        int m3 = majorityElement(a3);
        System.out.println("Array: " + Arrays.toString(a3) + " -> Majority: " + m3);
    }
}
