/**
 * Basic DSA Problems - Isomorphic Strings
 * Check if two strings are isomorphic (one-to-one mapping of characters)
 */
import java.util.HashMap;
import java.util.Map;

public class basic_dsa_two_hundred_ten {

    // Problem: s and t same length. Return true if we can map chars of s to t (and vice versa) preserving order.

    /**
     * Map s[i] -> t[i] and t[i] -> s[i]. Conflict => not isomorphic.
     * Time O(n), Space O(1) alphabet
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
    }
}
