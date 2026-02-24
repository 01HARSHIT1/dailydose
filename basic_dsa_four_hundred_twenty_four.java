/**
 * Basic DSA Problems - Longest Repeating Character Replacement (LeetCode 424)
 * At most k replacements -> longest substring of same letter
 */
public class basic_dsa_four_hundred_twenty_four {

    // Problem: s, k. Replace at most k chars. Max len of repeating substring.

    /**
     * Sliding window: valid when windowLen - maxFreq <= k.
     * Time O(n), Space O(1)
     */
    public static int characterReplacement(String s, int k) {
        int[] cnt = new int[26];
        int j = 0, maxCnt = 0;
        for (int i = 0; i < s.length(); i++) {
            int c = s.charAt(i) - 'A';
            cnt[c]++;
            if (cnt[c] > maxCnt) maxCnt = cnt[c];
            if (i - j + 1 - maxCnt > k) {
                cnt[s.charAt(j) - 'A']--;
                j++;
            }
        }
        return s.length() - j;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Longest Repeating Character Replacement");
        System.out.println("=".repeat(60));

        System.out.println("\"ABAB\", 2 -> " + characterReplacement("ABAB", 2));
        System.out.println("\"AABABBA\", 1 -> " + characterReplacement("AABABBA", 1));
        System.out.println("\"AABABBA\", 2 -> " + characterReplacement("AABABBA", 2));
    }
}
