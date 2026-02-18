/**
 * Basic DSA Problems - Self Crossing (LeetCode 335)
 * Check if path drawn by distance array crosses itself
 */
public class basic_dsa_three_hundred_thirty_five {

    // Problem: Array of distances [up, right, down, left, ...]. Return true if path crosses itself.

    /**
     * Crossing occurs when current edge crosses a non-adjacent edge.
     * Time O(n), Space O(1)
     */
    public static boolean isSelfCrossing(int[] distance) {
        int n = distance.length;
        for (int i = 3; i < n; i++) {
            if (distance[i] >= distance[i - 2] && distance[i - 1] <= distance[i - 3]) return true;
            if (i >= 4 && distance[i - 1] == distance[i - 3] && distance[i] + distance[i - 4] >= distance[i - 2]) return true;
            if (i >= 5 && distance[i - 2] >= distance[i - 4] && distance[i - 1] <= distance[i - 3]
                    && distance[i] >= distance[i - 2] - distance[i - 4]
                    && distance[i - 1] + distance[i - 5] >= distance[i - 3]) return true;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Self Crossing");
        System.out.println("=".repeat(60));

        System.out.println("[2,1,1,2] -> " + isSelfCrossing(new int[]{2,1,1,2}));
        System.out.println("[1,2,3,4] -> " + isSelfCrossing(new int[]{1,2,3,4}));
        System.out.println("[1,1,1,1] -> " + isSelfCrossing(new int[]{1,1,1,1}));
    }
}
