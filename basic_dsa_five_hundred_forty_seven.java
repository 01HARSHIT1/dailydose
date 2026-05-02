/**
 * Basic DSA Problems - One Fundamental Array Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_forty_seven {

    // Problem 1: Plus One
    // You are given a large integer represented as an integer array digits,
    // where each digits[i] is the i-th digit of the integer.
    //
    // Increment the large integer by one and return the resulting array of digits.
    //
    // Example:
    // digits = [1,2,3] -> [1,2,4]
    // digits = [9,9]   -> [1,0,0]

    /**
     * Add one from right to left, handle carry
     * Time Complexity: O(n)
     * Space Complexity: O(1) or O(n) only when all digits are 9
     */
    public static int[] plusOne(int[] digits) {
        if (digits == null || digits.length == 0) {
            return null;
        }

        for (int i = digits.length - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }

        int[] result = new int[digits.length + 1];
        result[0] = 1;
        return result;
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
        System.out.println("Problem 1: Plus One");
        System.out.println("=".repeat(60));

        int[] a1 = {1, 2, 3};
        System.out.println("digits = [1,2,3] -> " + arrayToString(plusOne(a1)));

        int[] a2 = {4, 3, 2, 1};
        System.out.println("digits = [4,3,2,1] -> " + arrayToString(plusOne(a2)));

        int[] a3 = {9};
        System.out.println("digits = [9] -> " + arrayToString(plusOne(a3)));

        int[] a4 = {9, 9, 9};
        System.out.println("digits = [9,9,9] -> " + arrayToString(plusOne(a4)));

        System.out.println("digits = null -> " + arrayToString(plusOne(null)));
    }
}
