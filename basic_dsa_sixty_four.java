/**
 * Basic DSA Problems - One More Fundamental Question
 * Simple and essential DSA problems for beginners
 */

public class basic_dsa_sixty_four {

    // Problem: First Non-Repeating Character in a String
    // Given a string, find the first character that does not repeat.
    // Return that character, or a placeholder (e.g. '\0' or null) if none exists.
    // Example: "leetcode" -> 'l', "aabb" -> no such character

    /**
     * Find first non-repeating character using frequency array
     * Time Complexity: O(n)
     * Space Complexity: O(1) for fixed character set (e.g. 256 for extended ASCII)
     */
    public static char firstNonRepeatingChar(String s) {
        if (s == null || s.isEmpty()) {
            return '\0';
        }

        int[] freq = new int[256];
        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i)]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (freq[s.charAt(i)] == 1) {
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
    public static int firstNonRepeatingCharIndex(String s) {
        if (s == null || s.isEmpty()) {
            return -1;
        }

        int[] freq = new int[256];
        for (int i = 0; i < s.length(); i++) {
            freq[s.charAt(i)]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (freq[s.charAt(i)] == 1) {
                return i;
            }
        }

        return -1;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: First Non-Repeating Character in a String");
        System.out.println("=".repeat(60));

        // Test Case 1 - "leetcode" -> 'l'
        String s1 = "leetcode";
        char result1 = firstNonRepeatingChar(s1);
        int index1 = firstNonRepeatingCharIndex(s1);
        System.out.println("String: \"" + s1 + "\"");
        System.out.println("First non-repeating char: " + (result1 == '\0' ? "none" : result1));
        System.out.println("Index: " + index1);

        // Test Case 2 - "aabb" -> none
        String s2 = "aabb";
        char result2 = firstNonRepeatingChar(s2);
        int index2 = firstNonRepeatingCharIndex(s2);
        System.out.println("\nString: \"" + s2 + "\"");
        System.out.println("First non-repeating char: " + (result2 == '\0' ? "none" : result2));
        System.out.println("Index: " + index2);

        // Test Case 3 - "loveleetcode" -> 'v'
        String s3 = "loveleetcode";
        char result3 = firstNonRepeatingChar(s3);
        int index3 = firstNonRepeatingCharIndex(s3);
        System.out.println("\nString: \"" + s3 + "\"");
        System.out.println("First non-repeating char: " + (result3 == '\0' ? "none" : result3));
        System.out.println("Index: " + index3);

        // Test Case 4 - single character
        String s4 = "z";
        char result4 = firstNonRepeatingChar(s4);
        System.out.println("\nString: \"" + s4 + "\"");
        System.out.println("First non-repeating char: " + result4);

        // Test Case 5 - "aabcc" -> 'b'
        String s5 = "aabcc";
        char result5 = firstNonRepeatingChar(s5);
        System.out.println("\nString: \"" + s5 + "\"");
        System.out.println("First non-repeating char: " + result5);
    }
}
