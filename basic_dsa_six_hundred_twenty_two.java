/**
 * Basic DSA Problems - One Fundamental Frequency Count Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_twenty_two {

    // Problem 1: Valid Anagram
    // Strings s and t use lowercase English letters only. Return true iff t is an anagram of s.

    /**
     * Letter counts must match; single pass difference array for a..z
     * Time Complexity: O(n)
     * Space Complexity: O(1) — 26 counters
     */
    public static Boolean isAnagram(String s, String t) {
        if (s == null || t == null) {
            return null;
        }
        if (s.length() != t.length()) {
            return false;
        }

        int[] diff = new int[26];
        for (int i = 0; i < s.length(); i++) {
            diff[s.charAt(i) - 'a']++;
            diff[t.charAt(i) - 'a']--;
        }

        for (int d : diff) {
            if (d != 0) {
                return false;
            }
        }
        return true;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Valid Anagram");
        System.out.println("=".repeat(60));

        System.out.println("anagram / nagaram -> " + isAnagram("anagram", "nagaram"));
        System.out.println("rat / car -> " + isAnagram("rat", "car"));
        System.out.println("a / ab -> " + isAnagram("a", "ab"));
        System.out.println("null -> " + isAnagram(null, "a"));
    }
}
