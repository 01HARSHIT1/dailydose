/**
 * Basic DSA Problems - Reverse String (LeetCode 344)
 * Reverse char array in-place with O(1) space
 */
public class basic_dsa_three_hundred_forty_four {

    // Problem: Char array s. Reverse in-place. O(1) extra memory.

    /**
     * Two-pointer swap from both ends.
     * Time O(n), Space O(1)
     */
    public static void reverseString(char[] s) {
        int i = 0, j = s.length - 1;
        while (i < j) {
            char t = s[i];
            s[i++] = s[j];
            s[j--] = t;
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
