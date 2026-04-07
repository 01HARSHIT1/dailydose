/**
 * Basic DSA Problems - One Fundamental Array/Math Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_sixty_nine {

    // Problem 1: Plus One
    // You are given a large integer represented as an integer array digits,
    // where digits[i] is the ith digit (0–9). The digits are ordered from most significant to least.
    // Increment the integer by one and return the resulting array of digits.
    //
    // Example:
    // digits = [1,2,3] -> [1,2,4]
    // digits = [9] -> [1,0]

    /**
     * Simulate carry from the right; extend array if needed
     * Time Complexity: O(n)
     * Space Complexity: O(1) extra excluding output (may allocate new array of length n+1)
     */
    public static int[] plusOne(int[] digits) {
        if (digits == null || digits.length == 0) {
            return null;
        }

        int n = digits.length;
        int[] result = new int[n];
        int carry = 1;

        for (int i = n - 1; i >= 0; i--) {
            int sum = digits[i] + carry;
            result[i] = sum % 10;
            carry = sum / 10;
        }

        if (carry == 0) {
            return result;
        }

        int[] extended = new int[n + 1];
        extended[0] = carry;
        System.arraycopy(result, 0, extended, 1, n);
        return extended;
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

        int[] d1 = {1, 2, 3};
        System.out.println("Before: " + arrayToString(d1));
        System.out.println("After : " + arrayToString(plusOne(d1)));

        int[] d2 = {9};
        System.out.println("\nBefore: " + arrayToString(d2));
        System.out.println("After : " + arrayToString(plusOne(d2)));

        int[] d3 = {9, 9, 9};
        System.out.println("\nBefore: " + arrayToString(d3));
        System.out.println("After : " + arrayToString(plusOne(d3)));

        int[] d4 = {0};
        System.out.println("\nBefore: " + arrayToString(d4));
        System.out.println("After : " + arrayToString(plusOne(d4)));

        int[] d5 = {};
        System.out.println("\nBefore: " + arrayToString(d5));
        System.out.println("After : " + arrayToString(plusOne(d5)));

        System.out.println("\nBefore: null");
        System.out.println("After : " + arrayToString(plusOne(null)));
    }
}
