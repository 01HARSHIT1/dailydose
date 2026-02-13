/**
 * Basic DSA Problems - Arranging Coins
 * Find number of complete rows when stacking coins in staircase shape
 */
public class basic_dsa_two_hundred_forty_five {

    // Problem: You have n coins. Row k has k coins. Return number of complete rows.
    // Row 1 has 1, row 2 has 2, etc. Example: 5 coins -> 2 full rows (1+2=3, need 3 more for row 3)

    /**
     * Binary search: rows 1..k sum to k*(k+1)/2. Find max k such that k*(k+1)/2 <= n.
     * Time O(log n), Space O(1)
     */
    public static int arrangeCoins(int n) {
        long lo = 0, hi = n;
        while (lo <= hi) {
            long mid = lo + (hi - lo) / 2;
            long sum = mid * (mid + 1) / 2;
            if (sum <= n) lo = mid + 1;
            else hi = mid - 1;
        }
        return (int) (lo - 1);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Arranging Coins");
        System.out.println("=".repeat(60));

        System.out.println("5 -> " + arrangeCoins(5));
        System.out.println("8 -> " + arrangeCoins(8));
        System.out.println("1 -> " + arrangeCoins(1));
    }
}
