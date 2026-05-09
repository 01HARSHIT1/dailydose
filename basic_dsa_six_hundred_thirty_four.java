import java.util.Arrays;

/**
 * Basic DSA Problems - One Fundamental Bijection / Mapping Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_thirty_four {

    // Problem 1: Isomorphic Strings
    // Characters of s can be replaced to get t; one-to-one mapping (ASCII).

    /**
     * Two fixed-size maps: s->t and t->s must stay consistent
     * Time Complexity: O(n)
     * Space Complexity: O(1) — alphabet size
     */
    public static Boolean isIsomorphic(String s, String t) {
        if (s == null || t == null) {
            return null;
        }
        if (s.length() != t.length()) {
            return false;
        }

        int[] sToT = new int[256];
        int[] tToS = new int[256];
        Arrays.fill(sToT, -1);
        Arrays.fill(tToS, -1);

        for (int i = 0; i < s.length(); i++) {
            int a = s.charAt(i);
            int b = t.charAt(i);

            if (sToT[a] == -1 && tToS[b] == -1) {
                sToT[a] = b;
                tToS[b] = a;
            } else if (sToT[a] != b || tToS[b] != a) {
                return false;
            }
        }

        return true;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Isomorphic Strings");
        System.out.println("=".repeat(60));

        System.out.println("egg, add -> " + isIsomorphic("egg", "add"));
        System.out.println("foo, bar -> " + isIsomorphic("foo", "bar"));
        System.out.println("paper, title -> " + isIsomorphic("paper", "title"));
        System.out.println("ab, aa -> " + isIsomorphic("ab", "aa"));
        System.out.println("null -> " + isIsomorphic(null, "a"));
    }
}
