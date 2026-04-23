"""
Basic DSA - Reverse Words in a String III
Given a string s, reverse the order of characters in each word while still
preserving whitespace and initial word order.
"""


def reverse_words(s):
    """
    Split by spaces, reverse each word, and join back.
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    return " ".join(word[::-1] for word in s.split(" "))


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Reverse Words in a String III")
    print("=" * 60)

    print(reverse_words("Let's take LeetCode contest"))  # s'teL ekat edoCteeL tsetnoc
    print(reverse_words("God Ding"))  # doG gniD
