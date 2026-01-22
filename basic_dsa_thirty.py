"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if a Number is Ugly Number
# An Ugly number is a number whose only prime factors are 2, 3, or 5
# Example: 6 = 2 × 3 (ugly), 8 = 2 × 2 × 2 (ugly), 14 = 2 × 7 (not ugly, has factor 7)

def is_ugly_number(n):
    """
    Check if a number is Ugly number
    An Ugly number has only prime factors 2, 3, or 5
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return False
    if n == 1:
        return True  # 1 is considered ugly
    
    # Remove all factors of 2, 3, and 5
    while n % 2 == 0:
        n //= 2
    while n % 3 == 0:
        n //= 3
    while n % 5 == 0:
        n //= 5
    
    # If after removing 2, 3, 5 factors, we get 1, it's ugly
    return n == 1


def get_ugly_factors(n):
    """
    Get prime factors of a number (only 2, 3, 5 if ugly)
    Returns list of factors
    Time Complexity: O(log n)
    Space Complexity: O(log n)
    """
    if n <= 0:
        return []
    
    factors = []
    num = n
    
    # Check factors of 2, 3, 5
    for prime in [2, 3, 5]:
        while num % prime == 0:
            factors.append(prime)
            num //= prime
    
    return factors if num == 1 else None  # None if has other factors


def get_ugly_numbers_in_range(start, end):
    """
    Find all Ugly numbers in a given range
    Time Complexity: O((end - start) * log n)
    Space Complexity: O(k) where k is the number of Ugly numbers
    """
    ugly_numbers = []
    
    for num in range(start, end + 1):
        if is_ugly_number(num):
            ugly_numbers.append(num)
    
    return ugly_numbers


# Problem 2: Find Sum of First N Odd Numbers
# Sum of first n odd numbers = n²
# Example: 1 + 3 + 5 + 7 = 16 = 4²

def sum_of_odd_numbers_iterative(n):
    """
    Find sum of first n odd numbers using iteration
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return 0
    
    total = 0
    odd = 1
    
    for i in range(n):
        total += odd
        odd += 2
    
    return total


def sum_of_odd_numbers_formula(n):
    """
    Find sum of first n odd numbers using formula
    Sum = n²
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if n <= 0:
        return 0
    return n * n


def sum_of_odd_numbers_recursive(n):
    """
    Find sum of first n odd numbers using recursion
    Time Complexity: O(n)
    Space Complexity: O(n) due to recursion stack
    """
    if n <= 0:
        return 0
    if n == 1:
        return 1
    
    # nth odd number = 2n - 1
    nth_odd = 2 * n - 1
    return nth_odd + sum_of_odd_numbers_recursive(n - 1)


def get_first_n_odd_numbers(n):
    """
    Get list of first n odd numbers
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    if n <= 0:
        return []
    
    odd_numbers = []
    odd = 1
    
    for i in range(n):
        odd_numbers.append(odd)
        odd += 2
    
    return odd_numbers


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if a Number is Ugly Number")
    print("=" * 60)
    
    # Test Case 1 - Ugly number 6
    num1 = 6
    result1 = is_ugly_number(num1)
    factors1 = get_ugly_factors(num1)
    print(f"Number: {num1}")
    if factors1:
        print(f"Prime factors: {factors1}")
    print(f"Is Ugly number: {result1}")
    
    # Test Case 2 - Ugly number 8
    num2 = 8
    result2 = is_ugly_number(num2)
    factors2 = get_ugly_factors(num2)
    print(f"\nNumber: {num2}")
    if factors2:
        print(f"Prime factors: {factors2}")
    print(f"Is Ugly number: {result2}")
    
    # Test Case 3 - Not Ugly number 14
    num3 = 14
    result3 = is_ugly_number(num3)
    factors3 = get_ugly_factors(num3)
    print(f"\nNumber: {num3}")
    if factors3:
        print(f"Prime factors: {factors3}")
    else:
        print("Has prime factors other than 2, 3, 5")
    print(f"Is Ugly number: {result3}")
    
    # Test Case 4 - Ugly number 1
    num4 = 1
    result4 = is_ugly_number(num4)
    print(f"\nNumber: {num4}")
    print(f"Is Ugly number: {result4}")
    
    # Test Case 5 - Find Ugly numbers in range
    start = 1
    end = 30
    ugly_nums = get_ugly_numbers_in_range(start, end)
    print(f"\nUgly numbers in range [{start}, {end}]:")
    print(ugly_nums)
    print(f"Count: {len(ugly_nums)}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Find Sum of First N Odd Numbers")
    print("=" * 60)
    
    # Test Case 1 - Sum of first 4 odd numbers
    n1 = 4
    result1_iter = sum_of_odd_numbers_iterative(n1)
    result1_formula = sum_of_odd_numbers_formula(n1)
    result1_rec = sum_of_odd_numbers_recursive(n1)
    odd_nums1 = get_first_n_odd_numbers(n1)
    print(f"n = {n1}")
    print(f"First {n1} odd numbers: {odd_nums1}")
    print(f"Sum (iterative): {result1_iter}")
    print(f"Sum (formula): {result1_formula}")
    print(f"Sum (recursive): {result1_rec}")
    print(f"Verification: {n1}² = {n1 * n1}")
    
    # Test Case 2 - Sum of first 10 odd numbers
    n2 = 10
    result2 = sum_of_odd_numbers_formula(n2)
    odd_nums2 = get_first_n_odd_numbers(n2)
    print(f"\nn = {n2}")
    print(f"First {n2} odd numbers: {odd_nums2}")
    print(f"Sum: {result2}")
    print(f"Verification: {n2}² = {n2 * n2}")
    
    # Test Case 3 - Sum of first 1 odd number
    n3 = 1
    result3 = sum_of_odd_numbers_formula(n3)
    print(f"\nn = {n3}")
    print(f"Sum: {result3}")
    
    # Test Case 4 - Sum of first 5 odd numbers
    n4 = 5
    result4 = sum_of_odd_numbers_formula(n4)
    odd_nums4 = get_first_n_odd_numbers(n4)
    print(f"\nn = {n4}")
    print(f"First {n4} odd numbers: {odd_nums4}")
    print(f"Sum: {result4}")
    
    # Test Case 5 - Large n
    n5 = 20
    result5 = sum_of_odd_numbers_formula(n5)
    print(f"\nn = {n5}")
    print(f"Sum of first {n5} odd numbers: {result5}")
    print(f"Verification: {n5}² = {n5 * n5}")
