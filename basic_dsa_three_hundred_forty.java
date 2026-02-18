/**
 * Basic DSA Problems - Longest Substring with At Most K Distinct (LeetCode 340)
 * Max length of substring with at most k distinct characters
 */
public class basic_dsa_three_hundred_forty {

    // Problem: String s, int k. Return length of longest substring with <= k distinct chars.

    /**
     * Sliding window. Expand right, shrink left when distinct > k.
     * Time O(n), Space O(k)
     */
    public static int lengthOfLongestSubstringKDistinct(String s, int k) {
        if (k == 0) return 0;
        int max = 0, left = 0;
        java.util.Map<Character, Integer> freq = new java.util.HashMap<>();
        for (int right = 0; right < s.length(); right++) {
            char c = s.charAt(right);
            freq.put(c, freq.getOrDefault(c, 0) + 1);
            while (freq.size() > k) {
                char d = s.charAt(left++);
                freq.put(d, freq.get(d) - 1);
                if (freq.get(d) == 0) freq.remove(d);
            }
            max = Math.max(max, right - left + 1);
        }
        return max;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Longest Substring with At Most K Distinct");
        System.out.println("=".repeat(60));

        System.out.println("eceba, k=2 -> " + lengthOfLongestSubstringKDistinct("eceba", 2));
        System.out.println("aa, k=1 -> " + lengthOfLongestSubstringKDistinct("aa", 1));
    }
}
