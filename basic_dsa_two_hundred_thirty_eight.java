/**
 * Basic DSA Problems - First Unique Character in a String
 * Find the index of the first non-repeating character
 */
public class basic_dsa_two_hundred_thirty_eight {

    // Problem: Given string s, return index of first non-repeating char. Else -1.
    // Example: "leetcode" -> 0 (l); "aabb" -> -1

    /**
     * Count frequency of each char, then scan for first with count == 1.
     * Time O(n), Space O(1) - 26 chars
     */
    public static int firstUniqChar(String s) {
        int[] count = new int[26];
        for (int i = 0; i < s.length(); i++)
            count[s.charAt(i) - 'a']++;
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
