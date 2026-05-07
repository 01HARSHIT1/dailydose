/**
 * Basic DSA Problems - One Fundamental Two Pointer Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred {

    // Problem 1: Container With Most Water
    // Integer array height has n vertical lines at x = 0..n-1 (width between lines = 1).
    // Find two lines that form a container with the x-axis so the contained water is maximal.

    /**
     * Greedy two pointers: always drop the shorter side
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer maxArea(int[] height) {
        if (height == null) {
            return null;
        }

        int left = 0;
        int right = height.length - 1;
        int max = 0;

        while (left < right) {
            int h = Math.min(height[left], height[right]);
            max = Math.max(max, h * (right - left));
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Container With Most Water");
        System.out.println("=".repeat(60));

        int[] a = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        System.out.println("classic -> " + maxArea(a));

        int[] b = {1, 1};
        System.out.println("[1,1] -> " + maxArea(b));

        int[] c = {4, 3, 2, 1, 4};
        System.out.println("ends high -> " + maxArea(c));

        System.out.println("null -> " + maxArea(null));
    }
}
