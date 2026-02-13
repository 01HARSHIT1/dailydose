/**
 * Basic DSA Problems - Reverse String
 * Reverse a character array in-place
 */
public class basic_dsa_two_hundred_thirty_seven {

    // Problem: Reverse the array s in-place. O(1) extra space.
    // Example: ['h','e','l','l','o'] -> ['o','l','l','e','h']

    /**
     * Two pointers: swap from both ends moving toward center.
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
