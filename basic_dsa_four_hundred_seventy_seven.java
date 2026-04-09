/**
 * Basic DSA Problems - One Fundamental Array Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_seventy_seven {

    // Problem 1: Majority Element
    // Given an array nums of size n, return the element that appears more than n / 2 times.
    // You may assume the majority element always exists in the input (LeetCode-style).
    // If no majority exists, this implementation returns null after verification.
    //
    // Example:
    // nums = [2,2,1,1,1,2,2] -> 2

    /**
     * Boyer–Moore voting algorithm, then verify frequency
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer majorityElement(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }

        int candidate = nums[0];
        int count = 0;

        for (int x : nums) {
            if (count == 0) {
                candidate = x;
            }
            count += (x == candidate) ? 1 : -1;
        }

        int freq = 0;
        for (int x : nums) {
            if (x == candidate) {
                freq++;
            }
        }

        return freq > nums.length / 2 ? candidate : null;
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
        System.out.println("Problem 1: Majority Element");
        System.out.println("=".repeat(60));

        int[] a1 = {2, 2, 1, 1, 1, 2, 2};
        System.out.println("nums: " + arrayToString(a1));
        System.out.println("Majority: " + majorityElement(a1));

        int[] a2 = {3, 2, 3};
        System.out.println("\nnums: " + arrayToString(a2));
        System.out.println("Majority: " + majorityElement(a2));

        int[] a3 = {1};
        System.out.println("\nnums: " + arrayToString(a3));
        System.out.println("Majority: " + majorityElement(a3));

        int[] a4 = {1, 2, 3};
        System.out.println("\nnums: " + arrayToString(a4));
        System.out.println("Majority: " + majorityElement(a4));

        int[] a5 = {};
        System.out.println("\nnums: " + arrayToString(a5));
        System.out.println("Majority: " + majorityElement(a5));

        System.out.println("\nnums: null");
        System.out.println("Majority: " + majorityElement(null));
    }
}
