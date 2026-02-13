/**
 * Basic DSA Problems - Ugly Number
 * Check if number has only prime factors 2, 3, 5
 */
public class basic_dsa_two_hundred_sixty_one {

    // Problem: Ugly numbers are positive integers whose prime factors are only 2, 3, 5.
    // Return true if n is ugly. 1 is typically considered ugly.

    /**
     * Divide by 2, 3, 5 repeatedly until 1 or other prime remains.
     * Time O(log n), Space O(1)
     */
    public static boolean isUgly(int n) {
        if (n <= 0) return false;
        for (int p : new int[]{2, 3, 5})
            while (n % p == 0) n /= p;
        return n == 1;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Ugly Number");
        System.out.println("=".repeat(60));

        System.out.println("6 -> " + isUgly(6));
        System.out.println("1 -> " + isUgly(1));
        System.out.println("14 -> " + isUgly(14));
        System.out.println("8 -> " + isUgly(8));
    }
}
