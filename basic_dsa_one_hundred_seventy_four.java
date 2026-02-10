/**
 * Basic DSA Problems - Design Add and Search Words Data Structure
 * Add word and search (search supports '.' as wildcard for any letter)
 */
public class basic_dsa_one_hundred_seventy_four {

    // Problem: Add words and search. search(word) can contain '.' meaning any letter.

    public static class WordDictionary {
        WordDictionary[] next = new WordDictionary[26];
        boolean end;

        public void addWord(String word) {
            WordDictionary cur = this;
            for (int i = 0; i < word.length(); i++) {
                int c = word.charAt(i) - 'a';
                if (cur.next[c] == null) cur.next[c] = new WordDictionary();
                cur = cur.next[c];
            }
            cur.end = true;
        }

        public boolean search(String word) {
            return search(word, 0, this);
        }

        boolean search(String word, int i, WordDictionary node) {
            if (node == null) return false;
            if (i == word.length()) return node.end;
            char ch = word.charAt(i);
            if (ch == '.') {
                for (int c = 0; c < 26; c++)
                    if (search(word, i + 1, node.next[c])) return true;
                return false;
            }
            return search(word, i + 1, node.next[ch - 'a']);
        }
    }

    public static void main(String[] args) {
        System.out.println("=".repeat(60));
        System.out.println("Problem: Add and Search Words");
        System.out.println("=".repeat(60));

        WordDictionary wd = new WordDictionary();
        wd.addWord("bad");
        wd.addWord("dad");
        wd.addWord("mad");
        System.out.println("search(pad) -> " + wd.search("pad"));
        System.out.println("search(bad) -> " + wd.search("bad"));
        System.out.println("search(.ad) -> " + wd.search(".ad"));
        System.out.println("search(b..) -> " + wd.search("b.."));
    }
}
