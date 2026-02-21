/**
 * Basic DSA Problems - Lexicographical Numbers (LeetCode 386)
 * Return [1..n] sorted lexicographically (as strings)
 */
public class basic_dsa_three_hundred_eighty_six {

    // Problem: n. Return [1..n] in lexicographic order.

    /**
     * DFS on digit trie: try 0-9, skip 0 at root. Prune when cur > n.
     * Time O(n), Space O(log n)
     */
    public static java.util.List<Integer> lexicalOrder(int n) {
        java.util.List<Integer> out = new java.util.ArrayList<>();
        for (int d = 1; d <= 9; d++) dfs(d, n, out);
        return out;
    }

    private static void dfs(int cur, int n, java.util.List<Integer> out) {
        if (cur > n) return;
        out.add(cur);
        for (int d = 0; d <= 9; d++) dfs(cur * 10 + d, n, out);
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Lexicographical Numbers");
        System.out.println("=".repeat(60));

        System.out.println("n=13 -> " + lexicalOrder(13));
        System.out.println("n=2 -> " + lexicalOrder(2));
    }
}
