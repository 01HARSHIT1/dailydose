/**
 * Basic DSA Problems - Majority Element
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_ninety_five {

    // Problem: Find the majority element (appears more than n/2 times). Assume it always exists.
    // Example: [3,2,3] -> 3, [2,2,1,1,1,2,2] -> 2

    /**
     * Boyer-Moore voting: one candidate, count; majority cancels all others.
     * Time O(n), Space O(1)
     */
    public static int majorityElement(int[] nums) {
        if (nums == null || nums.length == 0) return -1;
        int cand = nums[0], count = 1;
        for (int i = 1; i < nums.length; i++) {
            if (count == 0) cand = nums[i];
            count += (nums[i] == cand) ? 1 : -1;
        }
        return cand;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Majority Element");
        System.out.println("=".repeat(60));

        System.out.println("[3,2,3] -> " + majorityElement(new int[] { 3, 2, 3 }));
        System.out.println("[2,2,1,1,1,2,2] -> " + majorityElement(new int[] { 2, 2, 1, 1, 1, 2, 2 }));
    }
}
