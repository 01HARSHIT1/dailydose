/**
 * Basic DSA Problems - One Fundamental Binary Exponentiation Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_twenty_eight {

    // Problem 1: Pow(x, n)
    // Implement x raised to the integer n. Use binary exponentiation (O(log |n|)).

    /**
     * Exponentiation by squaring; treat exponent as long to handle Integer.MIN_VALUE
     * Time Complexity: O(log |n|)
     * Space Complexity: O(1)
     */
    public static double myPow(double x, int n) {
        if (n == 0) {
            return 1.0;
        }

        long exp = n;
        if (exp < 0) {
            x = 1.0 / x;
            exp = -exp;
        }

        double result = 1.0;
        double base = x;

        while (exp > 0) {
            if ((exp & 1L) == 1L) {
                result *= base;
            }
            base *= base;
            exp >>= 1;
        }

        return result;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Pow(x, n)");
        System.out.println("=".repeat(60));

        System.out.println("2.0^10 -> " + myPow(2.0, 10));
        System.out.println("2.1^3 -> " + myPow(2.1, 3));
        System.out.println("2^-2 -> " + myPow(2.0, -2));
        System.out.println("5^0 -> " + myPow(5.0, 0));
        System.out.println("0^5 -> " + myPow(0.0, 5));
    }
}
