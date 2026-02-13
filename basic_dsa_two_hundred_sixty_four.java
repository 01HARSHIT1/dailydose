/**
 * Basic DSA Problems - First Bad Version
 * Find first bad version using binary search
 */
public class basic_dsa_two_hundred_sixty_four {

    // Problem: Versions 1..n. isBadVersion(i) returns true if i is bad. Bad versions follow good.
    // Return first bad version. Minimize API calls.

    static boolean[] bad; // test harness: bad[i-1] = is version i bad

    public static int firstBadVersion(int n) {
        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (isBadVersion(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }

    static boolean isBadVersion(int v) {
        return bad[v - 1];
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: First Bad Version");
        System.out.println("=".repeat(60));

        bad = new boolean[]{false, false, false, true, true};
        System.out.println("n=5, first bad=4 -> " + firstBadVersion(5));

        bad = new boolean[]{true};
        System.out.println("n=1, first bad=1 -> " + firstBadVersion(1));
    }
}
