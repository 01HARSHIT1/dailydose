/**
 * Basic DSA Problems - Monotonic Array
 * Check if array is monotonic (non-decreasing or non-increasing)
 */
public class basic_dsa_two_hundred_twenty_nine {

    // Problem: Return true if nums is either monotone increasing or monotone decreasing.

    /**
     * One pass: determine direction from first differing pair; then verify rest.
     * Time O(n), Space O(1)
     */
    public static boolean isMonotonic(int[] nums) {
        if (nums.length <= 2) return true;
        int dir = 0; // 1 = inc, -1 = dec
        for (int i = 1; i < nums.length; i++) {
            int d = Integer.compare(nums[i], nums[i - 1]);
            if (d == 0) continue;
            if (dir == 0) dir = d;
            else if (d != dir) return false;
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Monotonic Array");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,2,3] -> " + isMonotonic(new int[]{1, 2, 2, 3}));
        System.out.println("[6,5,4,4] -> " + isMonotonic(new int[]{6, 5, 4, 4}));
        System.out.println("[1,3,2] -> " + isMonotonic(new int[]{1, 3, 2}));
    }
}
