/**
 * Basic DSA Problems - Repeated Substring Pattern
 * Check if string can be formed by repeating a substring
 */
public class basic_dsa_two_hundred_twenty_five {

    // Problem: String s. Return true if s = substring repeated multiple times (e.g. "abab" = "ab" twice).

    /**
     * Try period len from 1 to n/2. If n % len == 0, check if s = (s[0..len-1]) repeated.
     * Time O(n * d(n)), Space O(n) for substring, or O(1) with index check
     */
    public static boolean repeatedSubstringPattern(String s) {
        int n = s.length();
        for (int len = 1; len <= n / 2; len++) {
            if (n % len != 0) continue;
            String sub = s.substring(0, len);
            boolean ok = true;
            for (int i = len; i < n; i += len)
                if (!s.substring(i, i + len).equals(sub)) { ok = false; break; }
            if (ok) return true;
        }
        return false;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Repeated Substring Pattern");
        System.out.println("=".repeat(60));

        System.out.println("abab -> " + repeatedSubstringPattern("abab"));
        System.out.println("aba -> " + repeatedSubstringPattern("aba"));
        System.out.println("abcabcabcabc -> " + repeatedSubstringPattern("abcabcabcabc"));
    }
}
