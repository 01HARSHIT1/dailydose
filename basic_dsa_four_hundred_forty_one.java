/**
 * Basic DSA Problems - Arranging Coins (LeetCode 441)
 * Form staircase: row i has i coins. Return number of complete rows.
 */
public class basic_dsa_four_hundred_forty_one {

    // Problem: n coins. Row k needs k coins. Max complete rows k where k(k+1)/2 <= n.

    /**
     * k(k+1)/2 <= n -> k = floor((-1 + sqrt(8n+1))/2).
     * Time O(1), Space O(1)
     */
    public static int arrangeCoins(int n) {
        return (int) ((-1 + Math.sqrt(1 + 8L * n)) / 2);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Arranging Coins");
        System.out.println("=".repeat(60));

        System.out.println("n=5 -> " + arrangeCoins(5));
        System.out.println("n=8 -> " + arrangeCoins(8));
        System.out.println("n=1 -> " + arrangeCoins(1));
    }
}
