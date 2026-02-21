/**
 * Basic DSA Problems - Integer Replacement (LeetCode 397)
 * n -> 1: even n/2, odd n+1 or n-1. Min steps.
 */
public class basic_dsa_three_hundred_ninety_seven {

    // Problem: n to 1. Even: n/2. Odd: n+1 or n-1. Min operations.

    /**
     * Greedy: odd n, pick n+1 or n-1 based on which gives more trailing zeros.
     * Special case n=3. Time O(log n), Space O(1)
     */
    public static int integerReplacement(int n) {
        int c = 0;
        long x = n;
        while (x > 1) {
            if (x % 2 == 0) { x /= 2; c++; }
            else if (x == 3) { x = 2; c++; }
            else {
                if ((x + 1) % 4 == 0) x++;
                else x--;
                c++;
            }
        }
        return c;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Integer Replacement");
        System.out.println("=".repeat(60));

        System.out.println("8 -> " + integerReplacement(8));
        System.out.println("7 -> " + integerReplacement(7));
    }
}
