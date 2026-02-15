/**
 * Basic DSA Problems - First Bad Version
 * Binary search for first bad version
 */
public class basic_dsa_three_hundred_twelve {

    // Problem: n versions [1..n], one is bad (all after it are bad). Find first bad.

    private static int badFrom = 4; // simulated first bad version

    static boolean isBadVersion(int v) {
        return v >= badFrom;
    }

    /**
     * Binary search: if mid is bad, search left; else search right.
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

        badFrom = 4;
        System.out.println("n=5, bad=4 -> " + firstBadVersion(5));

        badFrom = 1;
        System.out.println("n=1, bad=1 -> " + firstBadVersion(1));

        badFrom = 2;
        System.out.println("n=3, bad=2 -> " + firstBadVersion(3));
    }
}
