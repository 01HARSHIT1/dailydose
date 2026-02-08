/**
 * Basic DSA Problems - Valid Anagram
 * Check if two strings are anagrams of each other
 */
public class basic_dsa_one_hundred_twelve {

    // Problem: Given two strings s and t, return true if t is an anagram of s.
    // Anagram = same characters, same frequency, different order.

    /**
     * Count character frequencies; strings must have same length and same counts.
     * Time O(n), Space O(1) - fixed 26-letter alphabet
     */
    public static boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        int[] count = new int[26];
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
            count[t.charAt(i) - 'a']--;
        }
        for (int c : count)
            if (c != 0) return false;
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
