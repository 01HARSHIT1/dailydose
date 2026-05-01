/**
 * Basic DSA Problems - One Fundamental String + Hashing Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_twenty_eight {

    // Problem 1: Valid Anagram
    // Given two strings s and t, return true if t is an anagram of s, and false otherwise.
    //
    // Example:
    // s = "anagram", t = "nagaram" -> true
    // s = "rat", t = "car"         -> false

    /**
     * Frequency-count based comparison for lowercase English letters
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Boolean isAnagram(String s, String t) {
        if (s == null || t == null) {
            return null;
        }
        if (s.length() != t.length()) {
            return false;
        }

        int[] freq = new int[26];
        for (int i = 0; i < s.length(); i++) {
            char a = s.charAt(i);
            char b = t.charAt(i);
            if (a < 'a' || a > 'z' || b < 'a' || b > 'z') {
                return false;
            }
            freq[a - 'a']++;
            freq[b - 'a']--;
        }

        for (int count : freq) {
            if (count != 0) {
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

        System.out.println("s = \"anagram\", t = \"nagaram\" -> " + isAnagram("anagram", "nagaram"));
        System.out.println("s = \"rat\", t = \"car\" -> " + isAnagram("rat", "car"));
        System.out.println("s = \"aa\", t = \"a\" -> " + isAnagram("aa", "a"));
        System.out.println("s = \"listen\", t = \"silent\" -> " + isAnagram("listen", "silent"));
        System.out.println("s = null, t = \"abc\" -> " + isAnagram(null, "abc"));
    }
}
