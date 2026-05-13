/**
 * Basic DSA Problems - One Fundamental Binary Search Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_eighty_four {

    // Problem 1: Capacity To Ship Packages Within D Days
    // weights[i] on day order; each day load a contiguous segment; cap = max weight per day.

    private static boolean canShipInDays(int[] weights, int capacity, int days) {
        int need = 1;
        int load = 0;
        for (int w : weights) {
            if (w > capacity) {
                return false;
            }
            if (load + w > capacity) {
                need++;
                load = w;
            } else {
                load += w;
            }
        }
        return need <= days;
    }

    /**
     * Binary search on ship capacity between max(weights) and sum(weights).
     * Time Complexity: O(n log S) where S is sum of weights
     * Space Complexity: O(1)
     */
    public static Integer shipWithinDays(int[] weights, int days) {
        if (weights == null || weights.length == 0 || days < 1 || days > weights.length) {
            return null;
        }

        int lo = 0;
        int hi = 0;
        for (int w : weights) {
            lo = Math.max(lo, w);
            hi += w;
        }

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (canShipInDays(weights, mid, days)) {
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
        System.out.println("Problem 1: Capacity To Ship Packages Within D Days");
        System.out.println("=".repeat(60));

        int[] a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        System.out.println("[1..10], days=5 -> " + shipWithinDays(a, 5));

        int[] b = {3, 2, 2, 4, 1, 4};
        System.out.println("[3,2,2,4,1,4], days=3 -> " + shipWithinDays(b, 3));

        int[] c = {1, 2, 3, 1, 1};
        System.out.println("[1,2,3,1,1], days=4 -> " + shipWithinDays(c, 4));

        int[] d = {5};
        System.out.println("[5], days=1 -> " + shipWithinDays(d, 1));

        System.out.println("null -> " + shipWithinDays(null, 5));
        System.out.println("days out of range [1], days=2 -> " + shipWithinDays(new int[] {1}, 2));
    }
}
