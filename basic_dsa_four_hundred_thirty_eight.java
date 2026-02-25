/**
 * Basic DSA Problems - Find All Anagrams in a String (LeetCode 438)
 * Return start indices where anagrams of p appear in s
 */
public class basic_dsa_four_hundred_thirty_eight {

    // Problem: s, p. Find all starts where substring is anagram of p.

    /**
     * Sliding window size len(p). Compare freq arrays.
     * Time O(m+n), Space O(1)
     */
    public static java.util.List<Integer> findAnagrams(String s, String p) {
        int m = s.length(), n = p.length();
        java.util.List<Integer> ans = new java.util.ArrayList<>();
        if (m < n) return ans;
        int[] cnt1 = new int[26];
        for (int i = 0; i < n; i++) cnt1[p.charAt(i) - 'a']++;
        int[] cnt2 = new int[26];
        for (int i = 0; i < n - 1; i++) cnt2[s.charAt(i) - 'a']++;
        for (int i = n - 1; i < m; i++) {
            cnt2[s.charAt(i) - 'a']++;
            if (java.util.Arrays.equals(cnt1, cnt2)) ans.add(i - n + 1);
            cnt2[s.charAt(i - n + 1) - 'a']--;
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Find All Anagrams in a String");
        System.out.println("=".repeat(60));

        System.out.println("cbaebabacd, abc -> " + findAnagrams("cbaebabacd", "abc"));
        System.out.println("abab, ab -> " + findAnagrams("abab", "ab"));
    }
}
