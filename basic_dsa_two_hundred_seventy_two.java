/**
 * Basic DSA Problems - Majority Element
 * Find element that appears more than n/2 times
 */
public class basic_dsa_two_hundred_seventy_two {

    // Problem: Return the majority element (appears > n/2 times). Assume it always exists.

    /**
     * Boyer-Moore voting: candidate and count. Same element +1, different -1.
     * When count=0, new candidate. Majority survives.
     * Time O(n), Space O(1)
     */
    public static int majorityElement(int[] nums) {
        int cand = nums[0], count = 1;
        for (int i = 1; i < nums.length; i++) {
            if (count == 0) {
                cand = nums[i];
                count = 1;
            } else if (nums[i] == cand) count++;
            else count--;
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
