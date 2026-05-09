/**
 * Basic DSA Problems - One Fundamental String Matching Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_thirty_one {

    // Problem 1: Find the Index of the First Occurrence (strStr)
    // Return starting index of first occurrence of needle in haystack, or -1 if absent.
    // If needle is empty, return 0.

    /**
     * Naive check at each offset — simple; KMP omitted for brevity
     * Time Complexity: O(n * m) worst case
     * Space Complexity: O(1)
     */
    public static Integer strStr(String haystack, String needle) {
        if (haystack == null || needle == null) {
            return null;
        }
        if (needle.isEmpty()) {
            return 0;
        }

        int n = haystack.length();
        int m = needle.length();
        if (m > n) {
            return -1;
        }

        for (int i = 0; i <= n - m; i++) {
            if (haystack.regionMatches(i, needle, 0, m)) {
                return i;
            }
        }

        return -1;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: strStr (first occurrence)");
        System.out.println("=".repeat(60));

        System.out.println("hello, ll -> " + strStr("hello", "ll"));
        System.out.println("aaaa, bba -> " + strStr("aaaa", "bba"));
        System.out.println("abc, \" -> " + strStr("abc", ""));
        System.out.println("sad, sadb -> " + strStr("sadbutsad", "sad"));
        System.out.println("null -> " + strStr(null, "a"));
    }
}
