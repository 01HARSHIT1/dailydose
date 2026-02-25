/**
 * Basic DSA Problems - String Compression (LeetCode 443)
 * In-place: replace consecutive duplicates with char + count (count>1 only)
 */
public class basic_dsa_four_hundred_forty_three {

    // Problem: ["a","a","b","b","c","c","c"] -> ["a","2","b","2","c","3"], return 6

    /**
     * Two pointers: count consecutive same, write char + count (if >1).
     * Time O(n), Space O(1)
     */
    public static int compress(char[] chars) {
        int n = chars.length, w = 0;
        for (int r = 0; r < n; ) {
            char c = chars[r];
            int cnt = 0;
            while (r < n && chars[r] == c) { r++; cnt++; }
            chars[w++] = c;
            if (cnt > 1)
                for (char d : String.valueOf(cnt).toCharArray()) chars[w++] = d;
        }
        return w;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: String Compression");
        System.out.println("=".repeat(60));

        char[] c1 = {'a','a','b','b','c','c','c'};
        int len1 = compress(c1);
        System.out.println("aabbccc -> " + len1 + ", " + java.util.Arrays.toString(java.util.Arrays.copyOf(c1, len1)));

        char[] c2 = {'a'};
        System.out.println("a -> " + compress(c2));

        char[] c3 = {'a','b','b','b','b','b','b','b','b','b','b','b','b'};
        int len3 = compress(c3);
        System.out.println("a+12b -> " + len3 + ", " + java.util.Arrays.toString(java.util.Arrays.copyOf(c3, len3)));
    }
}
