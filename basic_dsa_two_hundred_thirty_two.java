/**
 * Basic DSA Problems - Find the Difference
 * Find the letter added to string t (t is s shuffled + one extra letter)
 */
public class basic_dsa_two_hundred_thirty_two {

    // Problem: s and t; t = random shuffle of s + one extra letter. Return the added letter.

    /**
     * XOR all chars in s and t; result is the extra char. Or sum diff.
     * Time O(n), Space O(1)
     */
    public static char findTheDifference(String s, String t) {
        char x = 0;
        for (int i = 0; i < s.length(); i++) x ^= s.charAt(i);
        for (int i = 0; i < t.length(); i++) x ^= t.charAt(i);
        return x;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Find the Difference");
        System.out.println("=".repeat(60));

        System.out.println("abcd, abcde -> " + findTheDifference("abcd", "abcde"));
        System.out.println(", y -> " + findTheDifference("", "y"));
    }
}
