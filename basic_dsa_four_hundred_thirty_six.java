/**
 * Basic DSA Problems - Find Right Interval (LeetCode 436)
 * For each interval i, find j with smallest start >= end_i. Return index or -1.
 */
public class basic_dsa_four_hundred_thirty_six {

    // Problem: intervals. Right interval = j where start_j >= end_i, min start.

    /**
     * Sort (start, index) by start. Binary search for first start >= end_i.
     * Time O(n log n), Space O(n)
     */
    public static int[] findRightInterval(int[][] intervals) {
        int n = intervals.length;
        int[][] starts = new int[n][2]; // [start, origIndex]
        for (int i = 0; i < n; i++) {
            starts[i][0] = intervals[i][0];
            starts[i][1] = i;
        }
        java.util.Arrays.sort(starts, java.util.Comparator.comparingInt(a -> a[0]));
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            int end = intervals[i][1];
            int lo = 0, hi = n - 1;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (starts[mid][0] < end) lo = mid + 1;
                else hi = mid;
            }
            ans[i] = (starts[lo][0] >= end) ? starts[lo][1] : -1;
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Find Right Interval");
        System.out.println("=".repeat(60));

        System.out.println("[[1,2]] -> " + java.util.Arrays.toString(findRightInterval(new int[][]{{1,2}})));
        System.out.println("[[3,4],[2,3],[1,2]] -> " + java.util.Arrays.toString(findRightInterval(new int[][]{{3,4},{2,3},{1,2}})));
        System.out.println("[[1,4],[2,3],[3,4]] -> " + java.util.Arrays.toString(findRightInterval(new int[][]{{1,4},{2,3},{3,4}})));
    }
}
