/**
 * Basic DSA Problems - Reverse Words in a String III
 * Reverse each word in a string while preserving word order
 */
public class basic_dsa_three_hundred {

    // Problem: Given string s, reverse the order of characters in each word.
    // A word is a sequence of non-space characters. Words separated by single space.

    /**
     * Two-pointer reverse per word. Split by space or track word boundaries.
     * Time O(n), Space O(n) for result
     */
    public static String reverseWords(String s) {
        char[] a = s.toCharArray();
        int n = a.length;
        int i = 0;
        while (i < n) {
            if (a[i] != ' ') {
                int j = i;
                while (j < n && a[j] != ' ') j++;
                reverse(a, i, j - 1);
                i = j;
            } else {
                i++;
            }
        }
        return new String(a);
    }

    private static void reverse(char[] a, int lo, int hi) {
        while (lo < hi) {
            char t = a[lo];
            a[lo] = a[hi];
            a[hi] = t;
            lo++;
            hi--;
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Reverse Words in a String III");
        System.out.println("=".repeat(60));

        System.out.println("Let's take LeetCode contest -> " + reverseWords("Let's take LeetCode contest"));
        System.out.println("Mr Ding -> " + reverseWords("Mr Ding"));
    }
}
