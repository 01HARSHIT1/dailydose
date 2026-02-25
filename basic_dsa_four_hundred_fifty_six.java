/**
 * Basic DSA Problems - 132 Pattern (LeetCode 456)
 * Find i<j<k with nums[i] < nums[k] < nums[j]
 */
public class basic_dsa_four_hundred_fifty_six {

    // Problem: 132 = ai < ak < aj where i < j < k.

    /**
     * Right-to-left. Stack = decreasing (aj candidates). ak = best middle.
     * When nums[i] < ak, we have 132. Time O(n), Space O(n)
     */
    public static boolean find132pattern(int[] nums) {
        java.util.Deque<Integer> stk = new java.util.ArrayDeque<>();
        int ak = Integer.MIN_VALUE;
        for (int i = nums.length - 1; i >= 0; i--) {
            if (nums[i] < ak) return true;
            while (!stk.isEmpty() && stk.peek() < nums[i]) ak = stk.pop();
            stk.push(nums[i]);
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: 132 Pattern");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,3,4] -> " + find132pattern(new int[]{1,2,3,4}));
        System.out.println("[3,1,4,2] -> " + find132pattern(new int[]{3,1,4,2}));
        System.out.println("[-1,3,2,0] -> " + find132pattern(new int[]{-1,3,2,0}));
    }
}
