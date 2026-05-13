import java.util.Arrays;

/**
 * Basic DSA Problems - One Fundamental Monotonic Stack Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_seventy_six {

    // Problem 1: Next Greater Element II
    // nums is circular: for each i, next greater value when scanning forward with wrap; else -1.

    /**
     * Two passes over indices 0..2n-1; stack of indices with decreasing values
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static int[] nextGreaterElements(int[] nums) {
        if (nums == null) {
            return null;
        }

        int n = nums.length;
        int[] res = new int[n];
        Arrays.fill(res, -1);
        int[] stack = new int[n];
        int top = -1;

        for (int i = 0; i < 2 * n; i++) {
            int idx = i % n;
            while (top >= 0 && nums[stack[top]] < nums[idx]) {
                res[stack[top--]] = nums[idx];
            }
            if (i < n) {
                stack[++top] = idx;
            }
        }

        return res;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Next Greater Element II");
        System.out.println("=".repeat(60));

        int[] a = {1, 2, 1};
        System.out.println("[1,2,1] -> " + Arrays.toString(nextGreaterElements(a)));

        int[] b = {1, 2, 3, 4, 3};
        System.out.println("[1,2,3,4,3] -> " + Arrays.toString(nextGreaterElements(b)));

        int[] z = nextGreaterElements(null);
        System.out.println("null -> " + (z == null ? "null" : Arrays.toString(z)));
    }
}
