/**
 * Basic DSA Problems - Missing Number
 * Find the only number in [0, n] missing from array of length n
 */
public class basic_dsa_one_hundred_fifteen {

    // Problem: Given array nums containing n distinct numbers in [0, n], return the only
    // number in [0, n] that is missing from the array.

    /**
     * Sum 0+1+...+n = n*(n+1)/2; subtract sum of nums to get missing number.
     * Time O(n), Space O(1)
     */
    public static int missingNumber(int[] nums) {
        if (nums == null) return 0;
        int n = nums.length;
        int expected = n * (n + 1) / 2;
        int actual = 0;
        for (int x : nums) actual += x;
        return expected - actual;
    }

    /**
     * XOR approach: xor all indices 0..n and all values; pairs cancel, result is missing.
     */
    public static int missingNumberXor(int[] nums) {
        if (nums == null) return 0;
        int x = 0;
        for (int i = 0; i < nums.length; i++) x ^= i ^ nums[i];
        return x ^ nums.length;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Missing Number");
        System.out.println("=".repeat(60));

        System.out.println("[3,0,1] -> " + missingNumber(new int[] { 3, 0, 1 }));
        System.out.println("[0,1] -> " + missingNumber(new int[] { 0, 1 }));
        System.out.println("[9,6,4,2,3,5,7,0,1] -> " + missingNumber(new int[] { 9, 6, 4, 2, 3, 5, 7, 0, 1 }));
    }
}
