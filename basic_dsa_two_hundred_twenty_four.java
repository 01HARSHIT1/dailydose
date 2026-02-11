/**
 * Basic DSA Problems - Implement strStr() / Find Index of First Occurrence
 * Return index of first occurrence of needle in haystack, or -1
 */
public class basic_dsa_two_hundred_twenty_four {

    // Problem: haystack and needle. Return start index of first occurrence of needle, -1 if not found.

    /**
     * Sliding window: check each starting index. Could use KMP for O(n+m).
     * Time O(n*m) naive, Space O(1)
     */
    public static int strStr(String haystack, String needle) {
        if (needle.isEmpty()) return 0;
        int n = haystack.length(), m = needle.length();
        if (m > n) return -1;
        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack.charAt(i + j) == needle.charAt(j)) j++;
            if (j == m) return i;
        }
        return -1;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Find Index of First Occurrence (strStr)");
        System.out.println("=".repeat(60));

        System.out.println("sadbutsad, sad -> " + strStr("sadbutsad", "sad"));
        System.out.println("leetcode, leeto -> " + strStr("leetcode", "leeto"));
    }
}
