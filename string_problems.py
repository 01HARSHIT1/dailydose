"""
String DSA Interview Problems
Collection of common string problems with solutions
"""


# Problem 1: Reverse String
# Reverse a string in-place
def reverse_string(s):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    s = list(s)
    left, right = 0, len(s) - 1
    while left < right:
        s[left], s[right] = s[right], s[left]
        left += 1
        right -= 1
    return ''.join(s)


# Problem 2: Valid Anagram
# Check if two strings are anagrams
def is_anagram(s, t):
    """
    Time Complexity: O(n)
    Space Complexity: O(1) - limited to 26 characters
    """
    if len(s) != len(t):
        return False
    
    char_count = {}
    for char in s:
        char_count[char] = char_count.get(char, 0) + 1
    
    for char in t:
        if char not in char_count:
            return False
        char_count[char] -= 1
        if char_count[char] == 0:
            del char_count[char]
    
    return len(char_count) == 0


# Problem 3: First Unique Character
# Find the first non-repeating character in a string
def first_uniq_char(s):
    """
    Time Complexity: O(n)
    Space Complexity: O(1) - limited to 26 characters
    """
    char_count = {}
    for char in s:
        char_count[char] = char_count.get(char, 0) + 1
    
    for i, char in enumerate(s):
        if char_count[char] == 1:
            return i
    
    return -1


# Problem 4: Valid Palindrome
# Check if a string is a palindrome (considering alphanumeric only)
def is_palindrome(s):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    left, right = 0, len(s) - 1
    
    while left < right:
        while left < right and not s[left].isalnum():
            left += 1
        while left < right and not s[right].isalnum():
            right -= 1
        
        if s[left].lower() != s[right].lower():
            return False
        
        left += 1
        right -= 1
    
    return True


# Problem 5: Longest Common Prefix
# Find the longest common prefix string among an array of strings
def longest_common_prefix(strs):
    """
    Time Complexity: O(S) where S is sum of all characters
    Space Complexity: O(1)
    """
    if not strs:
        return ""
    
    prefix = strs[0]
    for i in range(1, len(strs)):
        while not strs[i].startswith(prefix):
            prefix = prefix[:-1]
            if not prefix:
                return ""
    
    return prefix


# Problem 6: String to Integer (atoi)
# Convert string to integer
def my_atoi(s):
    """
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    s = s.strip()
    if not s:
        return 0
    
    sign = 1
    if s[0] == '-':
        sign = -1
        s = s[1:]
    elif s[0] == '+':
        s = s[1:]
    
    result = 0
    for char in s:
        if not char.isdigit():
            break
        result = result * 10 + int(char)
        if result * sign > 2**31 - 1:
            return 2**31 - 1
        if result * sign < -2**31:
            return -2**31
    
    return result * sign


# Problem 7: Implement strStr() (Find Needle in Haystack)
# Find the first occurrence of needle in haystack
def str_str(haystack, needle):
    """
    Time Complexity: O(n * m)
    Space Complexity: O(1)
    """
    if not needle:
        return 0
    
    for i in range(len(haystack) - len(needle) + 1):
        if haystack[i:i + len(needle)] == needle:
            return i
    
    return -1


# Problem 8: Reverse Words in a String
# Reverse the order of words in a string
def reverse_words(s):
    """
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    words = s.split()
    return ' '.join(reversed(words))


# Problem 9: Longest Substring Without Repeating Characters
# Find length of longest substring without repeating characters
def length_of_longest_substring(s):
    """
    Time Complexity: O(n)
    Space Complexity: O(min(n, m)) where m is charset size
    """
    char_map = {}
    max_length = 0
    start = 0
    
    for end in range(len(s)):
        if s[end] in char_map and char_map[s[end]] >= start:
            start = char_map[s[end]] + 1
        
        char_map[s[end]] = end
        max_length = max(max_length, end - start + 1)
    
    return max_length


# Problem 10: Group Anagrams
# Group strings that are anagrams of each other
def group_anagrams(strs):
    """
    Time Complexity: O(n * k log k) where k is max string length
    Space Complexity: O(n * k)
    """
    anagram_map = {}
    
    for s in strs:
        sorted_s = ''.join(sorted(s))
        if sorted_s not in anagram_map:
            anagram_map[sorted_s] = []
        anagram_map[sorted_s].append(s)
    
    return list(anagram_map.values())


# Problem 11: Minimum Window Substring
# Find minimum window substring containing all characters of another string
def min_window(s, t):
    """
    Time Complexity: O(|s| + |t|)
    Space Complexity: O(|s| + |t|)
    """
    if not s or not t:
        return ""
    
    dict_t = {}
    for char in t:
        dict_t[char] = dict_t.get(char, 0) + 1
    
    required = len(dict_t)
    left, right = 0, 0
    formed = 0
    
    window_counts = {}
    ans = float("inf"), None, None
    
    while right < len(s):
        char = s[right]
        window_counts[char] = window_counts.get(char, 0) + 1
        
        if char in dict_t and window_counts[char] == dict_t[char]:
            formed += 1
        
        while left <= right and formed == required:
            char = s[left]
            
            if right - left + 1 < ans[0]:
                ans = (right - left + 1, left, right)
            
            window_counts[char] -= 1
            if char in dict_t and window_counts[char] < dict_t[char]:
                formed -= 1
            
            left += 1
        
        right += 1
    
    return "" if ans[0] == float("inf") else s[ans[1]:ans[2] + 1]


# Problem 12: Longest Palindromic Substring
# Find the longest palindromic substring
def longest_palindrome(s):
    """
    Time Complexity: O(n^2)
    Space Complexity: O(1)
    """
    if not s:
        return ""
    
    start = 0
    max_length = 1
    
    def expand_around_center(left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1
    
    for i in range(len(s)):
        len1 = expand_around_center(i, i)
        len2 = expand_around_center(i, i + 1)
        length = max(len1, len2)
        
        if length > max_length:
            max_length = length
            start = i - (length - 1) // 2
    
    return s[start:start + max_length]


# Problem 13: Valid Parentheses
# Check if string contains valid parentheses
def is_valid_parentheses(s):
    """
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    stack = []
    mapping = {')': '(', '}': '{', ']': '['}
    
    for char in s:
        if char in mapping:
            top_element = stack.pop() if stack else '#'
            if mapping[char] != top_element:
                return False
        else:
            stack.append(char)
    
    return not stack


# Problem 14: Count and Say
# Generate the nth term of the count-and-say sequence
def count_and_say(n):
    """
    Time Complexity: O(2^n) approximately
    Space Complexity: O(2^n) approximately
    """
    if n == 1:
        return "1"
    
    prev = count_and_say(n - 1)
    result = ""
    count = 1
    
    for i in range(len(prev)):
        if i < len(prev) - 1 and prev[i] == prev[i + 1]:
            count += 1
        else:
            result += str(count) + prev[i]
            count = 1
    
    return result


# Problem 15: Remove Duplicate Letters
# Remove duplicate letters to get lexicographically smallest result
def remove_duplicate_letters(s):
    """
    Time Complexity: O(n)
    Space Complexity: O(1) - limited to 26 characters
    """
    last_occurrence = {char: i for i, char in enumerate(s)}
    stack = []
    seen = set()
    
    for i, char in enumerate(s):
        if char in seen:
            continue
        
        while stack and char < stack[-1] and last_occurrence[stack[-1]] > i:
            seen.remove(stack.pop())
        
        stack.append(char)
        seen.add(char)
    
    return ''.join(stack)


# Problem 16: Word Pattern
# Check if string follows a given pattern
def word_pattern(pattern, s):
    """
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    words = s.split()
    if len(pattern) != len(words):
        return False
    
    pattern_to_word = {}
    word_to_pattern = {}
    
    for p, word in zip(pattern, words):
        if p in pattern_to_word:
            if pattern_to_word[p] != word:
                return False
        else:
            if word in word_to_pattern:
                return False
            pattern_to_word[p] = word
            word_to_pattern[word] = p
    
    return True


# Problem 17: Reverse String II
# Reverse every k characters in a string
def reverse_str(s, k):
    """
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    s = list(s)
    for i in range(0, len(s), 2 * k):
        s[i:i + k] = reversed(s[i:i + k])
    return ''.join(s)


# Problem 18: ZigZag Conversion
# Convert string to zigzag pattern
def convert_zigzag(s, num_rows):
    """
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    if num_rows == 1:
        return s
    
    rows = [''] * num_rows
    current_row = 0
    going_down = False
    
    for char in s:
        rows[current_row] += char
        if current_row == 0 or current_row == num_rows - 1:
            going_down = not going_down
        current_row += 1 if going_down else -1
    
    return ''.join(rows)


# Problem 19: Add Strings
# Add two numbers represented as strings
def add_strings(num1, num2):
    """
    Time Complexity: O(max(len(num1), len(num2)))
    Space Complexity: O(max(len(num1), len(num2)))
    """
    i, j = len(num1) - 1, len(num2) - 1
    carry = 0
    result = []
    
    while i >= 0 or j >= 0 or carry:
        digit1 = int(num1[i]) if i >= 0 else 0
        digit2 = int(num2[j]) if j >= 0 else 0
        
        total = digit1 + digit2 + carry
        carry = total // 10
        result.append(str(total % 10))
        
        i -= 1
        j -= 1
    
    return ''.join(reversed(result))


# Problem 20: Multiply Strings
# Multiply two numbers represented as strings
def multiply_strings(num1, num2):
    """
    Time Complexity: O(m * n)
    Space Complexity: O(m + n)
    """
    if num1 == "0" or num2 == "0":
        return "0"
    
    m, n = len(num1), len(num2)
    result = [0] * (m + n)
    
    for i in range(m - 1, -1, -1):
        for j in range(n - 1, -1, -1):
            mul = int(num1[i]) * int(num2[j])
            p1, p2 = i + j, i + j + 1
            total = mul + result[p2]
            
            result[p2] = total % 10
            result[p1] += total // 10
    
    start = 0
    while start < len(result) and result[start] == 0:
        start += 1
    
    return ''.join(str(digit) for digit in result[start:])


# Test cases
if __name__ == "__main__":
    print("Problem 1 - Reverse String:")
    print(reverse_string("hello"))  # Output: "olleh"
    
    print("\nProblem 2 - Valid Anagram:")
    print(is_anagram("anagram", "nagaram"))  # Output: True
    
    print("\nProblem 3 - First Unique Character:")
    print(first_uniq_char("leetcode"))  # Output: 0
    
    print("\nProblem 4 - Valid Palindrome:")
    print(is_palindrome("A man, a plan, a canal: Panama"))  # Output: True
    
    print("\nProblem 5 - Longest Common Prefix:")
    print(longest_common_prefix(["flower", "flow", "flight"]))  # Output: "fl"
    
    print("\nProblem 6 - String to Integer:")
    print(my_atoi("   -42"))  # Output: -42
    
    print("\nProblem 7 - Find Needle in Haystack:")
    print(str_str("hello", "ll"))  # Output: 2
    
    print("\nProblem 8 - Reverse Words:")
    print(reverse_words("the sky is blue"))  # Output: "blue is sky the"
    
    print("\nProblem 9 - Longest Substring Without Repeating Characters:")
    print(length_of_longest_substring("abcabcbb"))  # Output: 3
    
    print("\nProblem 10 - Group Anagrams:")
    print(group_anagrams(["eat", "tea", "tan", "ate", "nat", "bat"]))
    
    print("\nProblem 11 - Minimum Window Substring:")
    print(min_window("ADOBECODEBANC", "ABC"))  # Output: "BANC"
    
    print("\nProblem 12 - Longest Palindromic Substring:")
    print(longest_palindrome("babad"))  # Output: "bab" or "aba"
    
    print("\nProblem 13 - Valid Parentheses:")
    print(is_valid_parentheses("()[]{}"))  # Output: True
    
    print("\nProblem 14 - Count and Say:")
    print(count_and_say(4))  # Output: "1211"
    
    print("\nProblem 15 - Remove Duplicate Letters:")
    print(remove_duplicate_letters("bcabc"))  # Output: "abc"
    
    print("\nProblem 16 - Word Pattern:")
    print(word_pattern("abba", "dog cat cat dog"))  # Output: True
    
    print("\nProblem 17 - Reverse String II:")
    print(reverse_str("abcdefg", 2))  # Output: "bacdfeg"
    
    print("\nProblem 18 - ZigZag Conversion:")
    print(convert_zigzag("PAYPALISHIRING", 3))  # Output: "PAHNAPLSIIGYIR"
    
    print("\nProblem 19 - Add Strings:")
    print(add_strings("123", "456"))  # Output: "579"
    
    print("\nProblem 20 - Multiply Strings:")
    print(multiply_strings("123", "456"))  # Output: "56088"
