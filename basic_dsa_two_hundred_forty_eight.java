/**
 * Basic DSA Problems - Assign Cookies
 * Distribute cookies to greedy children maximally
 */
public class basic_dsa_two_hundred_forty_eight {

    // Problem: g = child greed factors, s = cookie sizes. Each child gets at most one cookie.
    // Cookie can satisfy child if size >= greed. Return max children satisfied.

    /**
     * Sort both, use two pointers to match smallest cookie to smallest greed.
     * Time O(g log g + s log s), Space O(1)
     */
    public static int findContentChildren(int[] g, int[] s) {
        java.util.Arrays.sort(g);
        java.util.Arrays.sort(s);
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

        System.out.println("g=[1,2,3], s=[1,1] -> " + findContentChildren(new int[]{1, 2, 3}, new int[]{1, 1}));
        System.out.println("g=[1,2], s=[1,2,3] -> " + findContentChildren(new int[]{1, 2}, new int[]{1, 2, 3}));
    }
}
