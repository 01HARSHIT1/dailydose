/**
 * Basic DSA Problems - First Unique Character in a String (LeetCode 387)
 * Index of first non-repeating character, or -1
 */
public class basic_dsa_three_hundred_eighty_seven {

    // Problem: Return index of first char that appears exactly once, else -1.

    /**
     * Count frequencies, then scan for first with count 1.
     * Time O(n), Space O(1)
     */
    public static int firstUniqChar(String s) {
        int[] freq = new int[26];
        for (char c : s.toCharArray()) freq[c - 'a']++;
        for (int i = 0; i < s.length(); i++)
            if (freq[s.charAt(i) - 'a'] == 1) return i;
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
