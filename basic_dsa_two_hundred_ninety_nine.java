/**
 * Basic DSA Problems - Reverse String
 * Reverse a string in-place (character array)
 */
public class basic_dsa_two_hundred_ninety_nine {

    // Problem: Reverse string in-place. Given char array s, modify it.
    // Must use O(1) extra space.

    /**
     * Two-pointer swap from both ends toward center.
     * Time O(n), Space O(1)
     */
    public static void reverseString(char[] s) {
        int i = 0, j = s.length - 1;
        while (i < j) {
            char t = s[i];
            s[i] = s[j];
            s[j] = t;
            i++;
            j--;
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Reverse String");
        System.out.println("=".repeat(60));

        char[] a = "hello".toCharArray();
        reverseString(a);
        System.out.println("hello -> " + new String(a));

        char[] b = "Hannah".toCharArray();
        reverseString(b);
        System.out.println("Hannah -> " + new String(b));
    }
}
