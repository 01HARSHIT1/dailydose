/**
 * Basic DSA Problems - Valid Anagram
 * Check if two strings are anagrams of each other
 */
public class basic_dsa_two_hundred_ninety_five {

    // Problem: Given two strings s and t, return true if t is an anagram of s.
    // An anagram is when both strings have the same characters with the same frequency.

    /**
     * Use frequency array. Count chars in s, decrement in t.
     * Time O(n), Space O(1) - fixed 26 chars
     */
    public static boolean isAnagram(String s, String t) {
        if (s.length() != t.length()) return false;
        int[] freq = new int[26];
        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i) - 'a']++;
            freq[t.charAt(i) - 'a']--;
        }
        for (int c : freq)
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
