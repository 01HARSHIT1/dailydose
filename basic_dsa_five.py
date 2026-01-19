"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Find Factorial of a Number
# Calculate factorial using both iterative and recursive approaches

def factorial_iterative(n):
    """
    Iterative approach to find factorial
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n < 0:
        return None  # Factorial is not defined for negative numbers
    
    result = 1
    for i in range(2, n + 1):
        result *= i
    return result


def factorial_recursive(n):
    """
    Recursive approach to find factorial
    Time Complexity: O(n)
    Space Complexity: O(n) due to recursion stack
    """
    if n < 0:
        return None  # Factorial is not defined for negative numbers
    if n == 0 or n == 1:
        return 1
    return n * factorial_recursive(n - 1)


# Problem 2: Check if a Number is Prime
# Determine whether a number is prime or not

def is_prime(n):
    """
    Check if a number is prime
    Time Complexity: O(√n)
    Space Complexity: O(1)
    """
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    
    # Check divisibility from 3 to √n
    i = 3
    while i * i <= n:
        if n % i == 0:
            return False
        i += 2  # Only check odd numbers
    
    return True


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Find Factorial of a Number")
    print("=" * 60)
    
    # Test Case 1
    num1 = 5
    fact_iter1 = factorial_iterative(num1)
    fact_rec1 = factorial_recursive(num1)
    print(f"Number: {num1}")
    print(f"Factorial (Iterative): {fact_iter1}")
    print(f"Factorial (Recursive): {fact_rec1}")
    
    # Test Case 2
    num2 = 0
    fact_iter2 = factorial_iterative(num2)
    fact_rec2 = factorial_recursive(num2)
    print(f"\nNumber: {num2}")
    print(f"Factorial (Iterative): {fact_iter2}")
    print(f"Factorial (Recursive): {fact_rec2}")
    
    # Test Case 3
    num3 = 1
    fact_iter3 = factorial_iterative(num3)
    fact_rec3 = factorial_recursive(num3)
    print(f"\nNumber: {num3}")
    print(f"Factorial (Iterative): {fact_iter3}")
    print(f"Factorial (Recursive): {fact_rec3}")
    
    # Test Case 4
    num4 = 7
    fact_iter4 = factorial_iterative(num4)
    fact_rec4 = factorial_recursive(num4)
    print(f"\nNumber: {num4}")
    print(f"Factorial (Iterative): {fact_iter4}")
    print(f"Factorial (Recursive): {fact_rec4}")
    
    # Test Case 5 - Negative number
    num5 = -5
    fact_iter5 = factorial_iterative(num5)
    fact_rec5 = factorial_recursive(num5)
    print(f"\nNumber: {num5}")
    print(f"Factorial (Iterative): {fact_iter5}")
    print(f"Factorial (Recursive): {fact_rec5}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Check if a Number is Prime")
    print("=" * 60)
    
    # Test Case 1 - Prime number
    num6 = 7
    result1 = is_prime(num6)
    print(f"Number: {num6}")
    print(f"Is Prime: {result1}")
    
    # Test Case 2 - Non-prime number
    num7 = 10
    result2 = is_prime(num7)
    print(f"\nNumber: {num7}")
    print(f"Is Prime: {result2}")
    
    # Test Case 3 - Smallest prime
    num8 = 2
    result3 = is_prime(num8)
    print(f"\nNumber: {num8}")
    print(f"Is Prime: {result3}")
    
    # Test Case 4 - Number less than 2
    num9 = 1
    result4 = is_prime(num9)
    print(f"\nNumber: {num9}")
    print(f"Is Prime: {result4}")
    
    # Test Case 5 - Large prime
    num10 = 17
    result5 = is_prime(num10)
    print(f"\nNumber: {num10}")
    print(f"Is Prime: {result5}")
    
    # Test Case 6 - Even number (except 2)
    num11 = 4
    result6 = is_prime(num11)
    print(f"\nNumber: {num11}")
    print(f"Is Prime: {result6}")
    
    # Test Case 7 - Large non-prime
    num12 = 100
    result7 = is_prime(num12)
    print(f"\nNumber: {num12}")
    print(f"Is Prime: {result7}")
    
    # Test Case 8 - Prime number
    num13 = 13
    result8 = is_prime(num13)
    print(f"\nNumber: {num13}")
    print(f"Is Prime: {result8}")
