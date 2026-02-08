/**
 * Basic DSA Problems - Length of Last Word
 * Return length of the last word in a string
 */
public class basic_dsa_one_hundred_thirty_five {

    // Problem: Given string s of words separated by spaces, return length of last word.
    // A word is a maximal substring of non-space characters. Ignore trailing spaces.
    // Example: "Hello World" -> 5, "   fly me   to   the moon  " -> 4

    /**
     * Trim and find last space, or scan from end
     * Time O(n), Space O(1)
     */
    public static int lengthOfLastWord(String s) {
        if (s == null || s.isEmpty()) return 0;
        s = s.trim();
        int lastSpace = s.lastIndexOf(' ');
        return lastSpace == -1 ? s.length() : s.length() - lastSpace - 1;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Length of Last Word");
        System.out.println("=".repeat(60));

        System.out.println("\"Hello World\" -> " + lengthOfLastWord("Hello World"));
        System.out.println("\"   fly me   to   the moon  \" -> " + lengthOfLastWord("   fly me   to   the moon  "));
        System.out.println("\"a\" -> " + lengthOfLastWord("a"));
        System.out.println("\" \" -> " + lengthOfLastWord(" "));
    }
}
