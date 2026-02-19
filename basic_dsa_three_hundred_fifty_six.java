/**
 * Basic DSA Problems - Line Reflection (LeetCode 356)
 * Check if points have a vertical line of reflection
 */
public class basic_dsa_three_hundred_fifty_six {

    // Problem: Points on 2D plane. Is there vertical line x=k that reflects all points?

    /**
     * Reflection line x = (minX + maxX) / 2. For each (x,y), (2*k-x, y) must exist.
     * Time O(n), Space O(n)
     */
    public static boolean isReflected(int[][] points) {
        int minX = Integer.MAX_VALUE, maxX = Integer.MIN_VALUE;
        java.util.Set<String> set = new java.util.HashSet<>();
        for (int[] p : points) {
            minX = Math.min(minX, p[0]);
            maxX = Math.max(maxX, p[0]);
            set.add(p[0] + "," + p[1]);
        }
        long sum = (long) minX + maxX;  // 2*k = minX + maxX
        for (int[] p : points) {
            long rx = sum - p[0];
            if (!set.contains(rx + "," + p[1])) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Line Reflection");
        System.out.println("=".repeat(60));

        System.out.println("[[1,1],[-1,1]] -> " + isReflected(new int[][]{{1,1},{-1,1}}));
        System.out.println("[[1,1],[-1,-1]] -> " + isReflected(new int[][]{{1,1},{-1,-1}}));
    }
}
