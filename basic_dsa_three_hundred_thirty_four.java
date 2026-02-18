/**
 * Basic DSA Problems - Increasing Triplet Subsequence (LeetCode 334)
 * Check if there exists indices i < j < k with nums[i] < nums[j] < nums[k]
 */
public class basic_dsa_three_hundred_thirty_four {

    // Problem: Integer array nums. Return true if exists triplet i<j<k with nums[i]<nums[j]<nums[k].

    /**
     * Track two smallest values; if we see larger than both, triplet exists.
     * Time O(n), Space O(1)
     */
    public static boolean increasingTriplet(int[] nums) {
        int first = Integer.MAX_VALUE;
        int second = Integer.MAX_VALUE;
        for (int x : nums) {
            if (x <= first) first = x;
            else if (x <= second) second = x;
            else return true;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Increasing Triplet Subsequence");
        System.out.println("=".repeat(60));

        System.out.println("[1,2,3,4,5] -> " + increasingTriplet(new int[]{1,2,3,4,5}));
        System.out.println("[5,4,3,2,1] -> " + increasingTriplet(new int[]{5,4,3,2,1}));
        System.out.println("[2,1,5,0,4,6] -> " + increasingTriplet(new int[]{2,1,5,0,4,6}));
    }
}
