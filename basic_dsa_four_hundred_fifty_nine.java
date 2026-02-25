/**
 * Basic DSA Problems - Repeated Substring Pattern (LeetCode 459)
 * Check if s = substring repeated multiple times
 */
public class basic_dsa_four_hundred_fifty_nine {

    // Problem: "abab" = "ab"*2 -> true. "aba" -> false.

    /**
     * Trick: (s+s) without first and last char contains s iff s is repeated.
     * Time O(n), Space O(n)
     */
    public static boolean repeatedSubstringPattern(String s) {
        String t = (s + s).substring(1, 2 * s.length() - 1);
        return t.contains(s);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Repeated Substring Pattern");
        System.out.println("=".repeat(60));

        System.out.println("\"abab\" -> " + repeatedSubstringPattern("abab"));
        System.out.println("\"aba\" -> " + repeatedSubstringPattern("aba"));
        System.out.println("\"abcabcabcabc\" -> " + repeatedSubstringPattern("abcabcabcabc"));
    }
}
