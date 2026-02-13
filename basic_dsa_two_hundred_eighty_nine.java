/**
 * Basic DSA Problems - Sliding Window Maximum
 * Max element in each sliding window of size k
 */
import java.util.ArrayDeque;
import java.util.Deque;

public class basic_dsa_two_hundred_eighty_nine {

    // Problem: For each window of size k, return max. nums = [1,3,-1,-3,5,3,6,7], k=3 -> [3,3,5,5,6,7]

    /**
     * Monotonic deque: store indices of elements in decreasing order.
     * Front is max. Remove indices outside window, smaller elements before adding.
     * Time O(n), Space O(k)
     */
    public static int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length == 0 || k == 0) return new int[0];
        int[] out = new int[nums.length - k + 1];
        Deque<Integer> dq = new ArrayDeque<>();
        for (int i = 0; i < nums.length; i++) {
            while (!dq.isEmpty() && dq.peekFirst() < i - k + 1) dq.pollFirst();
            while (!dq.isEmpty() && nums[dq.peekLast()] < nums[i]) dq.pollLast();
            dq.offerLast(i);
            if (i >= k - 1) out[i - k + 1] = nums[dq.peekFirst()];
        }
        return out;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Sliding Window Maximum");
        System.out.println("=".repeat(60));

        System.out.println("[1,3,-1,-3,5,3,6,7], k=3 -> " +
            java.util.Arrays.toString(maxSlidingWindow(new int[]{1, 3, -1, -3, 5, 3, 6, 7}, 3)));
    }
}
