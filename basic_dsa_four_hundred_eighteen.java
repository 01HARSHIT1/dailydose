/**
 * Basic DSA Problems - Sentence Screen Fitting (LeetCode 418)
 * How many times the sentence can be fitted on a rows x cols screen
 */
public class basic_dsa_four_hundred_eighteen {

    // Problem: Words cannot split. Order unchanged. Spaces between words.

    /**
     * Join words with spaces. For each row add cols; if mid-word, backtrack.
     * Time O(rows + total chars), Space O(total chars)
     */
    public static int wordsTyping(String[] sentence, int rows, int cols) {
        String s = String.join(" ", sentence) + " ";
        int len = s.length(), pos = 0;
        for (int r = 0; r < rows; r++) {
            pos += cols;
            if (s.charAt(pos % len) == ' ') pos++;
            else while (pos > 0 && s.charAt((pos - 1) % len) != ' ') pos--;
        }
        return pos / len;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Sentence Screen Fitting");
        System.out.println("=".repeat(60));

        System.out.println("[\"hello\",\"world\"], 2, 8 -> " + wordsTyping(new String[]{"hello","world"}, 2, 8));
        System.out.println("[\"a\",\"bcd\",\"e\"], 3, 6 -> " + wordsTyping(new String[]{"a","bcd","e"}, 3, 6));
        System.out.println("[\"i\",\"had\",\"apple\",\"pie\"], 4, 5 -> " + wordsTyping(new String[]{"i","had","apple","pie"}, 4, 5));
    }
}
