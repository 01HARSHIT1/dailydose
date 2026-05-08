import java.util.Arrays;

/**
 * Basic DSA Problems - One Fundamental Carry / Simulation Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_twenty_five {

    // Problem 1: Plus One
    // digits represents a non-negative integer with no leading zeros (MSB first).
    // Add one and return the digits of the result (new array).

    /**
     * Propagate carry from the least significant digit
     * Time Complexity: O(n)
     * Space Complexity: O(n) for the copy or the extra digit when all are 9
     */
    public static int[] plusOne(int[] digits) {
        if (digits == null) {
            return null;
        }

        int n = digits.length;
        int[] a = Arrays.copyOf(digits, n);

        for (int i = n - 1; i >= 0; i--) {
            if (a[i] < 9) {
                a[i]++;
                return a;
            }
            a[i] = 0;
        }

        int[] out = new int[n + 1];
        out[0] = 1;
        return out;
    }

    private static String arrToString(int[] a) {
        if (a == null) {
            return "null";
        }
        return Arrays.toString(a);
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Plus One");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,3] -> " + arrToString(plusOne(new int[] {1, 2, 3})));
        System.out.println("[9] -> " + arrToString(plusOne(new int[] {9})));
        System.out.println("[9,9] -> " + arrToString(plusOne(new int[] {9, 9})));
        System.out.println("[0] -> " + arrToString(plusOne(new int[] {0})));
        System.out.println("null -> " + arrToString(plusOne(null)));
    }
}
