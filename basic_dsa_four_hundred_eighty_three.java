/**
 * Basic DSA Problems - One Fundamental Binary Search Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_eighty_three {

    // Problem 1: Sqrt(x) — Integer Square Root
    // Given a non-negative integer x, return the integer part of its square root (truncate the decimal part).
    // You must not use built-in sqrt / pow for the core logic (binary search below).
    //
    // Example:
    // x = 4 -> 2
    // x = 8 -> 2

    /**
     * Binary search on answer in [1, x]; use long to avoid overflow when squaring mid
     * Time Complexity: O(log x)
     * Space Complexity: O(1)
     */
    public static Integer mySqrt(int x) {
        if (x < 0) {
            return null;
        }
        if (x == 0) {
            return 0;
        }

        int left = 1;
        int right = x;
        int ans = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long sq = (long) mid * mid;
            if (sq == x) {
                return mid;
            }
            if (sq < x) {
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
        System.out.println("Problem 1: Integer Square Root");
        System.out.println("=".repeat(60));

        System.out.println("x = 4       -> " + mySqrt(4));
        System.out.println("x = 8       -> " + mySqrt(8));
        System.out.println("x = 2147395599 -> " + mySqrt(2147395599));
        System.out.println("x = 0       -> " + mySqrt(0));
        System.out.println("x = 1       -> " + mySqrt(1));
        System.out.println("x = -1      -> " + mySqrt(-1));
    }
}
