/**
 * Basic DSA Problems - Reverse Vowels of a String (LeetCode 345)
 * Reverse only vowel characters in string, keep rest in place
 */
public class basic_dsa_three_hundred_forty_five {

    // Problem: String s. Reverse only vowels (a,e,i,o,u). Case-insensitive.

    private static boolean isVowel(char c) {
        c = Character.toLowerCase(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    /**
     * Two-pointer: advance to vowels from both ends, swap.
     * Time O(n), Space O(n) for char array
     */
    public static String reverseVowels(String s) {
        char[] a = s.toCharArray();
        int i = 0, j = a.length - 1;
        while (i < j) {
            while (i < j && !isVowel(a[i])) i++;
            while (i < j && !isVowel(a[j])) j--;
            if (i < j) {
                char t = a[i];
                a[i++] = a[j];
                a[j--] = t;
            }
        }
        return new String(a);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Reverse Vowels of a String");
        System.out.println("=".repeat(60));

        System.out.println("hello -> " + reverseVowels("hello"));
        System.out.println("leetcode -> " + reverseVowels("leetcode"));
    }
}
