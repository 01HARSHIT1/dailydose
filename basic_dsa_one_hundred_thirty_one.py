"""
Basic DSA - Reverse Words in a String
Given a string s, reverse the order of the words.
"""


def reverse_words(s):
    """
    Split on whitespace and re-join reversed words.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    words = s.split()
    words.reverse()
    return " ".join(words)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Reverse Words in a String")
    print("=" * 60)

    print(reverse_words("the sky is blue"))        # "blue is sky the"
    print(reverse_words("  hello world  "))        # "world hello"
    print(reverse_words("a good   example"))       # "example good a"

