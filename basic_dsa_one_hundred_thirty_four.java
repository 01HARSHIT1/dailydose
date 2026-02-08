/**
 * Basic DSA Problems - Plus One
 * Add 1 to a number represented as array of digits
 */
import java.util.Arrays;

public class basic_dsa_one_hundred_thirty_four {

    // Problem: Given array of digits representing a non-negative integer, add 1.
    // Most significant digit is at index 0. No leading zeros except for 0 itself.
    // Example: [1,2,3] -> [1,2,4], [9,9] -> [1,0,0]

    /**
     * Add 1 from right. If digit < 9, add and return. Else set 0 and carry.
     * If all 9s, create new array of length+1 with leading 1.
     * Time O(n), Space O(1) or O(n) if carry propagates to new digit
     */
    public static int[] plusOne(int[] digits) {
        if (digits == null || digits.length == 0) return new int[] { 1 };
        for (int i = digits.length - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            digits[i] = 0;
        }
        int[] ans = new int[digits.length + 1];
        ans[0] = 1;
        return ans;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Plus One");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,3] -> " + Arrays.toString(plusOne(new int[] { 1, 2, 3 })));
        System.out.println("[9,9] -> " + Arrays.toString(plusOne(new int[] { 9, 9 })));
        System.out.println("[0] -> " + Arrays.toString(plusOne(new int[] { 0 })));
        System.out.println("[9] -> " + Arrays.toString(plusOne(new int[] { 9 })));
    }
}
