/**
 * Basic DSA Problems - Is Subsequence (LeetCode 392)
 * Check if s is a subsequence of t (order preserved)
 */
public class basic_dsa_three_hundred_ninety_two {

    // Problem: s, t. Return true if s is subsequence of t.

    /**
     * Two pointers: match s[i] in t from left. If all matched, true.
     * Time O(m+n), Space O(1)
     */
    public static boolean isSubsequence(String s, String t) {
        int i = 0;
        for (int j = 0; i < s.length() && j < t.length(); j++)
            if (s.charAt(i) == t.charAt(j)) i++;
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
