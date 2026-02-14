/**
 * Basic DSA Problems - Missing Number
 * Find the single number missing from [0, n] range
 */
public class basic_dsa_two_hundred_ninety_seven {

    // Problem: Given array nums of n distinct numbers in [0, n], return the one that is missing.

    /**
     * Sum of 0..n minus sum of nums. Or use XOR: xor all 0..n and all nums.
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
