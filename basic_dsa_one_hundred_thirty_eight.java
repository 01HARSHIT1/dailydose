/**
 * Basic DSA Problems - Find the Difference
 * Find the character added to string t that is not in string s
 */
public class basic_dsa_one_hundred_thirty_eight {

    // Problem: String t is string s with one random character added and shuffled.
    // Return the character that was added to t.
    // Example: s="abcd", t="abcde" -> 'e'; s="", t="y" -> 'y'

    /**
     * XOR all chars - duplicates cancel, the added char remains
     * Time O(n), Space O(1)
     */
    public static char findTheDifference(String s, String t) {
        char diff = 0;
        for (int i = 0; i < s.length(); i++) diff ^= s.charAt(i);
        for (int i = 0; i < t.length(); i++) diff ^= t.charAt(i);
        return diff;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Find the Difference");
        System.out.println("=".repeat(60));

        System.out.println("s=\"abcd\", t=\"abcde\" -> '" + findTheDifference("abcd", "abcde") + "'");
        System.out.println("s=\"\", t=\"y\" -> '" + findTheDifference("", "y") + "'");
        System.out.println("s=\"a\", t=\"aa\" -> '" + findTheDifference("a", "aa") + "'");
    }
}
