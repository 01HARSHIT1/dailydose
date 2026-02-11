/**
 * Basic DSA Problems - Reverse Words in a String
 * Reverse the order of words (words are non-space chars separated by spaces)
 */
public class basic_dsa_two_hundred_seventeen {

    // Problem: String s with words separated by spaces. Return string with words in reverse order.

    /**
     * Split on one or more spaces, reverse the array of words, join with space.
     * Time O(n), Space O(n)
     */
    public static String reverseWords(String s) {
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

        System.out.println("the sky is blue -> \"" + reverseWords("the sky is blue") + "\"");
        System.out.println("  hello world  -> \"" + reverseWords("  hello world  ") + "\"");
    }
}
