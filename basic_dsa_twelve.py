"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if a Number is Even or Odd
# Determine whether a number is even or odd

def is_even_or_odd(n):
    """
    Check if a number is even or odd using modulo operator
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if n % 2 == 0:
        return "Even"
    else:
        return "Odd"


def is_even_or_odd_bitwise(n):
    """
    Check if a number is even or odd using bitwise AND
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if n & 1 == 0:
        return "Even"
    else:
        return "Odd"


# Problem 2: Find Sum of First N Natural Numbers
# Calculate the sum of first n natural numbers (1 + 2 + 3 + ... + n)

def sum_natural_numbers_iterative(n):
    """
    Find sum using iterative approach
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n < 0:
        return None
    
    total = 0
    for i in range(1, n + 1):
        total += i
    return total


def sum_natural_numbers_formula(n):
    """
    Find sum using mathematical formula: n * (n + 1) / 2
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if n < 0:
        return None
    return n * (n + 1) // 2


def sum_natural_numbers_recursive(n):
    """
    Find sum using recursive approach
    Time Complexity: O(n)
    Space Complexity: O(n) due to recursion stack
    """
    if n < 0:
        return None
    if n == 0:
        return 0
    return n + sum_natural_numbers_recursive(n - 1)


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if a Number is Even or Odd")
    print("=" * 60)
    
    # Test Case 1 - Even number
    num1 = 10
    result1 = is_even_or_odd(num1)
    result1b = is_even_or_odd_bitwise(num1)
    print(f"Number: {num1}")
    print(f"Result (Modulo): {result1}")
    print(f"Result (Bitwise): {result1b}")
    
    # Test Case 2 - Odd number
    num2 = 15
    result2 = is_even_or_odd(num2)
    result2b = is_even_or_odd_bitwise(num2)
    print(f"\nNumber: {num2}")
    print(f"Result (Modulo): {result2}")
    print(f"Result (Bitwise): {result2b}")
    
    # Test Case 3 - Zero
    num3 = 0
    result3 = is_even_or_odd(num3)
    result3b = is_even_or_odd_bitwise(num3)
    print(f"\nNumber: {num3}")
    print(f"Result (Modulo): {result3}")
    print(f"Result (Bitwise): {result3b}")
    
    # Test Case 4 - Negative even
    num4 = -8
    result4 = is_even_or_odd(num4)
    result4b = is_even_or_odd_bitwise(num4)
    print(f"\nNumber: {num4}")
    print(f"Result (Modulo): {result4}")
    print(f"Result (Bitwise): {result4b}")
    
    # Test Case 5 - Negative odd
    num5 = -7
    result5 = is_even_or_odd(num5)
    result5b = is_even_or_odd_bitwise(num5)
    print(f"\nNumber: {num5}")
    print(f"Result (Modulo): {result5}")
    print(f"Result (Bitwise): {result5b}")
    
    # Test Case 6 - Large even number
    num6 = 1000
    result6 = is_even_or_odd(num6)
    result6b = is_even_or_odd_bitwise(num6)
    print(f"\nNumber: {num6}")
    print(f"Result (Modulo): {result6}")
    print(f"Result (Bitwise): {result6b}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Find Sum of First N Natural Numbers")
    print("=" * 60)
    
    # Test Case 1
    n1 = 5
    sum_iter1 = sum_natural_numbers_iterative(n1)
    sum_formula1 = sum_natural_numbers_formula(n1)
    sum_rec1 = sum_natural_numbers_recursive(n1)
    print(f"N = {n1}")
    print(f"Sum (Iterative): {sum_iter1}")
    print(f"Sum (Formula): {sum_formula1}")
    print(f"Sum (Recursive): {sum_rec1}")
    print(f"Verification: 1+2+3+4+5 = {sum_iter1}")
    
    # Test Case 2
    n2 = 10
    sum_iter2 = sum_natural_numbers_iterative(n2)
    sum_formula2 = sum_natural_numbers_formula(n2)
    sum_rec2 = sum_natural_numbers_recursive(n2)
    print(f"\nN = {n2}")
    print(f"Sum (Iterative): {sum_iter2}")
    print(f"Sum (Formula): {sum_formula2}")
    print(f"Sum (Recursive): {sum_rec2}")
    
    # Test Case 3 - Single number
    n3 = 1
    sum_iter3 = sum_natural_numbers_iterative(n3)
    sum_formula3 = sum_natural_numbers_formula(n3)
    sum_rec3 = sum_natural_numbers_recursive(n3)
    print(f"\nN = {n3}")
    print(f"Sum (Iterative): {sum_iter3}")
    print(f"Sum (Formula): {sum_formula3}")
    print(f"Sum (Recursive): {sum_rec3}")
    
    # Test Case 4 - Zero
    n4 = 0
    sum_iter4 = sum_natural_numbers_iterative(n4)
    sum_formula4 = sum_natural_numbers_formula(n4)
    sum_rec4 = sum_natural_numbers_recursive(n4)
    print(f"\nN = {n4}")
    print(f"Sum (Iterative): {sum_iter4}")
    print(f"Sum (Formula): {sum_formula4}")
    print(f"Sum (Recursive): {sum_rec4}")
    
    # Test Case 5 - Large number
    n5 = 100
    sum_iter5 = sum_natural_numbers_iterative(n5)
    sum_formula5 = sum_natural_numbers_formula(n5)
    sum_rec5 = sum_natural_numbers_recursive(n5)
    print(f"\nN = {n5}")
    print(f"Sum (Iterative): {sum_iter5}")
    print(f"Sum (Formula): {sum_formula5}")
    print(f"Sum (Recursive): {sum_rec5}")
    
    # Test Case 6 - Negative number
    n6 = -5
    sum_iter6 = sum_natural_numbers_iterative(n6)
    sum_formula6 = sum_natural_numbers_formula(n6)
    sum_rec6 = sum_natural_numbers_recursive(n6)
    print(f"\nN = {n6}")
    print(f"Sum (Iterative): {sum_iter6}")
    print(f"Sum (Formula): {sum_formula6}")
    print(f"Sum (Recursive): {sum_rec6}")
