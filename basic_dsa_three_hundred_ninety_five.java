/**
 * Basic DSA Problems - Longest Substring with At Least K Repeating (LeetCode 395)
 * Longest substring where every char appears >= k times
 */
public class basic_dsa_three_hundred_ninety_five {

    // Problem: s, k. Longest substring with each char freq >= k.

    /**
     * Divide at chars with freq < k. Recurse on parts.
     * Time O(n), Space O(n)
     */
    public static int longestSubstring(String s, int k) {
        if (s.length() < k) return 0;
        int[] freq = new int[26];
        for (char c : s.toCharArray()) freq[c - 'a']++;
        int bad = -1;
        for (int i = 0; i < 26; i++)
            if (freq[i] > 0 && freq[i] < k) { bad = i; break; }
        if (bad == -1) return s.length();
        int max = 0;
        for (String part : s.split(Character.toString((char) ('a' + bad))))
            max = Math.max(max, longestSubstring(part, k));
        return max;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Longest Substring with At Least K Repeating");
        System.out.println("=".repeat(60));

        System.out.println("aaabb, k=3 -> " + longestSubstring("aaabb", 3));
        System.out.println("ababbc, k=2 -> " + longestSubstring("ababbc", 2));
    }
}
