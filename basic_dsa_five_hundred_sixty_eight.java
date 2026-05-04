/**
 * Basic DSA Problems - One Fundamental Array Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_sixty_eight {

    // Problem 1: Third Maximum Number
    // Given an integer array nums, return the third distinct maximum number in this array.
    // If the third maximum does not exist, return the maximum number.
    //
    // Example:
    // nums = [3,2,1] -> 1
    // nums = [1,2] -> 2

    /**
     * Track top three distinct values in one pass
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer thirdMax(int[] nums) {
        if (nums == null || nums.length == 0) {
            return null;
        }

        Long first = null;
        Long second = null;
        Long third = null;

        for (int num : nums) {
            long value = num;
            if ((first != null && value == first)
                    || (second != null && value == second)
                    || (third != null && value == third)) {
                continue;
            }

            if (first == null || value > first) {
                third = second;
                second = first;
                first = value;
            } else if (second == null || value > second) {
                third = second;
                second = value;
            } else if (third == null || value > third) {
                third = value;
            }
        }

        return third == null ? first.intValue() : third.intValue();
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
        System.out.println("Problem 1: Third Maximum Number");
        System.out.println("=".repeat(60));

        int[] a1 = {3, 2, 1};
        System.out.println("nums = " + arrayToString(a1) + " -> " + thirdMax(a1));

        int[] a2 = {1, 2};
        System.out.println("nums = " + arrayToString(a2) + " -> " + thirdMax(a2));

        int[] a3 = {2, 2, 3, 1};
        System.out.println("nums = " + arrayToString(a3) + " -> " + thirdMax(a3));

        int[] a4 = {1, 2, Integer.MIN_VALUE};
        System.out.println("nums = " + arrayToString(a4) + " -> " + thirdMax(a4));

        System.out.println("nums = null -> " + thirdMax(null));
    }
}
