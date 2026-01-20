"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Sum of Digits of a Number
# Calculate the sum of all digits in a number

def sum_of_digits(n):
    """
    Calculate sum of digits using iterative approach
    Time Complexity: O(log n) where log is base 10
    Space Complexity: O(1)
    """
    n = abs(n)  # Handle negative numbers
    total = 0
    
    while n > 0:
        total += n % 10
        n //= 10
    
    return total


def sum_of_digits_recursive(n):
    """
    Calculate sum of digits using recursive approach
    Time Complexity: O(log n)
    Space Complexity: O(log n) due to recursion stack
    """
    n = abs(n)  # Handle negative numbers
    if n == 0:
        return 0
    return (n % 10) + sum_of_digits_recursive(n // 10)


# Problem 2: Reverse a Number
# Reverse the digits of a number

def reverse_number(n):
    """
    Reverse a number using iterative approach
    Time Complexity: O(log n) where log is base 10
    Space Complexity: O(1)
    """
    is_negative = n < 0
    n = abs(n)
    reversed_num = 0
    
    while n > 0:
        reversed_num = reversed_num * 10 + n % 10
        n //= 10
    
    return -reversed_num if is_negative else reversed_num


def reverse_number_recursive(n, reversed_so_far=0):
    """
    Reverse a number using recursive approach (helper function pattern)
    Time Complexity: O(log n)
    Space Complexity: O(log n) due to recursion stack
    """
    if n == 0:
        return reversed_so_far
    
    # Handle negative numbers
    if n < 0:
        return -reverse_number_recursive(abs(n))
    
    return reverse_number_recursive(n // 10, reversed_so_far * 10 + n % 10)


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Sum of Digits of a Number")
    print("=" * 60)
    
    # Test Case 1
    num1 = 12345
    sum_iter1 = sum_of_digits(num1)
    sum_rec1 = sum_of_digits_recursive(num1)
    print(f"Number: {num1}")
    print(f"Sum of digits (Iterative): {sum_iter1}")
    print(f"Sum of digits (Recursive): {sum_rec1}")
    
    # Test Case 2
    num2 = 9876
    sum_iter2 = sum_of_digits(num2)
    sum_rec2 = sum_of_digits_recursive(num2)
    print(f"\nNumber: {num2}")
    print(f"Sum of digits (Iterative): {sum_iter2}")
    print(f"Sum of digits (Recursive): {sum_rec2}")
    
    # Test Case 3 - Single digit
    num3 = 5
    sum_iter3 = sum_of_digits(num3)
    sum_rec3 = sum_of_digits_recursive(num3)
    print(f"\nNumber: {num3}")
    print(f"Sum of digits (Iterative): {sum_iter3}")
    print(f"Sum of digits (Recursive): {sum_rec3}")
    
    # Test Case 4 - Negative number
    num4 = -123
    sum_iter4 = sum_of_digits(num4)
    sum_rec4 = sum_of_digits_recursive(num4)
    print(f"\nNumber: {num4}")
    print(f"Sum of digits (Iterative): {sum_iter4}")
    print(f"Sum of digits (Recursive): {sum_rec4}")
    
    # Test Case 5 - Zero
    num5 = 0
    sum_iter5 = sum_of_digits(num5)
    sum_rec5 = sum_of_digits_recursive(num5)
    print(f"\nNumber: {num5}")
    print(f"Sum of digits (Iterative): {sum_iter5}")
    print(f"Sum of digits (Recursive): {sum_rec5}")
    
    # Test Case 6 - Number with zeros
    num6 = 1005
    sum_iter6 = sum_of_digits(num6)
    sum_rec6 = sum_of_digits_recursive(num6)
    print(f"\nNumber: {num6}")
    print(f"Sum of digits (Iterative): {sum_iter6}")
    print(f"Sum of digits (Recursive): {sum_rec6}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Reverse a Number")
    print("=" * 60)
    
    # Test Case 1
    num7 = 12345
    rev_iter1 = reverse_number(num7)
    rev_rec1 = reverse_number_recursive(num7)
    print(f"Number: {num7}")
    print(f"Reversed (Iterative): {rev_iter1}")
    print(f"Reversed (Recursive): {rev_rec1}")
    
    # Test Case 2
    num8 = 9876
    rev_iter2 = reverse_number(num8)
    rev_rec2 = reverse_number_recursive(num8)
    print(f"\nNumber: {num8}")
    print(f"Reversed (Iterative): {rev_iter2}")
    print(f"Reversed (Recursive): {rev_rec2}")
    
    # Test Case 3 - Single digit
    num9 = 5
    rev_iter3 = reverse_number(num9)
    rev_rec3 = reverse_number_recursive(num9)
    print(f"\nNumber: {num9}")
    print(f"Reversed (Iterative): {rev_iter3}")
    print(f"Reversed (Recursive): {rev_rec3}")
    
    # Test Case 4 - Negative number
    num10 = -123
    rev_iter4 = reverse_number(num10)
    rev_rec4 = reverse_number_recursive(num10)
    print(f"\nNumber: {num10}")
    print(f"Reversed (Iterative): {rev_iter4}")
    print(f"Reversed (Recursive): {rev_rec4}")
    
    # Test Case 5 - Number ending with zero
    num11 = 1200
    rev_iter5 = reverse_number(num11)
    rev_rec5 = reverse_number_recursive(num11)
    print(f"\nNumber: {num11}")
    print(f"Reversed (Iterative): {rev_iter5}")
    print(f"Reversed (Recursive): {rev_rec5}")
    
    # Test Case 6 - Palindrome number
    num12 = 1221
    rev_iter6 = reverse_number(num12)
    rev_rec6 = reverse_number_recursive(num12)
    print(f"\nNumber: {num12}")
    print(f"Reversed (Iterative): {rev_iter6}")
    print(f"Reversed (Recursive): {rev_rec6}")
