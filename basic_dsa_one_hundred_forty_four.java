/**
 * Basic DSA Problems - Reverse Vowels of a String
 * Reverse only the vowels in a string
 */
public class basic_dsa_one_hundred_forty_four {

    // Problem: Reverse only the vowels (a,e,i,o,u - case insensitive) in string s.
    // Example: "hello" -> "holle", "leetcode" -> "leotcede"

    private static final String VOWELS = "aeiouAEIOU";

    private static boolean isVowel(char c) {
        return VOWELS.indexOf(c) >= 0;
    }

    /**
     * Two pointers from both ends, swap when both point to vowels
     * Time O(n), Space O(n) for char array
     */
    public static String reverseVowels(String s) {
        if (s == null || s.isEmpty()) return s;
        char[] arr = s.toCharArray();
        int i = 0, j = arr.length - 1;
        while (i < j) {
            while (i < j && !isVowel(arr[i])) i++;
            while (i < j && !isVowel(arr[j])) j--;
            if (i < j) {
                char t = arr[i];
                arr[i] = arr[j];
                arr[j] = t;
                i++;
                j--;
            }
        }
        return new String(arr);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Reverse Vowels of a String");
        System.out.println("=".repeat(60));

        System.out.println("hello -> " + reverseVowels("hello"));
        System.out.println("leetcode -> " + reverseVowels("leetcode"));
        System.out.println("aA -> " + reverseVowels("aA"));
        System.out.println("bcdfg -> " + reverseVowels("bcdfg"));
    }
}
