/**
 * Basic DSA Problems - Meeting Rooms II (Min meeting rooms)
 * Minimum number of conference rooms required
 */
import java.util.Arrays;
import java.util.Comparator;
import java.util.PriorityQueue;

public class basic_dsa_two_hundred_sixteen {

    // Problem: intervals[i] = [start, end]. Return min number of rooms so all meetings can be held.

    /**
     * Sort by start. Min-heap of end times. For each interval: if start >= heap min, reuse that room (poll); else need new room. Add current end to heap.
     * Time O(n log n), Space O(n)
     */
    public static int minMeetingRooms(int[][] intervals) {
        if (intervals == null || intervals.length == 0) return 0;
        Arrays.sort(intervals, Comparator.comparingInt(a -> a[0]));
        PriorityQueue<Integer> ends = new PriorityQueue<>();
        ends.offer(intervals[0][1]);
        for (int i = 1; i < intervals.length; i++) {
            if (intervals[i][0] >= ends.peek()) ends.poll();
            ends.offer(intervals[i][1]);
        }
        return ends.size();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Meeting Rooms II");
        System.out.println("=".repeat(60));

        System.out.println("[[0,30],[5,10],[15,20]] -> " + minMeetingRooms(new int[][]{{0, 30}, {5, 10}, {15, 20}}));
        System.out.println("[[7,10],[2,4]] -> " + minMeetingRooms(new int[][]{{7, 10}, {2, 4}}));
    }
}
