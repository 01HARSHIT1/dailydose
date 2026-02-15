/**
 * Basic DSA Problems - Missing Number
 * Find the missing number in range [0, n]
 */
public class basic_dsa_three_hundred_nine {

    // Problem: Array nums of n distinct numbers in [0, n]. Return the only number missing.

    /**
     * Sum formula: 0+1+...+n = n*(n+1)/2. Subtract sum(nums) to get missing.
     * Time O(n), Space O(1)
     */
    public static int missingNumber(int[] nums) {
        int n = nums.length;
        int sum = n * (n + 1) / 2;
        for (int x : nums) sum -= x;
        return sum;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Missing Number");
        System.out.println("=".repeat(60));

        System.out.println("[3,0,1] -> " + missingNumber(new int[]{3, 0, 1}));
        System.out.println("[0,1] -> " + missingNumber(new int[]{0, 1}));
        System.out.println("[9,6,4,2,3,5,7,0,1] -> " + missingNumber(new int[]{9, 6, 4, 2, 3, 5, 7, 0, 1}));
    }
}
