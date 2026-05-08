/**
 * Basic DSA Problems - One Fundamental String Scan Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_six_hundred_twenty_four {

    // Problem 1: Longest Common Prefix
    // Among all strings in strs, return the longest prefix shared by every string.

    /**
     * Column-wise compare character c across all strings; stop on mismatch or short string
     * Time Complexity: O(S) where S is sum of all characters
     * Space Complexity: O(1) besides output substring
     */
    public static String longestCommonPrefix(String[] strs) {
        if (strs == null) {
            return null;
        }
        if (strs.length == 0) {
            return "";
        }

        String first = strs[0];
        for (int col = 0; col < first.length(); col++) {
            char ch = first.charAt(col);
            for (int i = 1; i < strs.length; i++) {
                if (col >= strs[i].length() || strs[i].charAt(col) != ch) {
                    return first.substring(0, col);
                }
            }
        }
        return first;
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Longest Common Prefix");
        System.out.println("=".repeat(60));

        String[] a = {"flower", "flow", "flight"};
        System.out.println("sample -> \"" + longestCommonPrefix(a) + "\"");

        String[] b = {"dog", "racecar", "car"};
        System.out.println("no common -> \"" + longestCommonPrefix(b) + "\"");

        String[] c = {"alone"};
        System.out.println("single -> \"" + longestCommonPrefix(c) + "\"");

        System.out.println("empty arr -> \"" + longestCommonPrefix(new String[0]) + "\"");
        System.out.println("null -> " + longestCommonPrefix(null));
    }
}
