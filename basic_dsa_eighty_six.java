/**
 * Basic DSA Problems - First Bad Version
 * Simple and essential DSA problems for beginners
 */

public class basic_dsa_eighty_six {

    // Problem: Find the first bad version. You have n versions [1..n]; isBadVersion(i) returns true if i is bad.
    // All versions after the first bad one are bad. Find the first bad version in O(log n) API calls.

    private static int firstBad = 4; // simulated: versions >= 4 are bad

    static boolean isBadVersion(int version) {
        return version >= firstBad;
    }

    /**
     * Binary search for the first index where isBadVersion is true.
     * Time O(log n), Space O(1)
     */
    public static int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: First Bad Version");
        System.out.println("=".repeat(60));

        firstBad = 4;
        System.out.println("n=5, firstBad=4 -> " + firstBadVersion(5));

        firstBad = 1;
        System.out.println("n=1, firstBad=1 -> " + firstBadVersion(1));

        firstBad = 2;
        System.out.println("n=3, firstBad=2 -> " + firstBadVersion(3));
    }
}
