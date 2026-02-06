/**
 * Basic DSA Problems - Palindrome Number
 * Check if integer is a palindrome without converting to string
 */
public class basic_dsa_one_hundred_eleven {

    // Problem: Given integer x, return true if x is a palindrome (reads same forward and backward).
    // Solve without converting to string. Negative numbers are not palindromes.

    /**
     * Reverse half of the number and compare with the other half.
     * Time O(log n), Space O(1)
     */
    public static boolean isPalindrome(int x) {
        if (x < 0 || (x != 0 && x % 10 == 0)) return false;
        int half = 0;
        while (x > half) {
            half = half * 10 + x % 10;
            x /= 10;
        }
        return x == half || x == half / 10;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Palindrome Number");
        System.out.println("=".repeat(60));

        System.out.println("121 -> " + isPalindrome(121));
        System.out.println("-121 -> " + isPalindrome(-121));
        System.out.println("10 -> " + isPalindrome(10));
        System.out.println("0 -> " + isPalindrome(0));
    }
}
