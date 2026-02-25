/**
 * Basic DSA Problems - Non-overlapping Intervals (LeetCode 435)
 * Min intervals to remove so the rest are non-overlapping
 */
public class basic_dsa_four_hundred_thirty_five {

    // Problem: intervals. Remove min to make rest non-overlapping. Touch OK.

    /**
     * Sort by end. Keep if start >= lastEnd; else remove.
     * Time O(n log n), Space O(1)
     */
    public static int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length == 0) return 0;
        java.util.Arrays.sort(intervals, java.util.Comparator.comparingInt(a -> a[1]));
        int lastEnd = intervals[0][1], remove = 0;
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= lastEnd) lastEnd = intervals[i][1];
            else remove++;
        }
        return remove;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Non-overlapping Intervals");
        System.out.println("=".repeat(60));

        System.out.println("[[1,2],[2,3],[3,4],[1,3]] -> " + eraseOverlapIntervals(new int[][]{{1,2},{2,3},{3,4},{1,3}}));
        System.out.println("[[1,2],[1,2],[1,2]] -> " + eraseOverlapIntervals(new int[][]{{1,2},{1,2},{1,2}}));
        System.out.println("[[1,2],[2,3]] -> " + eraseOverlapIntervals(new int[][]{{1,2},{2,3}}));
    }
}
