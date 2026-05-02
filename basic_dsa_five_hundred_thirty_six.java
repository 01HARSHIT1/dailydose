/**
 * Basic DSA Problems - One Fundamental Array Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_thirty_six {

    // Problem 1: Majority Element
    // Given an array nums of size n, return the majority element.
    // The majority element is the element that appears more than n / 2 times.
    // You may assume that the majority element always exists in the array.
    //
    // Example:
    // nums = [3,2,3] -> 3

    /**
     * Boyer-Moore voting algorithm
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer majorityElement(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }

        int candidate = nums[0];
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            if (num == candidate) {
                count++;
            } else {
                count--;
            }
        }

        return candidate;
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

        int[] a1 = {3, 2, 3};
        System.out.println("nums = " + arrayToString(a1) + " -> " + majorityElement(a1));

        int[] a2 = {2, 2, 1, 1, 1, 2, 2};
        System.out.println("nums = " + arrayToString(a2) + " -> " + majorityElement(a2));

        int[] a3 = {1};
        System.out.println("nums = " + arrayToString(a3) + " -> " + majorityElement(a3));

        int[] a4 = {};
        System.out.println("nums = " + arrayToString(a4) + " -> " + majorityElement(a4));

        System.out.println("nums = null -> " + majorityElement(null));
    }
}
