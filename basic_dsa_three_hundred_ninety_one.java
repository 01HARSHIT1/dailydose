/**
 * Basic DSA Problems - Perfect Rectangle (LeetCode 391)
 * Check if rectangles exactly cover a rectangular region (no gap, no overlap)
 */
public class basic_dsa_three_hundred_ninety_one {

    // Problem: rectangles [x1,y1,x2,y2]. Return true if exact cover.

    /**
     * Bounding corners appear once; interior corners appear 2 or 4 times.
     * Total area of rects must equal bounding area.
     * Time O(n), Space O(n)
     */
    public static boolean isRectangleCover(int[][] rectangles) {
        int minX = Integer.MAX_VALUE, minY = Integer.MAX_VALUE;
        int maxX = Integer.MIN_VALUE, maxY = Integer.MIN_VALUE;
        long area = 0;
        java.util.Set<String> corners = new java.util.HashSet<>();

        for (int[] r : rectangles) {
            minX = Math.min(minX, r[0]);
            minY = Math.min(minY, r[1]);
            maxX = Math.max(maxX, r[2]);
            maxY = Math.max(maxY, r[3]);
            area += (long) (r[2] - r[0]) * (r[3] - r[1]);

            String[] pts = {r[0] + "," + r[1], r[0] + "," + r[3], r[2] + "," + r[1], r[2] + "," + r[3]};
            for (String p : pts) {
                if (corners.contains(p)) corners.remove(p);
                else corners.add(p);
            }
        }
        if (area != (long) (maxX - minX) * (maxY - minY)) return false;
        return corners.size() == 4 && corners.contains(minX + "," + minY)
                && corners.contains(minX + "," + maxY)
                && corners.contains(maxX + "," + minY)
                && corners.contains(maxX + "," + maxY);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Perfect Rectangle");
        System.out.println("=".repeat(60));

        int[][] r1 = {{1,1,3,3},{3,1,4,2},{3,2,4,4},{1,3,2,4},{2,3,3,4}};
        System.out.println("5 rects -> " + isRectangleCover(r1));
        int[][] r2 = {{1,1,2,2},{1,1,2,2},{2,1,3,2}};
        System.out.println("overlap -> " + isRectangleCover(r2));
    }
}
