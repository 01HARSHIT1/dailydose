/**
 * Basic DSA Problems - Longest Substring Without Repeating Characters
 * Find length of longest substring with unique chars
 */
public class basic_dsa_three_hundred_twenty {

    // Problem: String s. Return length of longest substring without repeating characters.

    /**
     * Sliding window: track chars in window with freq map. Expand right; shrink left when duplicate.
     * Time O(n), Space O(min(n, alphabet))
     */
    public static int lengthOfLongestSubstring(String s) {
        int[] seen = new int[128];
        int max = 0, lo = 0;
        for (int hi = 0; hi < s.length(); hi++) {
            char c = s.charAt(hi);
            seen[c]++;
            while (seen[c] > 1) {
                seen[s.charAt(lo++)]--;
            }
            max = Math.max(max, hi - lo + 1);
        }
        return max;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Longest Substring Without Repeating Characters");
        System.out.println("=".repeat(60));

        System.out.println("abcabcbb -> " + lengthOfLongestSubstring("abcabcbb"));
        System.out.println("bbbbb -> " + lengthOfLongestSubstring("bbbbb"));
        System.out.println("pwwkew -> " + lengthOfLongestSubstring("pwwkew"));
    }
}
