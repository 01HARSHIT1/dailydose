/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_sixty_six {

    // Problem: Majority Element (Boyer–Moore majority vote)
    // Find the element that appears more than n/2 times in the array.
    // Assume majority element always exists.
    // Example: [3,2,3] -> 3, [2,2,1,1,1,2,2] -> 2

    /**
     * Find majority element using Boyer-Moore voting
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int majorityElement(int[] nums) {
        if (nums == null || nums.length == 0) {
            throw new IllegalArgumentException("array is empty");
        }
        int candidate = nums[0];
        int count = 1;
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

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Majority Element");
        System.out.println("=".repeat(60));

        int[] a1 = { 3, 2, 3 };
        System.out.println("Array: " + Arrays.toString(a1) + " -> " + majorityElement(a1));

        int[] a2 = { 2, 2, 1, 1, 1, 2, 2 };
        System.out.println("Array: " + Arrays.toString(a2) + " -> " + majorityElement(a2));

        int[] a3 = { 6, 5, 5 };
        System.out.println("Array: " + Arrays.toString(a3) + " -> " + majorityElement(a3));
    }
}
