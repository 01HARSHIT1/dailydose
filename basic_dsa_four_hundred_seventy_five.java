/**
 * Basic DSA Problems - One Fundamental String Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_four_hundred_seventy_five {

    // Problem 1: Longest Common Prefix
    // Write a function to find the longest common prefix string amongst an array of strings.
    // If there is no common prefix, return an empty string.
    //
    // Example:
    // strs = ["flower","flow","flight"] -> "fl"
    // strs = ["dog","racecar","car"] -> ""

    /**
     * Compare character by character across all strings
     * Time Complexity: O(S) where S is sum of all characters
     * Space Complexity: O(1) excluding the output substring
     */
    public static String longestCommonPrefix(String[] strs) {
        if (strs == null) {
            return null;
        }
        if (strs.length == 0) {
            return "";
        }

        String first = strs[0];
        for (int i = 0; i < first.length(); i++) {
            char c = first.charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if (i >= strs[j].length() || strs[j].charAt(i) != c) {
                    return first.substring(0, i);
                }
            }
        }

        return first;
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
            sb.append("\"").append(arr[i]).append("\"");
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
        System.out.println("strs: " + arrayToString(a1));
        System.out.println("LCP: \"" + longestCommonPrefix(a1) + "\"");

        String[] a2 = {"dog", "racecar", "car"};
        System.out.println("\nstrs: " + arrayToString(a2));
        System.out.println("LCP: \"" + longestCommonPrefix(a2) + "\"");

        String[] a3 = {"interspecies", "interstellar", "interstate"};
        System.out.println("\nstrs: " + arrayToString(a3));
        System.out.println("LCP: \"" + longestCommonPrefix(a3) + "\"");

        String[] a4 = {"alone"};
        System.out.println("\nstrs: " + arrayToString(a4));
        System.out.println("LCP: \"" + longestCommonPrefix(a4) + "\"");

        String[] a5 = {};
        System.out.println("\nstrs: " + arrayToString(a5));
        System.out.println("LCP: \"" + longestCommonPrefix(a5) + "\"");

        System.out.println("\nstrs: null");
        System.out.println("LCP: " + longestCommonPrefix(null));
    }
}
