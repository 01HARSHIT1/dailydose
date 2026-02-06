/**
 * Basic DSA Problems - First Bad Version
 * Find the first bad version using binary search (minimize API calls)
 */
public class basic_dsa_one_hundred_three {

    // Problem: You have n versions [1, 2, ..., n]. isBadVersion(version) returns true if version is bad.
    // All versions after a bad one are bad. Find the first bad version with minimum API calls.

    // Simulated bad version threshold for testing
    private static int badFrom = 4;

    public static void setBadFrom(int version) {
        badFrom = version;
    }

    static boolean isBadVersion(int version) {
        return version >= badFrom;
    }

    /**
     * Binary search: if mid is bad, first bad is mid or left; else search right.
     * Time O(log n), Space O(1)
     */
    public static int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: First Bad Version");
        System.out.println("=".repeat(60));

        setBadFrom(4);
        System.out.println("n = 5, first bad = 4 -> " + firstBadVersion(5));

        setBadFrom(1);
        System.out.println("n = 1, first bad = 1 -> " + firstBadVersion(1));

        setBadFrom(2);
        System.out.println("n = 2, first bad = 2 -> " + firstBadVersion(2));
    }
}
