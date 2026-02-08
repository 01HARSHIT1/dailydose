/**
 * Basic DSA Problems - Detect Capital
 * Check if word uses capitals correctly
 */
public class basic_dsa_one_hundred_forty_nine {

    // Problem: A word uses capitals correctly if: all caps (USA), all lowercase (leetcode),
    // or only first letter capitalized (Google). Return true if correct.
    // Example: "USA" -> true, "FlaG" -> false

    /**
     * Count uppercase letters, then check against rules
     * Time O(n), Space O(1)
     */
    public static boolean detectCapitalUse(String word) {
        if (word == null || word.isEmpty()) return true;
        int upper = 0;
        for (char c : word.toCharArray()) {
            if (Character.isUpperCase(c)) upper++;
        }
        return upper == 0 || upper == word.length() || (upper == 1 && Character.isUpperCase(word.charAt(0)));
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Detect Capital");
        System.out.println("=".repeat(60));

        System.out.println("\"USA\" -> " + detectCapitalUse("USA"));
        System.out.println("\"leetcode\" -> " + detectCapitalUse("leetcode"));
        System.out.println("\"Google\" -> " + detectCapitalUse("Google"));
        System.out.println("\"FlaG\" -> " + detectCapitalUse("FlaG"));
    }
}
