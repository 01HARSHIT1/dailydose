/**
 * Basic DSA Problems - One Fundamental Monotonic Stack Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_ninety_nine {

    // Problem 1: Largest Rectangle in Histogram
    // heights[i] is the height of the bar at index i (width 1).
    // Return the area of the largest rectangle contained in the histogram.

    /**
     * Monotone stack of bar indices (heights increasing)
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static Integer largestRectangleArea(int[] heights) {
        if (heights == null) {
            return null;
        }

        int n = heights.length;
        int[] stack = new int[n + 1];
        int top = -1;
        int max = 0;

        for (int i = 0; i <= n; i++) {
            int cur = i < n ? heights[i] : 0;
            while (top >= 0 && cur < heights[stack[top]]) {
                int idx = stack[top--];
                int h = heights[idx];
                int w = top < 0 ? i : i - stack[top] - 1;
                max = Math.max(max, h * w);
            }
            if (i < n) {
                stack[++top] = i;
            }
        }

        return max;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Largest Rectangle in Histogram");
        System.out.println("=".repeat(60));

        int[] a = {2, 1, 5, 6, 2, 3};
        System.out.println("classic -> " + largestRectangleArea(a));

        int[] b = {2, 4};
        System.out.println("[2,4] -> " + largestRectangleArea(b));

        int[] c = {1};
        System.out.println("[1] -> " + largestRectangleArea(c));

        int[] d = {};
        System.out.println("empty -> " + largestRectangleArea(d));

        System.out.println("null -> " + largestRectangleArea(null));
    }
}
