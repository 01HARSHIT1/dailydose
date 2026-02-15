/**
 * Basic DSA Problems - Valid Anagram
 * Check if two strings are anagrams
 */
public class basic_dsa_three_hundred_eleven {

    // Problem: Two strings s and t. Return true if t is anagram of s (same chars, different order).

    /**
     * Count chars in s, subtract chars in t. All counts must be zero.
     * Time O(n), Space O(1) - 26 chars
     */
    public static boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        int[] count = new int[26];
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
            count[t.charAt(i) - 'a']--;
        }
        for (int c : count) if (c != 0) return false;
        return true;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Valid Anagram");
        System.out.println("=".repeat(60));

        System.out.println("anagram, nagaram -> " + isAnagram("anagram", "nagaram"));
        System.out.println("rat, car -> " + isAnagram("rat", "car"));
        System.out.println("a, ab -> " + isAnagram("a", "ab"));
    }
}
