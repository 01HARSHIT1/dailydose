
/**
 * Basic DSA Problems - First Non-Repeating Character
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_seventy_two {

    // Problem: Find the first non-repeating character in a string
    // Return the character that appears exactly once and comes first, or '\0' if
    // none
    // Example: "leetcode" -> 'l', "aabb" -> '\0'

    /**
     * Find first non-repeating character using frequency map
     * Time Complexity: O(n)
     * Space Complexity: O(1) — at most 26/256 distinct characters
     */
    public static char firstNonRepeatingChar(String s) {
        if (s == null || s.isEmpty()) {
            return '\0';
        }

        Map<Character, Integer> freq = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }

        for (int i = 0; i < s.length(); i++) {
            if (freq.get(s.charAt(i)) == 1) {
                return s.charAt(i);
            }
        }
        return '\0';
    }

    /**
     * Find index of first non-repeating character (-1 if none)
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int firstNonRepeatingIndex(String s) {
        if (s == null || s.isEmpty()) {
            return -1;
        }

        Map<Character, Integer> freq = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            freq.put(c, freq.getOrDefault(c, 0) + 1);
        }

        for (int i = 0; i < s.length(); i++) {
            if (freq.get(s.charAt(i)) == 1) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: First Non-Repeating Character");
        System.out.println("=".repeat(60));

        // Test 1
        String s1 = "leetcode";
        char r1 = firstNonRepeatingChar(s1);
        System.out.println("String: \"" + s1 + "\" -> First non-repeating: " + (r1 == '\0' ? "none" : r1));

        // Test 2
        String s2 = "aabb";
        char r2 = firstNonRepeatingChar(s2);
        System.out.println("String: \"" + s2 + "\" -> First non-repeating: " + (r2 == '\0' ? "none" : r2));

        // Test 3
        String s3 = "loveleetcode";
        char r3 = firstNonRepeatingChar(s3);
        int idx3 = firstNonRepeatingIndex(s3);
        System.out.println("String: \"" + s3 + "\" -> First non-repeating: " + r3 + " at index " + idx3);

        // Test 4 — single char
        String s4 = "z";
        char r4 = firstNonRepeatingChar(s4);
        System.out.println("String: \"" + s4 + "\" -> First non-repeating: " + r4);
    }
}
