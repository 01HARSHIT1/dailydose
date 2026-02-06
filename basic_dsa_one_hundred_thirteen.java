/**
 * Basic DSA Problems - Majority Element
 * Find element that appears more than n/2 times (Boyer-Moore Voting)
 */
import java.util.Arrays;

public class basic_dsa_one_hundred_thirteen {

    // Problem: Given array nums of size n, return the majority element (appears more than n/2 times).
    // Assume majority element always exists.

    /**
     * Boyer-Moore majority vote: one candidate and count; cancel pairs, remaining is majority.
     * Time O(n), Space O(1)
     */
    public static int majorityElement(int[] nums) {
        if (nums == null || nums.length == 0) return -1;
        int candidate = nums[0], count = 1;
        for (int i = 1; i < nums.length; i++) {
            if (count == 0) candidate = nums[i];
            count += (nums[i] == candidate) ? 1 : -1;
        }
        return candidate;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Majority Element");
        System.out.println("=".repeat(60));

        System.out.println("[3,2,3] -> " + majorityElement(new int[] { 3, 2, 3 }));
        System.out.println("[2,2,1,1,1,2,2] -> " + majorityElement(new int[] { 2, 2, 1, 1, 1, 2, 2 }));
    }
}
