/**
 * Basic DSA Problems - One Fundamental Binary Search Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_eighty_eight {

    // Problem 1: Random Pick with Weight (probability proportional to weight).
    // Given cumulative sums and r in [0, total), return index i with smallest prefix[i] > r.

    private static boolean validWeights(int[] w) {
        if (w == null || w.length == 0) {
            return false;
        }
        for (int x : w) {
            if (x <= 0) {
                return false;
            }
        }
        return true;
    }

    private static int[] prefixSum(int[] weights) {
        int[] p = new int[weights.length];
        p[0] = weights[0];
        for (int i = 1; i < weights.length; i++) {
            p[i] = p[i - 1] + weights[i];
        }
        return p;
    }

    /**
     * Smallest index i such that prefix[i] > r (prefix is inclusive cumulative sum).
     * Time Complexity: O(log n)
     * Space Complexity: O(1) extra besides prefix builder
     */
    public static Integer pickIndex(int[] prefix, int r) {
        if (prefix == null || prefix.length == 0) {
            return null;
        }
        int total = prefix[prefix.length - 1];
        if (r < 0 || r >= total) {
            return null;
        }

        int lo = 0;
        int hi = prefix.length - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (prefix[mid] <= r) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }

        return lo;
    }

    /**
     * Build prefix sums from weights, then pick using r in [0, sum(weights)).
     */
    public static Integer pickIndexFromWeights(int[] weights, int r) {
        if (!validWeights(weights)) {
            return null;
        }
        return pickIndex(prefixSum(weights), r);
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Random Pick with Weight (binary search on prefix)");
        System.out.println("=".repeat(60));

        int[] w = {1, 3};
        System.out.println("weights [1,3], r=0 -> " + pickIndexFromWeights(w, 0));
        System.out.println("weights [1,3], r=1 -> " + pickIndexFromWeights(w, 1));
        System.out.println("weights [1,3], r=2 -> " + pickIndexFromWeights(w, 2));
        System.out.println("weights [1,3], r=3 -> " + pickIndexFromWeights(w, 3));

        int[] w2 = {1, 2, 3, 4, 5};
        System.out.println("weights 1..5, r=14 -> " + pickIndexFromWeights(w2, 14));

        System.out.println("r out of range [1,3], r=4 -> " + pickIndexFromWeights(w, 4));
        System.out.println("null weights -> " + pickIndexFromWeights(null, 0));
        System.out.println("zero weight -> " + pickIndexFromWeights(new int[] {1, 0, 2}, 0));
    }
}
