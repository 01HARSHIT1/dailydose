/**
 * Basic DSA Problems - One Fundamental Binary Search Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_twenty_nine {

    // Problem 1: Sqrt(x)
    // Given a non-negative integer x, return the square root of x rounded down to the nearest integer.
    // You must not use any built-in exponent function.
    //
    // Example:
    // x = 8 -> 2
    // x = 16 -> 4

    /**
     * Binary search on answer space [0, x]
     * Time Complexity: O(log x)
     * Space Complexity: O(1)
     */
    public static Integer mySqrt(int x) {
        if (x < 0) {
            return null;
        }
        if (x < 2) {
            return x;
        }

        int left = 1;
        int right = x / 2;
        int ans = 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long square = (long) mid * mid;

            if (square == x) {
                return mid;
            } else if (square < x) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return ans;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Sqrt(x)");
        System.out.println("=".repeat(60));

        System.out.println("x = 0 -> " + mySqrt(0));
        System.out.println("x = 1 -> " + mySqrt(1));
        System.out.println("x = 4 -> " + mySqrt(4));
        System.out.println("x = 8 -> " + mySqrt(8));
        System.out.println("x = 16 -> " + mySqrt(16));
        System.out.println("x = 2147395599 -> " + mySqrt(2147395599));
    }
}
