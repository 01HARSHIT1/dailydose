/**
 * Basic DSA Problems - Container With Most Water
 * Max area of water between two vertical lines (height[i], distance = j-i)
 */
public class basic_dsa_one_hundred_ninety_nine {

    // Problem: Array height. Two lines at i and j. Area = min(height[i], height[j]) * (j - i). Return max area.

    /**
     * Two pointers at both ends. Move the shorter line inward (only way to possibly get larger area).
     * Time O(n), Space O(1)
     */
    public static int maxArea(int[] height) {
        int max = 0, left = 0, right = height.length - 1;
        while (left < right) {
            int area = Math.min(height[left], height[right]) * (right - left);
            max = Math.max(max, area);
            if (height[left] < height[right]) left++;
            else right--;
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
