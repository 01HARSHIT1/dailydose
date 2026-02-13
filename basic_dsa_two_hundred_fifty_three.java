/**
 * Basic DSA Problems - String Compression
 * Compress string in-place: "aaabbc" -> "a3b2c1" (or a3b2c if groups of 1 stay as char)
 */
public class basic_dsa_two_hundred_fifty_three {

    // Problem: Modify chars in-place. Group consecutive same chars, append char + count if count>1.
    // Return new length. Example: ['a','a','b','b','c'] -> ['a','2','b','2','c'] length 5.

    /**
     * Two pointers: read and write. Count consecutive same chars, write char and count (if > 1).
     * Time O(n), Space O(1)
     */
    public static int compress(char[] chars) {
        int w = 0, r = 0;
        while (r < chars.length) {
            char c = chars[r];
            int count = 0;
            while (r < chars.length && chars[r] == c) {
                r++;
                count++;
            }
            chars[w++] = c;
            if (count > 1)
                for (char d : String.valueOf(count).toCharArray()) chars[w++] = d;
        }
        return w;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: String Compression");
        System.out.println("=".repeat(60));

        char[] a = {'a', 'a', 'b', 'b', 'c'};
        int len = compress(a);
        System.out.println("aabbc -> length " + len + ", " + java.util.Arrays.toString(java.util.Arrays.copyOf(a, len)));

        char[] b = {'a'};
        System.out.println("a -> length " + compress(b));
    }
}
