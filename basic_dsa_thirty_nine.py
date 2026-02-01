"""
Basic DSA Problems - One More Fundamental Question
Simple and essential DSA problems for beginners
"""

import math


# Problem: Check if a Number is Sunny Number
# A Sunny number is a number n where n+1 is a perfect square
# Example: 8 is sunny because 8+1=9=3^2
# Example: 3 is sunny because 3+1=4=2^2
# Example: 24 is sunny because 24+1=25=5^2


def is_perfect_square(n):
    """
    Check if a number is a perfect square
    Time Complexity: O(1) using integer square root
    Space Complexity: O(1)
    """
    if n < 0:
        return False
    root = math.isqrt(n)
    return root * root == n


def is_sunny_number(n):
    """
    Check if a number is Sunny number
    A number n is sunny if n+1 is a perfect square
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if n < 0:
        return False
    return is_perfect_square(n + 1)


def get_sunny_numbers_in_range(start, end):
    """
    Find all Sunny numbers in a given range
    Time Complexity: O(end - start)
    Space Complexity: O(k) where k is the number of Sunny numbers
    """
    sunny_numbers = []
    
    for num in range(start, end + 1):
        if is_sunny_number(num):
            sunny_numbers.append(num)
    
    return sunny_numbers


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Check if a Number is Sunny Number")
    print("=" * 60)
    
    # Test Case 1 - Sunny number 8
    num1 = 8
    result1 = is_sunny_number(num1)
    print(f"Number: {num1}")
    print(f"n+1 = {num1 + 1} = {math.isqrt(num1 + 1)}^2")
    print(f"Is Sunny Number: {result1}")
    
    # Test Case 2 - Sunny number 3
    num2 = 3
    result2 = is_sunny_number(num2)
    print(f"\nNumber: {num2}")
    print(f"n+1 = {num2 + 1} = {math.isqrt(num2 + 1)}^2")
    print(f"Is Sunny Number: {result2}")
    
    # Test Case 3 - Sunny number 24
    num3 = 24
    result3 = is_sunny_number(num3)
    print(f"\nNumber: {num3}")
    print(f"n+1 = {num3 + 1} = {math.isqrt(num3 + 1)}^2")
    print(f"Is Sunny Number: {result3}")
    
    # Test Case 4 - Not Sunny number
    num4 = 5
    result4 = is_sunny_number(num4)
    print(f"\nNumber: {num4}")
    print(f"n+1 = {num4 + 1} (not a perfect square)")
    print(f"Is Sunny Number: {result4}")
    
    # Test Case 5 - Sunny number 0
    num5 = 0
    result5 = is_sunny_number(num5)
    print(f"\nNumber: {num5}")
    print(f"n+1 = {num5 + 1} = 1^2")
    print(f"Is Sunny Number: {result5}")
    
    # Test Case 6 - Find Sunny numbers in range
    start = 1
    end = 50
    sunny_nums = get_sunny_numbers_in_range(start, end)
    print(f"\nSunny numbers in range [{start}, {end}]:")
    print(sunny_nums)
    print(f"Count: {len(sunny_nums)}")
    
    # Test Case 7 - Sunny number 80
    num7 = 80
    result7 = is_sunny_number(num7)
    print(f"\nNumber: {num7}")
    print(f"n+1 = {num7 + 1} = 9^2")
    print(f"Is Sunny Number: {result7}")
