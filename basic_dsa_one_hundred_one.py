"""
Basic DSA - Implement Trie (Prefix Tree)
Support insert, search full word, and search prefix.
"""


class TrieNode:
    def __init__(self):
        self.children = {}
        self.is_end = False


class Trie:
    def __init__(self):
        self._root = TrieNode()

    def insert(self, word):
        node = self._root
        for ch in word:
            if ch not in node.children:
                node.children[ch] = TrieNode()
            node = node.children[ch]
        node.is_end = True

    def search(self, word):
        node = self._root
        for ch in word:
            if ch not in node.children:
                return False
            node = node.children[ch]
        return node.is_end

    def starts_with(self, prefix):
        node = self._root
        for ch in prefix:
            if ch not in node.children:
                return False
            node = node.children[ch]
        return True


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Implement Trie (Prefix Tree)")
    print("=" * 60)

    t = Trie()
    t.insert("apple")
    print(t.search("apple"))   # True
    print(t.search("app"))     # False
    print(t.starts_with("app"))  # True
    t.insert("app")
    print(t.search("app"))     # True
