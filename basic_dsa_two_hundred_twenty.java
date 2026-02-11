/**
 * Basic DSA Problems - Length of Last Word
 * Return length of last word in string (words separated by spaces)
 */
public class basic_dsa_two_hundred_twenty {

    // Problem: String s. Return length of last word. Word = non-space chars.

    /**
     * Trim and find last space; length from there to end. Or traverse from end.
     * Time O(n), Space O(1)
     */
    public static int lengthOfLastWord(String s) {
        s = s.trim();
        int lastSpace = s.lastIndexOf(' ');
        return lastSpace == -1 ? s.length() : s.length() - lastSpace - 1;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Length of Last Word");
        System.out.println("=".repeat(60));

        System.out.println("Hello World -> " + lengthOfLastWord("Hello World"));
        System.out.println("   fly me   to   the moon  -> " + lengthOfLastWord("   fly me   to   the moon  "));
        System.out.println("luffy is still joyboy -> " + lengthOfLastWord("luffy is still joyboy"));
    }
}
