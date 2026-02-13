/**
 * Basic DSA Problems - Missing Number
 * Find the single number missing from range [0, n]
 */
public class basic_dsa_two_hundred_thirty_five {

    // Problem: Array nums containing n distinct numbers from [0, n]. Return the one missing.
    // Example: [0,1,3] -> 2; [0,1,2,3,4] -> 5

    /**
     * Sum 0..n = n*(n+1)/2. Subtract actual sum to get missing number.
     * Time O(n), Space O(1)
     */
    public static int missingNumber(int[] nums) {
        int n = nums.length;
        int expected = n * (n + 1) / 2;
        int actual = 0;
        for (int x : nums) actual += x;
        return expected - actual;
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
