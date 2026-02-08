/**
 * Basic DSA Problems - Implement Trie (Prefix Tree)
 * Insert, search, and startsWith for strings
 */
public class basic_dsa_one_hundred_seventy_three {

    // Problem: Implement Trie with insert(word), search(word), startsWith(prefix). All lowercase letters.

    public static class Trie {
        Trie[] next = new Trie[26];
        boolean end;

        public void insert(String word) {
            Trie cur = this;
            for (int i = 0; i < word.length(); i++) {
                int c = word.charAt(i) - 'a';
                if (cur.next[c] == null) cur.next[c] = new Trie();
                cur = cur.next[c];
            }
            cur.end = true;
        }

        public boolean search(String word) {
            Trie node = walk(word);
            return node != null && node.end;
        }

        public boolean startsWith(String prefix) {
            return walk(prefix) != null;
        }

        Trie walk(String s) {
            Trie cur = this;
            for (int i = 0; i < s.length(); i++) {
                int c = s.charAt(i) - 'a';
                if (cur.next[c] == null) return null;
                cur = cur.next[c];
            }
            return cur;
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Implement Trie");
        System.out.println("=".repeat(60));

        Trie t = new Trie();
        t.insert("apple");
        System.out.println("search(apple) -> " + t.search("apple"));
        System.out.println("search(app) -> " + t.search("app"));
        System.out.println("startsWith(app) -> " + t.startsWith("app"));
        t.insert("app");
        System.out.println("search(app) -> " + t.search("app"));
    }
}
