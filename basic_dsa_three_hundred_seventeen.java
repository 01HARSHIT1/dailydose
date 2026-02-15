/**
 * Basic DSA Problems - Reverse Words in a String III
 * Reverse each word in a string
 */
public class basic_dsa_three_hundred_seventeen {

    // Problem: String s with words separated by spaces. Reverse each word in-place.

    /**
     * Two pointers: find word boundaries, reverse each word.
     * Time O(n), Space O(n) for char array
     */
    public static String reverseWords(String s) {
        char[] a = s.toCharArray();
        int i = 0;
        while (i < a.length) {
            int j = i;
            while (j < a.length && a[j] != ' ') j++;
            for (int lo = i, hi = j - 1; lo < hi; lo++, hi--) {
                char t = a[lo];
                a[lo] = a[hi];
                a[hi] = t;
            }
            i = j + 1;
        }
        return new String(a);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Reverse Words in a String III");
        System.out.println("=".repeat(60));

        System.out.println("\"Let's take LeetCode contest\" -> " + reverseWords("Let's take LeetCode contest"));
        System.out.println("\"God Ding\" -> " + reverseWords("God Ding"));
    }
}
