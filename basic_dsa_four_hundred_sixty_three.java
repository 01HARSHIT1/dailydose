/**
 * Basic DSA Problems - One Fundamental Hashing/String Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_sixty_three {
    
    // Problem 1: First Unique Character in a String
    // Given a string s, find the first non-repeating character in it and return its index.
    // If it does not exist, return -1.
    //
    // Notes:
    // - This implementation assumes lowercase English letters a-z for O(1) space.
    //
    // Example:
    // s = "leetcode" -> 0
    // s = "loveleetcode" -> 2
    // s = "aabb" -> -1
    
    /**
     * Find the index of the first unique character (lowercase a-z)
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static int firstUniqueCharIndex(String s) {
        if (s == null) {
            return -1;
        }
        
        int n = s.length();
        if (n == 0) {
            return -1;
        }
        
        int[] freq = new int[26];
        
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (c < 'a' || c > 'z') {
                return -1;
            }
            freq[c - 'a']++;
        }
        
        for (int i = 0; i < n; i++) {
            if (freq[s.charAt(i) - 'a'] == 1) {
                return i;
            }
        }
        
        return -1;
    }
    
    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: First Unique Character in a String");
        System.out.println("=".repeat(60));
        
        // Test Case 1
        String s1 = "leetcode";
        System.out.println("Input: " + s1);
        System.out.println("Index: " + firstUniqueCharIndex(s1));
        
        // Test Case 2
        String s2 = "loveleetcode";
        System.out.println("\nInput: " + s2);
        System.out.println("Index: " + firstUniqueCharIndex(s2));
        
        // Test Case 3 - No unique character
        String s3 = "aabb";
        System.out.println("\nInput: " + s3);
        System.out.println("Index: " + firstUniqueCharIndex(s3));
        
        // Test Case 4 - Empty string
        String s4 = "";
        System.out.println("\nInput: \"\"");
        System.out.println("Index: " + firstUniqueCharIndex(s4));
        
        // Test Case 5 - Null
        System.out.println("\nInput: null");
        System.out.println("Index: " + firstUniqueCharIndex(null));
        
        // Test Case 6 - Invalid character (by this implementation)
        String s6 = "aA";
        System.out.println("\nInput: " + s6);
        System.out.println("Index: " + firstUniqueCharIndex(s6));
    }
}

