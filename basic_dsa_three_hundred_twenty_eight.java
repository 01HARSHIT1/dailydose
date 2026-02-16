/**
 * Basic DSA Problems - Majority Element
 * Find element appearing more than n/2 times
 */
public class basic_dsa_three_hundred_twenty_eight {

    // Problem: Array nums. Return element that appears more than n/2 times. Assume it exists.

    /**
     * Boyer-Moore voting: count cancels; remaining candidate is majority.
     * Time O(n), Space O(1)
     */
    public static int majorityElement(int[] nums) {
        int cand = nums[0], count = 1;
        for (int i = 1; i < nums.length; i++) {
            if (count == 0) cand = nums[i];
            count += nums[i] == cand ? 1 : -1;
        }
        return cand;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Majority Element");
        System.out.println("=".repeat(60));

        System.out.println("[3,2,3] -> " + majorityElement(new int[]{3, 2, 3}));
        System.out.println("[2,2,1,1,1,2,2] -> " + majorityElement(new int[]{2, 2, 1, 1, 1, 2, 2}));
    }
}
