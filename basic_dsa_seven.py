"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""

import math


# Problem 1: Find GCD (Greatest Common Divisor) / HCF (Highest Common Factor)
# Find the greatest common divisor of two numbers

def gcd_iterative(a, b):
    """
    Find GCD using iterative approach (Euclidean Algorithm)
    Time Complexity: O(log(min(a, b)))
    Space Complexity: O(1)
    """
    a, b = abs(a), abs(b)
    while b != 0:
        a, b = b, a % b
    return a


def gcd_recursive(a, b):
    """
    Find GCD using recursive approach (Euclidean Algorithm)
    Time Complexity: O(log(min(a, b)))
    Space Complexity: O(log(min(a, b))) due to recursion stack
    """
    a, b = abs(a), abs(b)
    if b == 0:
        return a
    return gcd_recursive(b, a % b)


# Problem 2: Check if a Number is Perfect Square
# Determine whether a number is a perfect square

def is_perfect_square(n):
    """
    Check if a number is perfect square
    Time Complexity: O(log n) or O(1) depending on sqrt implementation
    Space Complexity: O(1)
    """
    if n < 0:
        return False
    
    sqrt_n = int(math.isqrt(n))
    return sqrt_n * sqrt_n == n


def is_perfect_square_no_library(n):
    """
    Check if a number is perfect square without using math library
    Using binary search approach
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n < 0:
        return False
    if n == 0 or n == 1:
        return True
    
    left, right = 1, n // 2
    
    while left <= right:
        mid = left + (right - left) // 2
        square = mid * mid
        
        if square == n:
            return True
        elif square < n:
            left = mid + 1
        else:
            right = mid - 1
    
    return False


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Find GCD (Greatest Common Divisor)")
    print("=" * 60)
    
    # Test Case 1
    a1, b1 = 48, 18
    gcd_iter1 = gcd_iterative(a1, b1)
    gcd_rec1 = gcd_recursive(a1, b1)
    print(f"Numbers: {a1}, {b1}")
    print(f"GCD (Iterative): {gcd_iter1}")
    print(f"GCD (Recursive): {gcd_rec1}")
    
    # Test Case 2
    a2, b2 = 100, 25
    gcd_iter2 = gcd_iterative(a2, b2)
    gcd_rec2 = gcd_recursive(a2, b2)
    print(f"\nNumbers: {a2}, {b2}")
    print(f"GCD (Iterative): {gcd_iter2}")
    print(f"GCD (Recursive): {gcd_rec2}")
    
    # Test Case 3 - Coprime numbers
    a3, b3 = 17, 13
    gcd_iter3 = gcd_iterative(a3, b3)
    gcd_rec3 = gcd_recursive(a3, b3)
    print(f"\nNumbers: {a3}, {b3}")
    print(f"GCD (Iterative): {gcd_iter3}")
    print(f"GCD (Recursive): {gcd_rec3}")
    
    # Test Case 4 - Same numbers
    a4, b4 = 15, 15
    gcd_iter4 = gcd_iterative(a4, b4)
    gcd_rec4 = gcd_recursive(a4, b4)
    print(f"\nNumbers: {a4}, {b4}")
    print(f"GCD (Iterative): {gcd_iter4}")
    print(f"GCD (Recursive): {gcd_rec4}")
    
    # Test Case 5 - One is zero
    a5, b5 = 0, 15
    gcd_iter5 = gcd_iterative(a5, b5)
    gcd_rec5 = gcd_recursive(a5, b5)
    print(f"\nNumbers: {a5}, {b5}")
    print(f"GCD (Iterative): {gcd_iter5}")
    print(f"GCD (Recursive): {gcd_rec5}")
    
    # Test Case 6 - Large numbers
    a6, b6 = 252, 105
    gcd_iter6 = gcd_iterative(a6, b6)
    gcd_rec6 = gcd_recursive(a6, b6)
    print(f"\nNumbers: {a6}, {b6}")
    print(f"GCD (Iterative): {gcd_iter6}")
    print(f"GCD (Recursive): {gcd_rec6}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Check if a Number is Perfect Square")
    print("=" * 60)
    
    # Test Case 1 - Perfect square
    num1 = 25
    result1 = is_perfect_square(num1)
    result1b = is_perfect_square_no_library(num1)
    print(f"Number: {num1}")
    print(f"Is Perfect Square (with math): {result1}")
    print(f"Is Perfect Square (binary search): {result1b}")
    
    # Test Case 2 - Not a perfect square
    num2 = 26
    result2 = is_perfect_square(num2)
    result2b = is_perfect_square_no_library(num2)
    print(f"\nNumber: {num2}")
    print(f"Is Perfect Square (with math): {result2}")
    print(f"Is Perfect Square (binary search): {result2b}")
    
    # Test Case 3 - Zero
    num3 = 0
    result3 = is_perfect_square(num3)
    result3b = is_perfect_square_no_library(num3)
    print(f"\nNumber: {num3}")
    print(f"Is Perfect Square (with math): {result3}")
    print(f"Is Perfect Square (binary search): {result3b}")
    
    # Test Case 4 - One
    num4 = 1
    result4 = is_perfect_square(num4)
    result4b = is_perfect_square_no_library(num4)
    print(f"\nNumber: {num4}")
    print(f"Is Perfect Square (with math): {result4}")
    print(f"Is Perfect Square (binary search): {result4b}")
    
    # Test Case 5 - Large perfect square
    num5 = 144
    result5 = is_perfect_square(num5)
    result5b = is_perfect_square_no_library(num5)
    print(f"\nNumber: {num5}")
    print(f"Is Perfect Square (with math): {result5}")
    print(f"Is Perfect Square (binary search): {result5b}")
    
    # Test Case 6 - Negative number
    num6 = -16
    result6 = is_perfect_square(num6)
    result6b = is_perfect_square_no_library(num6)
    print(f"\nNumber: {num6}")
    print(f"Is Perfect Square (with math): {result6}")
    print(f"Is Perfect Square (binary search): {result6b}")
    
    # Test Case 7 - Not perfect square
    num7 = 50
    result7 = is_perfect_square(num7)
    result7b = is_perfect_square_no_library(num7)
    print(f"\nNumber: {num7}")
    print(f"Is Perfect Square (with math): {result7}")
    print(f"Is Perfect Square (binary search): {result7b}")
