"""
Basic DSA - Valid Word Abbreviation
Given a non-empty string word and an abbreviation abbr, return whether abbr is a
valid abbreviation for word.

Rules:
- Letters must match.
- Numbers represent how many characters to skip in word.
- Leading zeros in numbers are not allowed.
"""


def valid_word_abbreviation(word, abbr):
    """
    Two pointers; parse numbers in abbr and advance in word.
    Time Complexity: O(len(word) + len(abbr))
    Space Complexity: O(1)
    """
    i = j = 0
    while i < len(word) and j < len(abbr):
        if abbr[j].isalpha():
            if word[i] != abbr[j]:
                return False
            i += 1
            j += 1
            continue

        if abbr[j] == "0":
            return False
        num = 0
        while j < len(abbr) and abbr[j].isdigit():
            num = num * 10 + (ord(abbr[j]) - ord("0"))
            j += 1
        i += num

    return i == len(word) and j == len(abbr)


if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Valid Word Abbreviation")
    print("=" * 60)

    print(valid_word_abbreviation("internationalization", "i12iz4n"))  # True
    print(valid_word_abbreviation("apple", "a2e"))  # False
