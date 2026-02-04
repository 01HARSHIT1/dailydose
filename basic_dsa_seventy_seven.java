/**
 * Basic DSA Problems - Single Number (XOR)
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_seventy_seven {

    // Problem: Every element appears twice except one. Find that single one.
    // Linear time, constant extra space. Example: [4,1,2,1,2] -> 4

    /**
     * XOR: a ^ a = 0, a ^ 0 = a. So xor of all gives the single number.
     * Time O(n), Space O(1)
     */
    public static int singleNumber(int[] nums) {
        if (nums == null || nums.length == 0) return -1;
        int xor = 0;
        for (int x : nums) xor ^= x;
        return xor;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Single Number");
        System.out.println("=".repeat(60));

        int[] a1 = { 2, 2, 1 };
        System.out.println("Array: " + Arrays.toString(a1) + " -> Single: " + singleNumber(a1));

        int[] a2 = { 4, 1, 2, 1, 2 };
        System.out.println("Array: " + Arrays.toString(a2) + " -> Single: " + singleNumber(a2));

        int[] a3 = { 1 };
        System.out.println("Array: " + Arrays.toString(a3) + " -> Single: " + singleNumber(a3));
    }
}
