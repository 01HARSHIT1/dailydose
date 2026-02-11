/**
 * Basic DSA Problems - Meeting Rooms (Can attend all?)
 * Check if one person can attend all meetings (no two overlap)
 */
import java.util.Arrays;
import java.util.Comparator;

public class basic_dsa_two_hundred_fifteen {

    // Problem: intervals[i] = [start, end]. Can attend all? (no overlap)

    /**
     * Sort by start. If intervals[i].start < intervals[i-1].end then overlap => false.
     * Time O(n log n), Space O(1)
     */
    public static boolean canAttendMeetings(int[][] intervals) {
        if (intervals == null || intervals.length <= 1) return true;
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        for (int i = 1; i < intervals.length; i++)
            if (intervals[i][0] < intervals[i - 1][1]) return false;
        return true;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Meeting Rooms");
        System.out.println("=".repeat(60));

        System.out.println("[[0,30],[5,10],[15,20]] -> " + canAttendMeetings(new int[][]{{0, 30}, {5, 10}, {15, 20}}));
        System.out.println("[[7,10],[2,4]] -> " + canAttendMeetings(new int[][]{{7, 10}, {2, 4}}));
    }
}
