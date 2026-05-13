import java.util.Arrays;

/**
 * Basic DSA Problems - One Fundamental Binary Search Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_eighty_three {

    // Problem 1: Magnetic Force Between Two Balls (maximize minimum distance)
    // place m balls into baskets at positions on a number line; baskets need max spacing.

    private static boolean canPlace(int[] pos, int m, int minDist) {
        int count = 1;
        int last = pos[0];
        for (int i = 1; i < pos.length; i++) {
            if (pos[i] - last >= minDist) {
                count++;
                last = pos[i];
            }
        }
        return count >= m;
    }

    /**
     * Binary search on answer (minimum distance between any two balls).
     * Time Complexity: O(n log D) where D is max position - min position
     * Space Complexity: O(1) extra (O(log n) sort stack if not already sorted)
     */
    public static Integer maxDistance(int[] position, int m) {
        if (position == null || position.length == 0 || m < 2 || m > position.length) {
            return null;
        }

        int[] pos = position.clone();
        Arrays.sort(pos);

        int lo = 1;
        int hi = pos[pos.length - 1] - pos[0];
        int ans = 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canPlace(pos, m, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Magnetic Force Between Two Balls");
        System.out.println("=".repeat(60));

        int[] a = {1, 2, 3, 4, 7};
        System.out.println("[1,2,3,4,7], m=3 -> " + maxDistance(a, 3));

        int[] b = {5, 4, 3, 2, 1};
        System.out.println("[5,4,3,2,1], m=3 -> " + maxDistance(b, 3));

        int[] c = {79, 74, 57, 22};
        System.out.println("[79,74,57,22], m=4 -> " + maxDistance(c, 4));

        int[] d = {1};
        System.out.println("[1], m=2 -> " + maxDistance(d, 2));

        System.out.println("null -> " + maxDistance(null, 3));
    }
}
