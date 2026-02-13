/**
 * Basic DSA Problems - Detect Capital
 * Check if word has correct capital usage
 */
public class basic_dsa_two_hundred_fifty_six {

    // Problem: Valid: all caps "USA", first cap "Google", all lowercase "leetcode".
    // Invalid: "FlaG", "aBc". Return true if valid.

    /**
     * Count uppercase letters. Valid: count==0, count==len, or (count==1 and first is upper).
     * Time O(n), Space O(1)
     */
    public static boolean detectCapitalUse(String word) {
        int upper = 0;
        for (char c : word.toCharArray())
            if (Character.isUpperCase(c)) upper++;
        return upper == 0 || upper == word.length() || (upper == 1 && Character.isUpperCase(word.charAt(0)));
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Detect Capital");
        System.out.println("=".repeat(60));

        System.out.println("USA -> " + detectCapitalUse("USA"));
        System.out.println("FlaG -> " + detectCapitalUse("FlaG"));
        System.out.println("Google -> " + detectCapitalUse("Google"));
        System.out.println("leetcode -> " + detectCapitalUse("leetcode"));
    }
}
