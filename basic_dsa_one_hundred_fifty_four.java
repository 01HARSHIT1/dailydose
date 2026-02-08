/**
 * Basic DSA Problems - Missing Number
 * Find the only number missing from range [0, n] in an array of n numbers
 */
public class basic_dsa_one_hundred_fifty_four {

    // Problem: Given array nums containing n distinct numbers in [0, n], return the only number missing.

    /**
     * Sum of 0..n is n*(n+1)/2; subtract sum of nums to get missing.
     * Time O(n), Space O(1)
     */
    public static int missingNumber(int[] nums) {
        int n = nums.length;
        int expected = n * (n + 1) / 2;
        int sum = 0;
        for (int x : nums) sum += x;
        return expected - sum;
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
