/**
 * Basic DSA Problems - One Fundamental String Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_fifty_six {

    // Problem 1: Reverse Vowels of a String
    // Given a string s, reverse only all the vowels in the string and return it.
    //
    // Example:
    // s = "hello" -> "holle"
    // s = "leetcode" -> "leotcede"

    /**
     * Two-pointer vowel swapping
     * Time Complexity: O(n)
     * Space Complexity: O(n) because Java strings are immutable
     */
    public static String reverseVowels(String s) {
        if (s == null) {
            return null;
        }

        char[] chars = s.toCharArray();
        int left = 0;
        int right = chars.length - 1;

        while (left < right) {
            while (left < right && !isVowel(chars[left])) {
                left++;
            }
            while (left < right && !isVowel(chars[right])) {
                right--;
            }
            if (left < right) {
                char temp = chars[left];
                chars[left] = chars[right];
                chars[right] = temp;
                left++;
                right--;
            }
        }

        return new String(chars);
    }

    private static boolean isVowel(char c) {
        char ch = Character.toLowerCase(c);
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Reverse Vowels of a String");
        System.out.println("=".repeat(60));

        System.out.println("s = \"hello\" -> " + reverseVowels("hello"));
        System.out.println("s = \"leetcode\" -> " + reverseVowels("leetcode"));
        System.out.println("s = \"aA\" -> " + reverseVowels("aA"));
        System.out.println("s = \"bcdf\" -> " + reverseVowels("bcdf"));
        System.out.println("s = null -> " + reverseVowels(null));
    }
}
