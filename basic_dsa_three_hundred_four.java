/**
 * Basic DSA Problems - First Bad Version
 * Find first bad version using binary search (API simulation)
 */
public class basic_dsa_three_hundred_four {

    // Problem: n versions [1..n], one is bad (all after are bad). Find first bad.
    // Simulate isBadVersion(version) API.

    private static int badStart = 4; // for demo

    private static boolean isBadVersion(int v) {
        return v >= badStart;
    }

    /**
     * Binary search for first true. Classic lower-bound.
     * Time O(log n), Space O(1)
     */
    public static int firstBadVersion(int n) {
        int lo = 1, hi = n, ans = n;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: First Bad Version");
        System.out.println("=".repeat(60));

        badStart = 4;
        System.out.println("n=5, bad=4 -> " + firstBadVersion(5));

        badStart = 1;
        System.out.println("n=1, bad=1 -> " + firstBadVersion(1));
    }
}
