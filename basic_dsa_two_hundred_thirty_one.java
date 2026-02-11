/**
 * Basic DSA Problems - Is Subsequence
 * Check if s is subsequence of t (relative order preserved)
 */
public class basic_dsa_two_hundred_thirty_one {

    // Problem: s and t. Return true if s is subsequence of t.

    /**
     * Two pointers: match s[i] with t[j]; advance j always, i when match. True if i reached end of s.
     * Time O(|t|), Space O(1)
     */
    public static boolean isSubsequence(String s, String t) {
        int i = 0, j = 0;
        while (i < s.length() && j < t.length()) {
            if (s.charAt(i) == t.charAt(j)) i++;
            j++;
        }
        return i == s.length();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Is Subsequence");
        System.out.println("=".repeat(60));

        System.out.println("abc, ahbgdc -> " + isSubsequence("abc", "ahbgdc"));
        System.out.println("axc, ahbgdc -> " + isSubsequence("axc", "ahbgdc"));
    }
}
