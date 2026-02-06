/**
 * Basic DSA Problems - Assign Cookies
 * Greedy: assign cookies to children (each child one cookie, size >= greed)
 */
import java.util.Arrays;

public class basic_dsa_one_hundred_twenty_six {

    // Problem: g[i] = greed of child i, s[j] = size of cookie j. Each child at most one cookie.
    // Cookie j can satisfy child i only if s[j] >= g[i]. Return max number of content children.

    /**
     * Sort both arrays. Two pointers: assign smallest cookie that satisfies current child.
     * Time O(n log n), Space O(1) excluding sort
     */
    public static int findContentChildren(int[] g, int[] s) {
        if (g == null || s == null) return 0;
        Arrays.sort(g);
        Arrays.sort(s);
        int i = 0, j = 0;
        while (i < g.length && j < s.length) {
            if (s[j] >= g[i]) i++;
            j++;
        }
        return i;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Assign Cookies");
        System.out.println("=".repeat(60));

        System.out.println("g=[1,2,3], s=[1,1] -> " + findContentChildren(new int[] { 1, 2, 3 }, new int[] { 1, 1 }));
        System.out.println("g=[1,2], s=[1,2,3] -> " + findContentChildren(new int[] { 1, 2 }, new int[] { 1, 2, 3 }));
    }
}
