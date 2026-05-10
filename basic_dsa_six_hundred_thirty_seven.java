/**
 * Basic DSA Problems - One Fundamental Number Theory Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_thirty_seven {

    // Problem 1: Factorial Trailing Zeroes
    // For n!, count how many times 10 divides it — same as min(2s, 5s) in prime factors; always enough 2s.

    /**
     * Count multiples of 5, 25, 125, ... in 1..n
     * Time Complexity: O(log5 n)
     * Space Complexity: O(1)
     */
    public static int trailingZeroes(int n) {
        int count = 0;
        long m = n;
        while (m > 0) {
            m /= 5;
            count += m;
        }
        return count;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Factorial Trailing Zeroes");
        System.out.println("=".repeat(60));

        System.out.println("n=3 -> " + trailingZeroes(3));
        System.out.println("n=5 -> " + trailingZeroes(5));
        System.out.println("n=0 -> " + trailingZeroes(0));
        System.out.println("n=25 -> " + trailingZeroes(25));
        System.out.println("n=30 -> " + trailingZeroes(30));
    }
}
