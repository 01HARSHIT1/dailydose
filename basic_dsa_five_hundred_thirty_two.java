/**
 * Basic DSA Problems - One Fundamental Sorting + Greedy Question
 * Simple and essential DSA problem for beginners
 */
public class basic_dsa_five_hundred_thirty_two {

    // Problem 1: Assign Cookies
    // Assume you are an awesome parent and want to give your children cookies.
    // Each child i has a greed factor g[i], and each cookie j has a size s[j].
    // If s[j] >= g[i], child i can be content.
    //
    // Maximize the number of content children.
    //
    // Example:
    // g = [1,2,3], s = [1,1] -> 1

    /**
     * Sort both arrays and greedily match smallest possible cookie
     * Time Complexity: O(n log n + m log m)
     * Space Complexity: O(1) extra (ignoring sorting internals)
     */
    public static Integer findContentChildren(int[] g, int[] s) {
        if (g == null || s == null) {
            return null;
        }

        java.util.Arrays.sort(g);
        java.util.Arrays.sort(s);

        int child = 0;
        int cookie = 0;

        while (child < g.length && cookie < s.length) {
            if (s[cookie] >= g[child]) {
                child++;
            }
            cookie++;
        }

        return child;
    }

    private static String arrayToString(int[] arr) {
        if (arr == null) {
            return "null";
        }
        if (arr.length == 0) {
            return "[]";
        }
        StringBuilder sb = new StringBuilder();
        sb.append("[");
        for (int i = 0; i < arr.length; i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append(arr[i]);
        }
        sb.append("]");
        return sb.toString();
    }

    // Test cases
    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem 1: Assign Cookies");
        System.out.println("=".repeat(60));

        int[] g1 = {1, 2, 3};
        int[] s1 = {1, 1};
        System.out.println("g = " + arrayToString(g1) + ", s = " + arrayToString(s1)
                + " -> " + findContentChildren(g1, s1));

        int[] g2 = {1, 2};
        int[] s2 = {1, 2, 3};
        System.out.println("g = " + arrayToString(g2) + ", s = " + arrayToString(s2)
                + " -> " + findContentChildren(g2, s2));

        int[] g3 = {};
        int[] s3 = {1, 2};
        System.out.println("g = " + arrayToString(g3) + ", s = " + arrayToString(s3)
                + " -> " + findContentChildren(g3, s3));

        System.out.println("g = null, s = [1] -> " + findContentChildren(null, new int[]{1}));
    }
}
