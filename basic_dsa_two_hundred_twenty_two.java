/**
 * Basic DSA Problems - Reverse String (in place)
 * Reverse array of characters in O(1) extra space
 */
public class basic_dsa_two_hundred_twenty_two {

    // Problem: char[] s. Reverse in place.

    /**
     * Two pointers: swap s[i] with s[n-1-i] for i from 0 to mid.
     * Time O(n), Space O(1)
     */
    public static void reverseString(char[] s) {
        int left = 0, right = s.length - 1;
        while (left < right) {
            char t = s[left];
            s[left] = s[right];
            s[right] = t;
            left++;
            right--;
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Reverse String");
        System.out.println("=".repeat(60));

        char[] s = "hello".toCharArray();
        reverseString(s);
        System.out.println("hello -> " + new String(s));

        char[] s2 = "Hannah".toCharArray();
        reverseString(s2);
        System.out.println("Hannah -> " + new String(s2));
    }
}
