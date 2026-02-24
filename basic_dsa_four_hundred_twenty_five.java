/**
 * Basic DSA Problems - Word Squares (LeetCode 425)
 * Find all word squares: kth row and kth column read the same
 */
public class basic_dsa_four_hundred_twenty_five {

    // Problem: words. Build squares. Same word can be used multiple times.

    static class Trie {
        Trie[] children = new Trie[26];
        java.util.List<Integer> indices = new java.util.ArrayList<>();

        void insert(String w, int i) {
            Trie node = this;
            for (char c : w.toCharArray()) {
                int idx = c - 'a';
                if (node.children[idx] == null) node.children[idx] = new Trie();
                node = node.children[idx];
                node.indices.add(i);
            }
        }

        java.util.List<Integer> search(String pref) {
            Trie node = this;
            for (char c : pref.toCharArray()) {
                int idx = c - 'a';
                if (node.children[idx] == null) return java.util.Collections.emptyList();
                node = node.children[idx];
            }
            return node.indices;
        }
    }

    /**
     * Trie + backtracking. Next row prefix = column from placed rows.
     * Time O(n * len * n^len), Space O(n * len)
     */
    public static java.util.List<java.util.List<String>> wordSquares(String[] words) {
        Trie trie = new Trie();
        for (int i = 0; i < words.length; i++) trie.insert(words[i], i);
        java.util.List<java.util.List<String>> ans = new java.util.ArrayList<>();
        java.util.List<String> cur = new java.util.ArrayList<>();
        for (String w : words) {
            cur.add(w);
            dfs(words, trie, cur, ans);
            cur.remove(cur.size() - 1);
        }
        return ans;
    }

    private static void dfs(String[] words, Trie trie, java.util.List<String> cur,
                           java.util.List<java.util.List<String>> ans) {
        if (cur.size() == words[0].length()) {
            ans.add(new java.util.ArrayList<>(cur));
            return;
        }
        int idx = cur.size();
        StringBuilder pref = new StringBuilder();
        for (String s : cur) pref.append(s.charAt(idx));
        for (int i : trie.search(pref.toString())) {
            cur.add(words[i]);
            dfs(words, trie, cur, ans);
            cur.remove(cur.size() - 1);
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Word Squares");
        System.out.println("=".repeat(60));

        String[] w1 = {"area","lead","wall","lady","ball"};
        System.out.println("[\"area\",\"lead\",\"wall\",\"lady\",\"ball\"] -> " + wordSquares(w1));

        String[] w2 = {"abat","baba","atan","atal"};
        System.out.println("[\"abat\",\"baba\",\"atan\",\"atal\"] -> " + wordSquares(w2));
    }
}
