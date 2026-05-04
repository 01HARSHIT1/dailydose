/**
 * Basic DSA Problems - One Fundamental String Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_sixty {

    // Problem 1: Detect Capital
    // We define the usage of capitals in a word to be right when one of the following holds:
    // 1) All letters are capitals, like "USA"
    // 2) All letters are not capitals, like "leetcode"
    // 3) Only the first letter is capital, like "Google"
    //
    // Return true if the capitalization in the given word is correct.

    /**
     * Count uppercase letters and validate allowed patterns
     * Time Complexity: O(n)
     * Space Complexity: O(1)
     */
    public static Boolean detectCapitalUse(String word) {
        if (word == null || word.length() == 0) {
            return null;
        }

        int upper = 0;
        for (int i = 0; i < word.length(); i++) {
            if (Character.isUpperCase(word.charAt(i))) {
                upper++;
            }
        }

        return upper == word.length()
                || upper == 0
                || (upper == 1 && Character.isUpperCase(word.charAt(0)));
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Detect Capital");
        System.out.println("=".repeat(60));

        System.out.println("word = \"USA\" -> " + detectCapitalUse("USA"));
        System.out.println("word = \"leetcode\" -> " + detectCapitalUse("leetcode"));
        System.out.println("word = \"Google\" -> " + detectCapitalUse("Google"));
        System.out.println("word = \"FlaG\" -> " + detectCapitalUse("FlaG"));
        System.out.println("word = null -> " + detectCapitalUse(null));
    }
}
