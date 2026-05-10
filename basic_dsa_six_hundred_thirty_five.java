/**
 * Basic DSA Problems - One Fundamental Integer Math Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_thirty_five {

    // Problem 1: Reverse Integer
    // Reverse decimal digits of x; if result is outside 32-bit signed range, return 0.

    /**
     * Pop digits from right; push onto result; check bounds before each multiply-add
     * Time Complexity: O(log10 |x|)
     * Space Complexity: O(1)
     */
    public static int reverse(int x) {
        int result = 0;
        int n = x;

        while (n != 0) {
            int digit = n % 10;
            n /= 10;

            if (result > Integer.MAX_VALUE / 10 || (result == Integer.MAX_VALUE / 10 && digit > 7)) {
                return 0;
            }
            if (result < Integer.MIN_VALUE / 10 || (result == Integer.MIN_VALUE / 10 && digit < -8)) {
                return 0;
            }

            result = result * 10 + digit;
        }

        return result;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Reverse Integer");
        System.out.println("=".repeat(60));

        System.out.println("123 -> " + reverse(123));
        System.out.println("-123 -> " + reverse(-123));
        System.out.println("120 -> " + reverse(120));
        System.out.println("1534236469 -> " + reverse(1534236469));
        System.out.println("0 -> " + reverse(0));
    }
}
