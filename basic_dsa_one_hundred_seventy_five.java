/**
 * Basic DSA Problems - Word Search II
 * Find all words from a list that exist on the board (adjacent cells)
 */
import java.util.*;

public class basic_dsa_one_hundred_seventy_five {

    // Problem: 2D board of chars, list of words. Return all words that can be formed by adjacent cells.

    static List<String> out;
    static int rows, cols;
    static char[][] board;
    static TrieNode root;

    static class TrieNode {
        TrieNode[] next = new TrieNode[26];
        String word;
    }

    public static List<String> findWords(char[][] b, String[] words) {
        board = b;
        rows = board.length;
        cols = board[0].length;
        root = new TrieNode();
        for (String w : words) {
            TrieNode cur = root;
            for (char c : w.toCharArray()) {
                int i = c - 'a';
                if (cur.next[i] == null) cur.next[i] = new TrieNode();
                cur = cur.next[i];
            }
            cur.word = w;
        }
        out = new ArrayList<>();
        for (int r = 0; r < rows; r++)
            for (int c = 0; c < cols; c++)
                dfs(r, c, root);
        return out;
    }

    static void dfs(int r, int c, TrieNode node) {
        if (r < 0 || r >= rows || c < 0 || c >= cols) return;
        char ch = board[r][c];
        if (ch == '#' || node.next[ch - 'a'] == null) return;
        node = node.next[ch - 'a'];
        if (node.word != null) {
            out.add(node.word);
            node.word = null;
        }
        board[r][c] = '#';
        dfs(r - 1, c, node);
        dfs(r + 1, c, node);
        dfs(r, c - 1, node);
        dfs(r, c + 1, node);
        board[r][c] = ch;
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Word Search II");
        System.out.println("=".repeat(60));

        char[][] board = {{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
        String[] words = {"oath", "pea", "eat", "rain"};
        System.out.println("findWords -> " + findWords(board, words));
    }
}
