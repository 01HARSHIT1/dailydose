/**
 * Basic DSA Problems - Merge Intervals
 * Merge overlapping intervals
 */
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class basic_dsa_two_hundred_twelve {

    // Problem: intervals[i] = [start, end]. Merge all overlapping, return non-overlapping list.

    /**
     * Sort by start. Then merge: if current overlaps with last in list, extend last; else add current.
     * Time O(n log n), Space O(n)
     */
    public static int[][] merge(int[][] intervals) {
        if (intervals == null || intervals.length == 0) return new int[0][0];
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        List<int[]> out = new ArrayList<>();
        out.add(intervals[0]);
        for (int i = 1; i < intervals.length; i++) {
            int[] cur = intervals[i];
            int[] last = out.get(out.size() - 1);
            if (cur[0] <= last[1])
                last[1] = Math.max(last[1], cur[1]);
            else
                out.add(cur);
        }
        return out.toArray(new int[0][]);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Merge Intervals");
        System.out.println("=".repeat(60));

        int[][] intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
        int[][] merged = merge(intervals);
        System.out.println("Merged -> " + Arrays.deepToString(merged));
    }
}
