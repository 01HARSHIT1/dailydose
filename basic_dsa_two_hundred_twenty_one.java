/**
 * Basic DSA Problems - Longest Common Prefix
 * Find longest common prefix string amongst array of strings
 */
public class basic_dsa_two_hundred_twenty_one {

    // Problem: Array of strings. Return longest common prefix. "" if none.

    /**
     * Use first string as base. For each position, check all others; stop on mismatch.
     * Time O(S) total chars, Space O(1)
     */
    public static String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) return "";
        String base = strs[0];
        for (int i = 0; i < base.length(); i++) {
            char c = base.charAt(i);
            for (int j = 1; j < strs.length; j++)
                if (i >= strs[j].length() || strs[j].charAt(i) != c)
                    return base.substring(0, i);
        }
        return base;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Longest Common Prefix");
        System.out.println("=".repeat(60));

        System.out.println("[flower,flow,flight] -> \"" + longestCommonPrefix(new String[]{"flower", "flow", "flight"}) + "\"");
        System.out.println("[dog,racecar,car] -> \"" + longestCommonPrefix(new String[]{"dog", "racecar", "car"}) + "\"");
    }
}
