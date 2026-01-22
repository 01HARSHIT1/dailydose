"""
Basic DSA Problems - One More Fundamental Question
Simple and essential DSA problems for beginners
"""


# Problem: Check if a Number is Palindrome
# A palindrome number is a number that remains the same when its digits are reversed
# Example: 121, 1331, 12321 are palindromes

def reverse_number(n):
    """
    Reverse a number
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    reversed_num = 0
    num = abs(n)
    
    while num > 0:
        reversed_num = reversed_num * 10 + num % 10
        num //= 10
    
    return -reversed_num if n < 0 else reversed_num


def is_palindrome_number_string(n):
    """
    Check if a number is palindrome using string conversion
    Time Complexity: O(log n)
    Space Complexity: O(log n)
    """
    num_str = str(abs(n))
    return num_str == num_str[::-1]


def is_palindrome_number_reverse(n):
    """
    Check if a number is palindrome by reversing it
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n < 0:
        return False  # Negative numbers are not palindromes
    
    original = n
    reversed_num = reverse_number(n)
    return original == reversed_num


def is_palindrome_number_two_pointers(n):
    """
    Check if a number is palindrome using two-pointer approach
    Time Complexity: O(log n)
    Space Complexity: O(log n) for string conversion
    """
    if n < 0:
        return False
    
    num_str = str(n)
    left = 0
    right = len(num_str) - 1
    
    while left < right:
        if num_str[left] != num_str[right]:
            return False
        left += 1
        right -= 1
    
    return True


def get_palindrome_numbers_in_range(start, end):
    """
    Find all palindrome numbers in a given range
    Time Complexity: O((end - start) * log n)
    Space Complexity: O(k) where k is the number of palindrome numbers
    """
    palindrome_numbers = []
    
    for num in range(start, end + 1):
        if is_palindrome_number_reverse(num):
            palindrome_numbers.append(num)
    
    return palindrome_numbers


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Check if a Number is Palindrome")
    print("=" * 60)
    
    # Test Case 1 - Palindrome number 121
    num1 = 121
    result1_string = is_palindrome_number_string(num1)
    result1_reverse = is_palindrome_number_reverse(num1)
    result1_two_pointers = is_palindrome_number_two_pointers(num1)
    reversed1 = reverse_number(num1)
    print(f"Number: {num1}")
    print(f"Reversed: {reversed1}")
    print(f"Is palindrome (string): {result1_string}")
    print(f"Is palindrome (reverse): {result1_reverse}")
    print(f"Is palindrome (two pointers): {result1_two_pointers}")
    
    # Test Case 2 - Palindrome number 1331
    num2 = 1331
    result2 = is_palindrome_number_reverse(num2)
    reversed2 = reverse_number(num2)
    print(f"\nNumber: {num2}")
    print(f"Reversed: {reversed2}")
    print(f"Is palindrome: {result2}")
    
    # Test Case 3 - Not palindrome
    num3 = 123
    result3 = is_palindrome_number_reverse(num3)
    reversed3 = reverse_number(num3)
    print(f"\nNumber: {num3}")
    print(f"Reversed: {reversed3}")
    print(f"Is palindrome: {result3}")
    
    # Test Case 4 - Single digit (always palindrome)
    num4 = 7
    result4 = is_palindrome_number_reverse(num4)
    print(f"\nNumber: {num4}")
    print(f"Is palindrome: {result4}")
    
    # Test Case 5 - Palindrome number 12321
    num5 = 12321
    result5 = is_palindrome_number_reverse(num5)
    reversed5 = reverse_number(num5)
    print(f"\nNumber: {num5}")
    print(f"Reversed: {reversed5}")
    print(f"Is palindrome: {result5}")
    
    # Test Case 6 - Find palindrome numbers in range
    start = 100
    end = 200
    palindrome_nums = get_palindrome_numbers_in_range(start, end)
    print(f"\nPalindrome numbers in range [{start}, {end}]:")
    print(palindrome_nums)
    print(f"Count: {len(palindrome_nums)}")
    
    # Test Case 7 - Zero
    num7 = 0
    result7 = is_palindrome_number_reverse(num7)
    print(f"\nNumber: {num7}")
    print(f"Is palindrome: {result7}")
