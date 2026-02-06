/**
 * Basic DSA Problems - Valid Anagram
 * Check if two strings are anagrams (same characters with same frequency)
 */
import java.util.*;

public class basic_dsa_ninety_seven {

    // Problem: Given two strings s and t, return true if t is an anagram of s, else false.
    // An anagram is a word formed by rearranging the letters of another (e.g. "listen" <-> "silent").

    /**
     * Count character frequencies in s, decrement using t; if any count != 0, not anagram.
     * Time O(n), Space O(1) - at most 26/128 chars
     */
    public static boolean isAnagram(String s, String t) {
        if (s == null || t == null) return false;
        if (s.length() != t.length()) return false;

        int[] count = new int[128]; // ASCII
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i)]++;
            count[t.charAt(i)]--;
        }
        for (int c : count) {
            if (c != 0) return false;
        }
        return true;
    }

    /**
     * Alternative: sort both and compare (simpler but O(n log n) time).
     */
    public static boolean isAnagramSort(String s, String t) {
        if (s == null || t == null || s.length() != t.length()) return false;
        char[] a = s.toCharArray();
        char[] b = t.toCharArray();
        Arrays.sort(a);
        Arrays.sort(b);
        return Arrays.equals(a, b);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Valid Anagram");
        System.out.println("=".repeat(60));

        System.out.println("listen, silent -> " + isAnagram("listen", "silent"));
        System.out.println("anagram, nagaram -> " + isAnagram("anagram", "nagaram"));
        System.out.println("rat, car -> " + isAnagram("rat", "car"));
        System.out.println("a, ab -> " + isAnagram("a", "ab"));
        System.out.println("\"\", \"\" -> " + isAnagram("", ""));
    }
}
