/**
 * Basic DSA Problems - One Fundamental Frequency Count Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_twenty_three {

    // Problem 1: First Unique Character in a String
    // s has only lowercase English letters. Return the index of the first non-repeating char, or -1.

    /**
     * Two passes: count letters, then scan left to right for count 1
     * Time Complexity: O(n)
     * Space Complexity: O(1) — 26 counts
     */
    public static Integer firstUniqChar(String s) {
        if (s == null) {
            return null;
        }

        int[] count = new int[26];
        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (count[s.charAt(i) - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: First Unique Character");
        System.out.println("=".repeat(60));

        System.out.println("leetcode -> " + firstUniqChar("leetcode"));
        System.out.println("loveleetcode -> " + firstUniqChar("loveleetcode"));
        System.out.println("aabb -> " + firstUniqChar("aabb"));
        System.out.println("z -> " + firstUniqChar("z"));
        System.out.println("null -> " + firstUniqChar(null));
    }
}
