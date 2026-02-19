/**
 * Basic DSA Problems - Super Pow (LeetCode 372)
 * Compute a^b mod 1337, b given as digit array
 */
public class basic_dsa_three_hundred_seventy_two {

    // Problem: a, b as digit array. Return a^b mod 1337.

    static final int M = 1337;

    /**
     * a^(10k+d) = (a^10)^k * a^d. Process digits right to left.
     * Time O(n), Space O(1)
     */
    public static int superPow(int a, int[] b) {
        a %= M;
        int out = 1;
        for (int i = b.length - 1; i >= 0; i--) {
            out = (out * pow(a, b[i])) % M;
            a = pow(a, 10);
        }
        return out;
    }

    private static int pow(int base, int exp) {
        int r = 1;
        base %= M;
        while (exp > 0) {
            if ((exp & 1) == 1) r = (r * base) % M;
            base = (base * base) % M;
            exp >>= 1;
        }
        return r;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Super Pow");
        System.out.println("=".repeat(60));

        System.out.println("a=2, b=[3] -> " + superPow(2, new int[]{3}));
        System.out.println("a=2, b=[1,0] -> " + superPow(2, new int[]{1, 0}));
    }
}
