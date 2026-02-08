/**
 * Basic DSA Problems - Isomorphic Strings
 * Check if two strings are isomorphic
 */
import java.util.HashMap;
import java.util.Map;

public class basic_dsa_one_hundred_forty_three {

    // Problem: Two strings s and t are isomorphic if we can replace chars in s to get t (and vice versa).
    // All occurrences of a char must map to same char. No two chars map to same char.
    // Example: "egg" and "add" -> true (e->a, g->d). "foo" and "bar" -> false.

    /**
     * Use two maps: s->t and t->s to ensure bijection
     * Time O(n), Space O(1) - at most 26 chars
     */
    public static boolean isIsomorphic(String s, String t) {
        if (s.length() != t.length()) return false;
        Map<Character, Character> st = new HashMap<>();
        Map<Character, Character> ts = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char a = s.charAt(i), b = t.charAt(i);
            if (st.containsKey(a) && st.get(a) != b) return false;
            if (ts.containsKey(b) && ts.get(b) != a) return false;
            st.put(a, b);
            ts.put(b, a);
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
        System.out.println("badc, baba -> " + isIsomorphic("badc", "baba"));
    }
}
