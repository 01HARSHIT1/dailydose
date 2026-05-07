/**
 * Basic DSA Problems - One Fundamental Sliding Window Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_two {

    // Problem 1: Longest Substring Without Repeating Characters
    // Return the length of the longest substring of s that has no repeated characters.

    /**
     * Sliding window with last-seen index per ASCII character
     * Time Complexity: O(n)
     * Space Complexity: O(1) — fixed alphabet size
     */
    public static Integer lengthOfLongestSubstring(String s) {
        if (s == null) {
            return null;
        }

        int[] last = new int[128];
        for (int i = 0; i < 128; i++) {
            last[i] = -1;
        }

        int left = 0;
        int max = 0;

        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            if (last[c] >= left) {
                left = last[c] + 1;
            }
            last[c] = right;
            max = Math.max(max, right - left + 1);
        }

        return max;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Longest Substring Without Repeating Characters");
        System.out.println("=".repeat(60));

        System.out.println("\"abcabcbb\" -> " + lengthOfLongestSubstring("abcabcbb"));
        System.out.println("\"bbbbb\" -> " + lengthOfLongestSubstring("bbbbb"));
        System.out.println("\"pwwkew\" -> " + lengthOfLongestSubstring("pwwkew"));
        System.out.println("\"\" -> " + lengthOfLongestSubstring(""));
        System.out.println("null -> " + lengthOfLongestSubstring(null));
    }
}
