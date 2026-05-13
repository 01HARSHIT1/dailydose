import java.util.HashMap;
import java.util.Map;

/**
 * Basic DSA Problems - One Fundamental Prefix Sum Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_seventy_seven {

    // Problem 1: Subarray Sum Equals K
    // Count contiguous subarrays whose sum is exactly k (nums may include negatives).

    /**
     * Prefix sums: count of (sum - k) seen so far equals ways to end here with sum k
     * Time Complexity: O(n)
     * Space Complexity: O(n)
     */
    public static Integer subarraySum(int[] nums, int k) {
        if (nums == null) {
            return null;
        }

        Map<Integer, Integer> freq = new HashMap<>();
        freq.put(0, 1);
        int sum = 0;
        int count = 0;

        for (int x : nums) {
            sum += x;
            count += freq.getOrDefault(sum - k, 0);
            freq.merge(sum, 1, Integer::sum);
        }

        return count;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Subarray Sum Equals K");
        System.out.println("=".repeat(60));

        int[] a = {1, 1, 1};
        System.out.println("[1,1,1] k=2 -> " + subarraySum(a, 2));

        int[] b = {1, 2, 3};
        System.out.println("[1,2,3] k=3 -> " + subarraySum(b, 3));

        int[] c = {1, -1, 0};
        System.out.println("[1,-1,0] k=0 -> " + subarraySum(c, 0));

        System.out.println("null -> " + subarraySum(null, 1));
    }
}
