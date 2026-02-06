/**
 * Basic DSA Problems - Longest Substring Without Repeating Characters
 * Find length of longest substring with all distinct characters
 */
import java.util.*;

public class basic_dsa_one_hundred_ten {

    // Problem: Given a string s, find the length of the longest substring
    // without repeating characters.

    /**
     * Sliding window with HashSet: expand with right, shrink from left when duplicate seen.
     * Time O(n), Space O(min(n, charset))
     */
    public static int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) return 0;
        Set<Character> set = new HashSet<>();
        int left = 0, maxLen = 0;
        for (int right = 0; right < s.length(); right++) {
            while (set.contains(s.charAt(right))) {
                set.remove(s.charAt(left++));
            }
            set.add(s.charAt(right));
            maxLen = Math.max(maxLen, right - left + 1);
        }
        return maxLen;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Longest Substring Without Repeating Characters");
        System.out.println("=".repeat(60));

        System.out.println("\"abcabcbb\" -> " + lengthOfLongestSubstring("abcabcbb"));
        System.out.println("\"bbbbb\" -> " + lengthOfLongestSubstring("bbbbb"));
        System.out.println("\"pwwkew\" -> " + lengthOfLongestSubstring("pwwkew"));
    }
}
