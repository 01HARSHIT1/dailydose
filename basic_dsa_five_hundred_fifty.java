/**
 * Basic DSA Problems - One Fundamental Array + Math Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_fifty {

    // Problem 1: Missing Number
    // Given an array nums containing n distinct numbers in the range [0, n],
    // return the only number in the range that is missing from the array.
    //
    // Example:
    // nums = [3,0,1] -> 2

    /**
     * Sum formula approach
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer missingNumber(int[] nums) {
        if (nums == null) {
            return null;
        }

        int n = nums.length;
        int expected = n * (n + 1) / 2;
        int actual = 0;
        for (int num : nums) {
            actual += num;
        }

        return expected - actual;
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
        System.out.println("Problem 1: Missing Number");
        System.out.println("=".repeat(60));

        int[] a1 = {3, 0, 1};
        System.out.println("nums = " + arrayToString(a1) + " -> " + missingNumber(a1));

        int[] a2 = {0, 1};
        System.out.println("nums = " + arrayToString(a2) + " -> " + missingNumber(a2));

        int[] a3 = {9, 6, 4, 2, 3, 5, 7, 0, 1};
        System.out.println("nums = " + arrayToString(a3) + " -> " + missingNumber(a3));

        int[] a4 = {};
        System.out.println("nums = " + arrayToString(a4) + " -> " + missingNumber(a4));

        System.out.println("nums = null -> " + missingNumber(null));
    }
}
