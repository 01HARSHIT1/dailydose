/**
 * Basic DSA Problems - Reverse Integer
 * Reverse digits of a 32-bit signed integer, return 0 if overflow
 */
public class basic_dsa_one_hundred_thirty_one {

    // Problem: Given a signed 32-bit integer x, return x with its digits reversed.
    // If reversing causes overflow (outside [-2^31, 2^31-1]), return 0.
    // Example: 123 -> 321, -123 -> -321, 120 -> 21

    /**
     * Reverse digits using modulo and multiplication.
     * Check overflow before it happens: if result > Integer.MAX_VALUE/10 or < Integer.MIN_VALUE/10
     * Time O(log n), Space O(1)
     */
    public static int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int digit = x % 10;
            x /= 10;
            if (rev > Integer.MAX_VALUE / 10 || (rev == Integer.MAX_VALUE / 10 && digit > 7)) return 0;
            if (rev < Integer.MIN_VALUE / 10 || (rev == Integer.MIN_VALUE / 10 && digit < -8)) return 0;
            rev = rev * 10 + digit;
        }
        return rev;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Reverse Integer");
        System.out.println("=".repeat(60));

        System.out.println("123 -> " + reverse(123));
        System.out.println("-123 -> " + reverse(-123));
        System.out.println("120 -> " + reverse(120));
        System.out.println("0 -> " + reverse(0));
        System.out.println("1534236469 (overflow) -> " + reverse(1534236469));
    }
}
