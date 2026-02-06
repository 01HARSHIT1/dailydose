/**
 * Basic DSA Problems - Reverse Words in a String
 * Reverse the order of words (words are space-separated, trim extra spaces)
 */
public class basic_dsa_one_hundred_nine {

    // Problem: Given a string s, reverse the order of words. A word is a sequence of
    // non-space characters. Return string with single spaces between words, no leading/trailing spaces.

    /**
     * Split on one or more spaces, reverse the array of words, join with single space.
     * Time O(n), Space O(n)
     */
    public static String reverseWords(String s) {
        if (s == null) return "";
        String[] words = s.trim().split("\\s+");
        StringBuilder sb = new StringBuilder();
        for (int i = words.length - 1; i >= 0; i--) {
            sb.append(words[i]);
            if (i > 0) sb.append(" ");
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Reverse Words in a String");
        System.out.println("=".repeat(60));

        System.out.println("\"the sky is blue\" -> \"" + reverseWords("the sky is blue") + "\"");
        System.out.println("\"  hello world  \" -> \"" + reverseWords("  hello world  ") + "\"");
        System.out.println("\"a good   example\" -> \"" + reverseWords("a good   example") + "\"");
    }
}
