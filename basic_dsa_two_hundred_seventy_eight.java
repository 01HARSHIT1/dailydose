/**
 * Basic DSA Problems - Isomorphic Strings
 * Check if two strings have same character mapping
 */
public class basic_dsa_two_hundred_seventy_eight {

    // Problem: s and t same length. Return true if chars in s can be replaced to get t (bijection).
    // "egg" and "add" -> true (e->a, g->d). "foo" and "bar" -> false.

    /**
     * Two maps: s[i]->t[i] and t[i]->s[i]. Check bijection.
     * Time O(n), Space O(1) - fixed charset
     */
    public static boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) return false;
        int[] sToT = new int[256];
        int[] tToS = new int[256];
        for (int i = 0; i < s.length(); i++) {
            char a = s.charAt(i), b = t.charAt(i);
            if (sToT[a] != 0 && sToT[a] != b + 1) return false;
            if (tToS[b] != 0 && tToS[b] != a + 1) return false;
            sToT[a] = b + 1;
            tToS[b] = a + 1;
        }
        return true;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Isomorphic Strings");
        System.out.println("=".repeat(60));

        System.out.println("egg, add -> " + isIsomorphic("egg", "add"));
        System.out.println("foo, bar -> " + isIsomorphic("foo", "bar"));
        System.out.println("paper, title -> " + isIsomorphic("paper", "title"));
    }
}
