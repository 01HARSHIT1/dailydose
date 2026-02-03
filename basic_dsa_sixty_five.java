/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */
import java.util.*;

public class basic_dsa_sixty_five {

    // Problem: Valid Anagram
    // Given two strings s and t, return true if t is an anagram of s, else false.
    // An anagram is a word formed by rearranging the letters of another (same chars, same frequency).
    // Example: "anagram" & "nagaram" -> true, "rat" & "car" -> false

    /**
     * Check if t is anagram of s using frequency array
     * Time Complexity: O(n)
     * Space Complexity: O(1) for fixed character set
     */
    public static boolean isAnagram(String s, String t) {
        if (s == null || t == null || s.length() != t.length()) {
            return false;
        }

        int[] freq = new int[256];
        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i)]++;
            freq[t.charAt(i)]--;
        }

        for (int count : freq) {
            if (count != 0) {
                return false;
            }
        }
        return true;
    }

    /**
     * Check if t is anagram of s using sorting (alternative)
     * Time Complexity: O(n log n)
     * Space Complexity: O(n) for char arrays
     */
    public static boolean isAnagramSort(String s, String t) {
        if (s == null || t == null || s.length() != t.length()) {
            return false;
        }
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

        // Test 1: anagram, nagaram -> true
        String s1 = "anagram", t1 = "nagaram";
        System.out.println("s = \"" + s1 + "\", t = \"" + t1 + "\" -> " + isAnagram(s1, t1));

        // Test 2: rat, car -> false
        String s2 = "rat", t2 = "car";
        System.out.println("s = \"" + s2 + "\", t = \"" + t2 + "\" -> " + isAnagram(s2, t2));

        // Test 3: empty / same length
        String s3 = "a", t3 = "a";
        System.out.println("s = \"" + s3 + "\", t = \"" + t3 + "\" -> " + isAnagram(s3, t3));

        // Test 4: different lengths
        String s4 = "ab", t4 = "a";
        System.out.println("s = \"" + s4 + "\", t = \"" + t4 + "\" -> " + isAnagram(s4, t4));
    }
}
