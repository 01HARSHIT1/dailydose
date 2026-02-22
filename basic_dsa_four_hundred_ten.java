/**
 * Basic DSA Problems - Split Array Largest Sum (LeetCode 410)
 * Split nums into k subarrays; minimize the maximum subarray sum
 */
public class basic_dsa_four_hundred_ten {

    // Problem: Split into k subarrays. Minimize max subarray sum.

    /**
     * Binary search on answer. Check if we can split with max sum <= mid.
     * Time O(n log(sum)), Space O(1)
     */
    public static int splitArray(int[] nums, int k) {
        long lo = 0, hi = 0;
        for (int x : nums) { lo = Math.max(lo, x); hi += x; }
        while (lo < hi) {
            long mid = lo + (hi - lo) / 2;
            if (canSplit(nums, k, mid)) hi = mid;
            else lo = mid + 1;
        }
        return (int) lo;
    }

    private static boolean canSplit(int[] nums, int k, long maxSum) {
        int parts = 1;
        long sum = 0;
        for (int x : nums) {
            if (sum + x > maxSum) {
                parts++;
                sum = x;
                if (parts > k) return false;
            } else sum += x;
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Split Array Largest Sum");
        System.out.println("=".repeat(60));

        System.out.println("[7,2,5,10,8], k=2 -> " + splitArray(new int[]{7,2,5,10,8}, 2));
        System.out.println("[1,2,3,4,5], k=2 -> " + splitArray(new int[]{1,2,3,4,5}, 2));
    }
}
