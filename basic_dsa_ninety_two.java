/**
 * Basic DSA Problems - Reverse Words in a String III
 * Simple and essential DSA problems for beginners
 */
public class basic_dsa_ninety_two {

    // Problem: Reverse the order of characters in each word within a sentence (words separated by spaces).
    // Example: "Let's take LeetCode contest" -> "s'teL ekat edoCteeL tsetnoc"

    /**
     * Split by space, reverse each word, join.
     * Time O(n), Space O(n)
     */
    public static String reverseWords(String s) {
        if (s == null) return null;
        String[] words = s.split(" ");
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length; i++) {
            if (i > 0) sb.append(" ");
            sb.append(reverse(words[i]));
        }
        return sb.toString();
    }

    private static String reverse(String w) {
        char[] a = w.toCharArray();
        int i = 0, j = a.length - 1;
        while (i < j) {
            char t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
        return new String(a);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Reverse Words in a String III");
        System.out.println("=".repeat(60));

        System.out.println("Let's take LeetCode contest -> " + reverseWords("Let's take LeetCode contest"));
    }
}
