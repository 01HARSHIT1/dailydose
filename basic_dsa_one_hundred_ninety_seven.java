/**
 * Basic DSA Problems - Longest Substring Without Repeating Characters
 * Length of longest substring with all distinct characters
 */
import java.util.HashMap;
import java.util.Map;

public class basic_dsa_one_hundred_ninety_seven {

    // Problem: String s. Return length of longest substring without repeating characters.

    /**
     * Sliding window + map (char -> last index). Extend right; if char seen, move left past it.
     * Time O(n), Space O(min(n, alphabet))
     */
    public static int lengthOfLongestSubstring(String s) {
        Map<Character, Integer> idx = new HashMap<>();
        int max = 0, left = 0;
        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            if (idx.containsKey(c) && idx.get(c) >= left)
                left = idx.get(c) + 1;
            idx.put(c, right);
            max = Math.max(max, right - left + 1);
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
