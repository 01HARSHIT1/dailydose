/**
 * Basic DSA Problems - One Fundamental Math Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_fifty_three {

    // Problem 1: Palindrome Number
    // Given an integer x, return true if x is a palindrome, and false otherwise.
    //
    // A palindrome number reads the same backward as forward.
    //
    // Example:
    // x = 121 -> true
    // x = -121 -> false

    /**
     * Reverse only half of the number
     * Time Complexity: O(log10 n)
     * Space Complexity: O(1)
     */
    public static Boolean isPalindromeNumber(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        return x == reversedHalf || x == reversedHalf / 10;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Palindrome Number");
        System.out.println("=".repeat(60));

        System.out.println("x = 121 -> " + isPalindromeNumber(121));
        System.out.println("x = -121 -> " + isPalindromeNumber(-121));
        System.out.println("x = 10 -> " + isPalindromeNumber(10));
        System.out.println("x = 0 -> " + isPalindromeNumber(0));
        System.out.println("x = 12321 -> " + isPalindromeNumber(12321));
    }
}
