/**
 * Basic DSA Problems - Non-overlapping Intervals
 * Minimum number of intervals to remove so remaining are non-overlapping
 */
import java.util.Arrays;
import java.util.Comparator;

public class basic_dsa_two_hundred_fourteen {

    // Problem: Remove min number of intervals so no two overlap. Return min removals.

    /**
     * Sort by end. Greedy: keep interval if its start >= last end; else remove (count removal).
     * Time O(n log n), Space O(1)
     */
    public static int eraseOverlapIntervals(int[][] intervals) {
        if (intervals == null || intervals.length == 0) return 0;
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[1]));
        int end = intervals[0][1], remove = 0;
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] < end) remove++;
            else end = intervals[i][1];
        }
        return remove;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Non-overlapping Intervals");
        System.out.println("=".repeat(60));

        System.out.println("[[1,2],[2,3],[3,4],[1,3]] -> " + eraseOverlapIntervals(new int[][]{{1, 2}, {2, 3}, {3, 4}, {1, 3}}));
        System.out.println("[[1,2],[1,2],[1,2]] -> " + eraseOverlapIntervals(new int[][]{{1, 2}, {1, 2}, {1, 2}}));
    }
}
