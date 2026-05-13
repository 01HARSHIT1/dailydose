/**
 * Basic DSA Problems - One Fundamental Binary Search Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_eighty_five {

    // Problem 1: Smallest Divisor Given a Threshold
    // Smallest positive d such that sum_i ceil(nums[i] / d) <= threshold.

    private static long sumOfCeils(int[] nums, int d) {
        long sum = 0;
        for (int x : nums) {
            sum += (x + d - 1L) / d;
        }
        return sum;
    }

    /**
     * Search divisor in [1, max(nums)]. Feasible(d) is monotone: larger d => smaller sum.
     * Time Complexity: O(n log M) where M = max value in nums
     * Space Complexity: O(1)
     */
    public static Integer smallestDivisor(int[] nums, int threshold) {
        if (nums == null || nums.length == 0 || threshold < nums.length) {
            return null;
        }

        int hi = 1;
        for (int x : nums) {
            hi = Math.max(hi, x);
        }

        int lo = 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (sumOfCeils(nums, mid) <= threshold) {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Smallest Divisor Given a Threshold");
        System.out.println("=".repeat(60));

        int[] a = {1, 2, 5, 9};
        System.out.println("[1,2,5,9], threshold=6 -> " + smallestDivisor(a, 6));

        int[] b = {2, 3, 4, 5};
        System.out.println("[2,3,4,5], threshold=10 -> " + smallestDivisor(b, 10));

        int[] c = {19};
        System.out.println("[19], threshold=5 -> " + smallestDivisor(c, 5));

        int[] d = {962551, 752479, 554859, 561589, 455934, 310812, 272853, 957124, 411693};
        System.out.println("9 large nums, threshold=9 -> " + smallestDivisor(d, 9));

        System.out.println("null -> " + smallestDivisor(null, 10));
        System.out.println("threshold too small [1,2], th=1 -> " + smallestDivisor(new int[] {1, 2}, 1));
    }
}
