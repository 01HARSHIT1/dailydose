/**
 * Basic DSA Problems - One Fundamental Binary Search + Patience Sort Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_thirteen {

    // Problem 1: Longest Increasing Subsequence
    // Return the length of the longest strictly increasing subsequence of nums.

    /**
     * Patience sorting tails: smallest tail for each length; binary search placement
     * Time Complexity: O(n log n)
     * Space Complexity: O(n)
     */
    public static Integer lengthOfLIS(int[] nums) {
        if (nums == null) {
            return null;
        }
        if (nums.length == 0) {
            return 0;
        }

        int[] tails = new int[nums.length];
        int size = 0;

        for (int x : nums) {
            int lo = 0;
            int hi = size;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (tails[mid] < x) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            tails[lo] = x;
            if (lo == size) {
                size++;
            }
        }

        return size;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Longest Increasing Subsequence");
        System.out.println("=".repeat(60));

        int[] a = {10, 9, 2, 5, 3, 7, 101, 18};
        System.out.println("classic -> " + lengthOfLIS(a));

        int[] b = {0, 1, 0, 3, 2, 3};
        System.out.println("[0,1,0,3,2,3] -> " + lengthOfLIS(b));

        int[] c = {7, 7, 7, 7, 7};
        System.out.println("all equal -> " + lengthOfLIS(c));

        System.out.println("empty -> " + lengthOfLIS(new int[0]));
        System.out.println("null -> " + lengthOfLIS(null));
    }
}
