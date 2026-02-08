/**
 * Basic DSA Problems - Arranging Coins
 * How many complete rows of coins can you form?
 */
public class basic_dsa_one_hundred_forty_eight {

    // Problem: You have n coins. Build a staircase: row 1 has 1 coin, row 2 has 2, row 3 has 3, etc.
    // Return the number of complete rows you can form. Example: n=5 -> 2 (row1:1, row2:2, row3 needs 3, only 2 left)

    /**
     * Binary search: find largest k such that k(k+1)/2 <= n
     * Time O(log n), Space O(1)
     */
    public static int arrangeCoins(int n) {
        if (n <= 0) return 0;
        long lo = 1, hi = n;
        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2;
            long sum = mid * (mid + 1) / 2;
            if (sum == n) return (int) mid;
            if (sum < n) lo = mid + 1;
            else hi = mid - 1;
        }
        return (int) hi;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Arranging Coins");
        System.out.println("=".repeat(60));

        System.out.println("n=5 -> " + arrangeCoins(5));
        System.out.println("n=8 -> " + arrangeCoins(8));
        System.out.println("n=1 -> " + arrangeCoins(1));
        System.out.println("n=0 -> " + arrangeCoins(0));
    }
}
