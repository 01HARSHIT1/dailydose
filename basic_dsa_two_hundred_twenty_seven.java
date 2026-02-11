/**
 * Basic DSA Problems - Plus One
 * Increment the large integer represented as array of digits
 */
public class basic_dsa_two_hundred_twenty_seven {

    // Problem: digits = number (MSB at index 0). Return digits + 1 (no leading zero except for 0 itself).

    /**
     * Add 1 from right; carry. If carry remains, new array [1] + digits.
     * Time O(n), Space O(n) only when all 9s
     */
    public static int[] plusOne(int[] digits) {
        for (int i = digits.length - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        int[] out = new int[digits.length + 1];
        out[0] = 1;
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Plus One");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,3] -> " + java.util.Arrays.toString(plusOne(new int[]{1, 2, 3})));
        System.out.println("[9,9,9] -> " + java.util.Arrays.toString(plusOne(new int[]{9, 9, 9})));
    }
}
