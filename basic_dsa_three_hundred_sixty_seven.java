/**
 * Basic DSA Problems - Valid Perfect Square (LeetCode 367)
 * Check if num is perfect square without built-in sqrt
 */
public class basic_dsa_three_hundred_sixty_seven {

    // Problem: num > 0. Return true if num = k*k for some integer k.

    /**
     * Binary search for sqrt. lo=1, hi=num.
     * Time O(log num), Space O(1)
     */
    public static boolean isPerfectSquare(int num) {
        if (num < 2) return true;
        long lo = 1, hi = num;
        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2;
            long sq = mid * mid;
            if (sq == num) return true;
            if (sq < num) lo = mid + 1;
            else hi = mid - 1;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Valid Perfect Square");
        System.out.println("=".repeat(60));

        System.out.println("16 -> " + isPerfectSquare(16));
        System.out.println("14 -> " + isPerfectSquare(14));
    }
}
