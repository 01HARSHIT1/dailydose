/**
 * Basic DSA Problems - Sum of Two Integers (LeetCode 371)
 * Add two integers without using + or -
 */
public class basic_dsa_three_hundred_seventy_one {

    // Problem: Return a + b without using + or -.

    /**
     * Bit manipulation: sum = a^b (xor), carry = (a&b)<<1. Repeat until no carry.
     * Time O(1) bits, Space O(1)
     */
    public static int getSum(int a, int b) {
        while (b != 0) {
            int carry = (a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Sum of Two Integers");
        System.out.println("=".repeat(60));

        System.out.println("1 + 2 = " + getSum(1, 2));
        System.out.println("2 + 3 = " + getSum(2, 3));
    }
}
