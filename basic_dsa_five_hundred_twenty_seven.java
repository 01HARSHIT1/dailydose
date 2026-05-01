/**
 * Basic DSA Problems - One Fundamental String Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_twenty_seven {

    // Problem 1: Longest Common Prefix
    // Write a function to find the longest common prefix string amongst an array of strings.
    // If there is no common prefix, return an empty string "".
    //
    // Example:
    // strs = ["flower","flow","flight"] -> "fl"
    // strs = ["dog","racecar","car"] -> ""

    /**
     * Compare character by character with the first string
     * Time Complexity: O(n * m), where n = number of strings, m = prefix length checked
     * Space Complexity: O(1) extra
     */
    public static String longestCommonPrefix(String[] strs) {
        if (strs == null) {
            return null;
        }
        if (strs.length == 0) {
            return "";
        }
        if (strs[0] == null) {
            return null;
        }

        for (int i = 0; i < strs[0].length(); i++) {
            char ch = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if (strs[j] == null || i >= strs[j].length() || strs[j].charAt(i) != ch) {
                    return strs[0].substring(0, i);
                }
            }
        }

        return strs[0];
    }

    private static String arrayToString(String[] arr) {
        if (arr == null) {
            return "null";
        }
        if (arr.length == 0) {
            return "[]";
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < arr.length; i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append(arr[i] == null ? "null" : "\"" + arr[i] + "\"");
        }
        sb.append("]");
        return sb.toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Longest Common Prefix");
        System.out.println("=".repeat(60));

        String[] a1 = {"flower", "flow", "flight"};
        System.out.println("strs = " + arrayToString(a1) + " -> \"" + longestCommonPrefix(a1) + "\"");

        String[] a2 = {"dog", "racecar", "car"};
        System.out.println("strs = " + arrayToString(a2) + " -> \"" + longestCommonPrefix(a2) + "\"");

        String[] a3 = {"interview", "internet", "internal"};
        System.out.println("strs = " + arrayToString(a3) + " -> \"" + longestCommonPrefix(a3) + "\"");

        String[] a4 = {};
        System.out.println("strs = " + arrayToString(a4) + " -> \"" + longestCommonPrefix(a4) + "\"");

        System.out.println("strs = null -> " + longestCommonPrefix(null));
    }
}
