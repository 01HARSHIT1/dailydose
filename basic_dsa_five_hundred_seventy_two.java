/**
 * Basic DSA Problems - One Fundamental String + Hashing Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_seventy_two {

    // Problem 1: First Unique Character in a String
    // Given a string s, find the first non-repeating character in it
    // and return its index. If it does not exist, return -1.
    //
    // Example:
    // s = "leetcode" -> 0
    // s = "loveleetcode" -> 2

    /**
     * Frequency count then first index scan
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Integer firstUniqChar(String s) {
        if (s == null) {
            return null;
        }

        int[] freq = new int[26];
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (c < 'a' || c > 'z') {
                return null;
            }
            freq[c - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
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

        System.out.println("s = \"leetcode\" -> " + firstUniqChar("leetcode"));
        System.out.println("s = \"loveleetcode\" -> " + firstUniqChar("loveleetcode"));
        System.out.println("s = \"aabb\" -> " + firstUniqChar("aabb"));
        System.out.println("s = \"\" -> " + firstUniqChar(""));
        System.out.println("s = null -> " + firstUniqChar(null));
    }
}
