/**
 * Basic DSA Problems - One Fundamental Integer Manipulation Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_twenty_seven {

    // Problem 1: Palindrome Number
    // Return true iff integer x reads the same forward and backward (no extra string conversion).

    /**
     * Reverse only the second half of digits and compare to the first half
     * Time Complexity: O(log10 x)
     * Space Complexity: O(1)
     */
    public static boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        if (x % 10 == 0 && x != 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }

        int reversedHalf = 0;
        int n = x;
        while (n > reversedHalf) {
            reversedHalf = reversedHalf * 10 + n % 10;
            n /= 10;
        }

        return n == reversedHalf || n == reversedHalf / 10;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Palindrome Number");
        System.out.println("=".repeat(60));

        System.out.println("121 -> " + isPalindrome(121));
        System.out.println("-121 -> " + isPalindrome(-121));
        System.out.println("10 -> " + isPalindrome(10));
        System.out.println("1001 -> " + isPalindrome(1001));
        System.out.println("0 -> " + isPalindrome(0));
        System.out.println("1221 -> " + isPalindrome(1221));
        System.out.println("7 -> " + isPalindrome(7));
    }
}
