/**
 * Basic DSA Problems - First Unique Character in a String
 * Return index of first non-repeating character, or -1
 */
public class basic_dsa_two_hundred_twenty_three {

    // Problem: String s. Return index of first char that appears exactly once. -1 if none.

    /**
     * Two passes: count frequency; then find first with count 1.
     * Time O(n), Space O(1) alphabet
     */
    public static int firstUniqChar(String s) {
        int[] count = new int[26];
        for (char c : s.toCharArray()) count[c - 'a']++;
        for (int i = 0; i < s.length(); i++)
            if (count[s.charAt(i) - 'a'] == 1) return i;
        return -1;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: First Unique Character in a String");
        System.out.println("=".repeat(60));

        System.out.println("leetcode -> " + firstUniqChar("leetcode"));
        System.out.println("loveleetcode -> " + firstUniqChar("loveleetcode"));
        System.out.println("aabb -> " + firstUniqChar("aabb"));
    }
}
