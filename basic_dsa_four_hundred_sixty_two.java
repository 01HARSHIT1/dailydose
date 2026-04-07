/**
 * Basic DSA Problems - One Fundamental String Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_sixty_two {
    
    // Problem 1: Valid Anagram
    // Given two strings s and t, return true if t is an anagram of s, and false otherwise.
    //
    // Notes:
    // - An anagram uses the same characters with the same frequencies.
    // - This implementation assumes lowercase English letters a-z for optimal space.
    //
    // Example:
    // s = "anagram", t = "nagaram" -> true
    // s = "rat", t = "car" -> false
    
    /**
     * Check if two strings are anagrams (lowercase a-z)
     * Time Complexity: O(n + m)
     * Space Complexity: O(1)
     */
    public static boolean isAnagram(String s, String t) {
        if (s == null || t == null) {
            return false;
        }
        if (s.length() != t.length()) {
            return false;
        }
        
        int[] freq = new int[26];
        
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c < 'a' || c > 'z') {
                return false;
            }
            freq[c - 'a']++;
        }
        
        for (int i = 0; i < t.length(); i++) {
            char c = t.charAt(i);
            if (c < 'a' || c > 'z') {
                return false;
            }
            int idx = c - 'a';
            freq[idx]--;
            if (freq[idx] < 0) {
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
        
        // Test Case 1 - Anagram
        String s1 = "anagram";
        String t1 = "nagaram";
        System.out.println("s = " + s1 + ", t = " + t1);
        System.out.println("Is Anagram: " + isAnagram(s1, t1));
        
        // Test Case 2 - Not anagram
        String s2 = "rat";
        String t2 = "car";
        System.out.println("\ns = " + s2 + ", t = " + t2);
        System.out.println("Is Anagram: " + isAnagram(s2, t2));
        
        // Test Case 3 - Different lengths
        String s3 = "aacc";
        String t3 = "ccac";
        System.out.println("\ns = " + s3 + ", t = " + t3);
        System.out.println("Is Anagram: " + isAnagram(s3, t3));
        
        // Test Case 4 - Empty strings
        String s4 = "";
        String t4 = "";
        System.out.println("\ns = \"\", t = \"\"");
        System.out.println("Is Anagram: " + isAnagram(s4, t4));
        
        // Test Case 5 - Null input
        System.out.println("\ns = null, t = \"abc\"");
        System.out.println("Is Anagram: " + isAnagram(null, "abc"));
        
        // Test Case 6 - Non-lowercase character (invalid per this implementation)
        String s6 = "Listen";
        String t6 = "Silent";
        System.out.println("\ns = " + s6 + ", t = " + t6);
        System.out.println("Is Anagram: " + isAnagram(s6, t6));
    }
}

