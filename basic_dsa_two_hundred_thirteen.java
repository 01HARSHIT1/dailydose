/**
 * Basic DSA Problems - Insert Interval
 * Insert new interval into non-overlapping sorted intervals, merge if needed
 */
import java.util.ArrayList;
import java.util.List;

public class basic_dsa_two_hundred_thirteen {

    // Problem: Sorted non-overlapping intervals. Insert newInterval, merge overlaps. Return merged list.

    /**
     * Add all intervals that end before newInterval.start; merge overlapping with newInterval; add rest.
     * Time O(n), Space O(n)
     */
    public static int[][] insert(int[][] intervals, int[] newInterval) {
        List<int[]> out = new ArrayList<>();
        int i = 0, n = intervals.length;
        while (i < n && intervals[i][1] < newInterval[0])
            out.add(intervals[i++]);
        while (i < n && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = Math.min(newInterval[0], intervals[i][0]);
            newInterval[1] = Math.max(newInterval[1], intervals[i][1]);
            i++;
        }
        out.add(newInterval);
        while (i < n) out.add(intervals[i++]);
        return out.toArray(new int[0][]);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Insert Interval");
        System.out.println("=".repeat(60));

        int[][] intervals = {{1, 3}, {6, 9}};
        int[] newInterval = {2, 5};
        int[][] result = insert(intervals, newInterval);
        System.out.println("Insert [2,5] -> " + java.util.Arrays.deepToString(result));
    }
}
