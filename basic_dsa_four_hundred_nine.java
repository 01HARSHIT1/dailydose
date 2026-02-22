/**
 * Basic DSA Problems - Longest Palindrome (LeetCode 409)
 * Max length palindrome from rearranging chars of s
 */
public class basic_dsa_four_hundred_nine {

    // Problem: s. Rearrange chars. Return max length of palindrome.

    /**
     * Even freq -> all used. Odd freq -> use freq-1, one odd for center.
     * Time O(n), Space O(1)
     */
    public static int longestPalindrome(String s) {
        int[] freq = new int[128];
        for (char c : s.toCharArray()) freq[c]++;
        int len = 0;
        boolean hasOdd = false;
        for (int f : freq) {
            len += (f / 2) * 2;
            if (f % 2 == 1) hasOdd = true;
        }
        return len + (hasOdd ? 1 : 0);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Longest Palindrome");
        System.out.println("=".repeat(60));

        System.out.println("abccccdd -> " + longestPalindrome("abccccdd"));
        System.out.println("a -> " + longestPalindrome("a"));
    }
}
