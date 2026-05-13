/**
 * Basic DSA Problems - One Fundamental Binary Search Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_eighty_nine {

    // Problem 1: Minimum Time to Complete Trips
    // time[i] = minutes between trips for machine i; all can run in parallel.

    private static boolean canFinish(int[] time, int totalTrips, long limit) {
        long done = 0;
        for (int t : time) {
            done += limit / t;
            if (done >= totalTrips) {
                return true;
            }
        }
        return false;
    }

    /**
     * Binary search total time in [min(time), min(time) * totalTrips].
     * Time Complexity: O(n log answer)
     * Space Complexity: O(1)
     */
    public static Long minimumTime(int[] time, int totalTrips) {
        if (time == null || time.length == 0 || totalTrips < 1) {
            return null;
        }

        int minT = Integer.MAX_VALUE;
        for (int t : time) {
            if (t < 1) {
                return null;
            }
            minT = Math.min(minT, t);
        }

        long lo = minT;
        long hi = (long) minT * totalTrips;

        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            if (canFinish(time, totalTrips, mid)) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Minimum Time to Complete Trips");
        System.out.println("=".repeat(60));

        int[] a = {1, 2, 3};
        System.out.println("[1,2,3], total=5 -> " + minimumTime(a, 5));

        int[] b = {2};
        System.out.println("[2], total=1 -> " + minimumTime(b, 1));

        int[] c = {7, 10, 7, 8, 9, 8};
        System.out.println("[7,10,7,8,9,8], total=8 -> " + minimumTime(c, 8));

        System.out.println("null -> " + minimumTime(null, 3));
        System.out.println("total 0 -> " + minimumTime(a, 0));
    }
}
