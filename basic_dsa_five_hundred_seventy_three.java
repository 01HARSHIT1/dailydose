/**
 * Basic DSA Problems - One Fundamental String Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_seventy_three {

    // Problem 1: Repeated Substring Pattern
    // Given a string s, check if it can be constructed by taking a substring
    // and appending multiple copies of that substring together.
    //
    // Example:
    // s = "abab" -> true
    // s = "aba" -> false

    /**
     * Try all possible pattern lengths dividing n
     * Time Complexity: O(n^2) in worst case
     * Space Complexity: O(1)
     */
    public static Boolean repeatedSubstringPattern(String s) {
        if (s == null) {
            return null;
        }
        int n = s.length();
        if (n == 0) {
            return false;
        }

        for (int len = 1; len <= n / 2; len++) {
            if (n % len != 0) {
                continue;
            }

            boolean match = true;
            for (int i = len; i < n; i++) {
                if (s.charAt(i) != s.charAt(i % len)) {
                    match = false;
                    break;
                }
            }

            if (match) {
                return true;
            }
        }

        return false;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Repeated Substring Pattern");
        System.out.println("=".repeat(60));

        System.out.println("s = \"abab\" -> " + repeatedSubstringPattern("abab"));
        System.out.println("s = \"aba\" -> " + repeatedSubstringPattern("aba"));
        System.out.println("s = \"abcabcabcabc\" -> " + repeatedSubstringPattern("abcabcabcabc"));
        System.out.println("s = \"a\" -> " + repeatedSubstringPattern("a"));
        System.out.println("s = null -> " + repeatedSubstringPattern(null));
    }
}
