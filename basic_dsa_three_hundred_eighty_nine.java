/**
 * Basic DSA Problems - Find the Difference (LeetCode 389)
 * t = shuffled s + one extra char. Return the added char.
 */
public class basic_dsa_three_hundred_eighty_nine {

    // Problem: t is s shuffled with one extra letter. Return that letter.

    /**
     * XOR all chars in s and t; result is the extra char.
     * Time O(n), Space O(1)
     */
    public static char findTheDifference(String s, String t) {
        char xor = 0;
        for (char c : s.toCharArray()) xor ^= c;
        for (char c : t.toCharArray()) xor ^= c;
        return xor;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Find the Difference");
        System.out.println("=".repeat(60));

        System.out.println("abcd, abcde -> " + findTheDifference("abcd", "abcde"));
        System.out.println(", y -> " + findTheDifference("", "y"));
    }
}
