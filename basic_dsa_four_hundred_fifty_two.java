/**
 * Basic DSA Problems - Minimum Number of Arrows to Burst Balloons (LeetCode 452)
 * Arrows shot at x burst balloons where xstart <= x <= xend. Min arrows.
 */
public class basic_dsa_four_hundred_fifty_two {

    // Problem: intervals. One arrow at x bursts all overlapping. Greedy by end.

    /**
     * Sort by end. Shoot at first end; skip overlapping; repeat.
     * Time O(n log n), Space O(1)
     */
    public static int findMinArrowShots(int[][] points) {
        if (points.length == 0) return 0;
        java.util.Arrays.sort(points, java.util.Comparator.comparingInt(a -> a[1]));
        int arrows = 1, lastEnd = points[0][1];
        for (int i = 1; i < points.length; i++) {
            if (points[i][0] > lastEnd) {
                arrows++;
                lastEnd = points[i][1];
            }
        }
        return arrows;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Minimum Number of Arrows to Burst Balloons");
        System.out.println("=".repeat(60));

        System.out.println("[[10,16],[2,8],[1,6],[7,12]] -> " + findMinArrowShots(new int[][]{{10,16},{2,8},{1,6},{7,12}}));
        System.out.println("[[1,2],[3,4],[5,6],[7,8]] -> " + findMinArrowShots(new int[][]{{1,2},{3,4},{5,6},{7,8}}));
        System.out.println("[[1,2],[2,3],[3,4],[4,5]] -> " + findMinArrowShots(new int[][]{{1,2},{2,3},{3,4},{4,5}}));
    }
}
