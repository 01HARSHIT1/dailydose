/**
 * Basic DSA Problems - K-th Smallest in Lexicographical Order (LeetCode 440)
 * Find k-th smallest int in [1,n] when sorted lexicographically
 */
public class basic_dsa_four_hundred_forty {

    // Problem: n=13, k=2 -> lex order 1,10,11,12,13,2,3,... -> ans=10

    /**
     * Denary tree: ans*10 = child, ans+1 = sibling. getGap counts subtree size.
     * Time O(log^2 n), Space O(1)
     */
    public static int findKthNumber(int n, int k) {
        long ans = 1;
        for (int i = 1; i < k; ) {
            long gap = getGap(ans, ans + 1, n);
            if (i + gap <= k) {
                i += gap;
                ans++;
            } else {
                i++;
                ans *= 10;
            }
        }
        return (int) ans;
    }

    private static long getGap(long a, long b, long n) {
        long gap = 0;
        while (a <= n) {
            gap += Math.min(n + 1, b) - a;
            a *= 10;
            b *= 10;
        }
        return gap;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: K-th Smallest in Lexicographical Order");
        System.out.println("=".repeat(60));

        System.out.println("n=13, k=2 -> " + findKthNumber(13, 2));
        System.out.println("n=1, k=1 -> " + findKthNumber(1, 1));
        System.out.println("n=100, k=10 -> " + findKthNumber(100, 10));
    }
}
