/**
 * Basic DSA Problems - Container With Most Water
 * Find two lines that form container with most water
 */
public class basic_dsa_three_hundred_twenty_three {

    // Problem: Array height of vertical lines. Two lines form container. Return max water area.

    /**
     * Two pointers at ends. Move the shorter line inward (only way to possibly get more).
     * Time O(n), Space O(1)
     */
    public static int maxArea(int[] height) {
        int i = 0, j = height.length - 1, max = 0;
        while (i < j) {
            int area = Math.min(height[i], height[j]) * (j - i);
            max = Math.max(max, area);
            if (height[i] < height[j]) i++;
            else j--;
        }
        return max;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Container With Most Water");
        System.out.println("=".repeat(60));

        System.out.println("[1,8,6,2,5,4,8,3,7] -> " + maxArea(new int[]{1, 8, 6, 2, 5, 4, 8, 3, 7}));
        System.out.println("[1,1] -> " + maxArea(new int[]{1, 1}));
    }
}
