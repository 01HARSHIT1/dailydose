/**
 * Basic DSA Problems - Reverse String
 * Reverse a string in-place
 */
public class basic_dsa_three_hundred_sixteen {

    // Problem: Char array s. Reverse it in-place.

    /**
     * Two pointers: swap chars from both ends toward center.
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

        char[] a = {'h', 'e', 'l', 'l', 'o'};
        reverseString(a);
        System.out.println("hello -> " + new String(a));

        char[] b = {'H', 'a', 'n', 'n', 'a', 'h'};
        reverseString(b);
        System.out.println("Hannah -> " + new String(b));
    }
}
