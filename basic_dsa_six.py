"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Fibonacci Sequence
# Generate Fibonacci sequence using both iterative and recursive approaches

def fibonacci_iterative(n):
    """
    Generate first n Fibonacci numbers using iterative approach
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return []
    if n == 1:
        return [0]
    if n == 2:
        return [0, 1]
    
    fib = [0, 1]
    for i in range(2, n):
        fib.append(fib[i - 1] + fib[i - 2])
    
    return fib


def fibonacci_recursive(n):
    """
    Get nth Fibonacci number using recursive approach
    Time Complexity: O(2^n) - exponential (can be optimized with memoization)
    Space Complexity: O(n) due to recursion stack
    """
    if n <= 0:
        return None
    if n == 1:
        return 0
    if n == 2:
        return 1
    
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2)


def fibonacci_nth_iterative(n):
    """
    Get nth Fibonacci number using iterative approach (optimized)
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return None
    if n == 1:
        return 0
    if n == 2:
        return 1
    
    a, b = 0, 1
    for _ in range(2, n):
        a, b = b, a + b
    
    return b


# Problem 2: Check if a Number is Palindrome
# Determine whether a number reads the same forwards and backwards

def is_palindrome_number(n):
    """
    Check if a number is palindrome
    Time Complexity: O(log n) where log is base 10
    Space Complexity: O(1)
    """
    if n < 0:
        return False  # Negative numbers are not palindromes
    if n < 10:
        return True  # Single digit numbers are palindromes
    
    original = n
    reversed_num = 0
    
    while n > 0:
        reversed_num = reversed_num * 10 + n % 10
        n //= 10
    
    return original == reversed_num


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Fibonacci Sequence")
    print("=" * 60)
    
    # Test Case 1 - First 10 Fibonacci numbers
    n1 = 10
    fib1 = fibonacci_iterative(n1)
    print(f"First {n1} Fibonacci numbers (Iterative): {fib1}")
    
    # Test Case 2 - First 5 Fibonacci numbers
    n2 = 5
    fib2 = fibonacci_iterative(n2)
    print(f"\nFirst {n2} Fibonacci numbers (Iterative): {fib2}")
    
    # Test Case 3 - 7th Fibonacci number (iterative optimized)
    n3 = 7
    fib_nth1 = fibonacci_nth_iterative(n3)
    print(f"\n{n3}th Fibonacci number (Iterative): {fib_nth1}")
    
    # Test Case 4 - 7th Fibonacci number (recursive)
    fib_nth2 = fibonacci_recursive(n3)
    print(f"{n3}th Fibonacci number (Recursive): {fib_nth2}")
    
    # Test Case 5 - Edge cases
    print(f"\n1st Fibonacci number: {fibonacci_nth_iterative(1)}")
    print(f"2nd Fibonacci number: {fibonacci_nth_iterative(2)}")
    print(f"3rd Fibonacci number: {fibonacci_nth_iterative(3)}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Check if a Number is Palindrome")
    print("=" * 60)
    
    # Test Case 1 - Palindrome number
    num1 = 121
    result1 = is_palindrome_number(num1)
    print(f"Number: {num1}")
    print(f"Is Palindrome: {result1}")
    
    # Test Case 2 - Non-palindrome number
    num2 = 123
    result2 = is_palindrome_number(num2)
    print(f"\nNumber: {num2}")
    print(f"Is Palindrome: {result2}")
    
    # Test Case 3 - Single digit
    num3 = 5
    result3 = is_palindrome_number(num3)
    print(f"\nNumber: {num3}")
    print(f"Is Palindrome: {result3}")
    
    # Test Case 4 - Palindrome with even digits
    num4 = 1221
    result4 = is_palindrome_number(num4)
    print(f"\nNumber: {num4}")
    print(f"Is Palindrome: {result4}")
    
    # Test Case 5 - Large palindrome
    num5 = 12321
    result5 = is_palindrome_number(num5)
    print(f"\nNumber: {num5}")
    print(f"Is Palindrome: {result5}")
    
    # Test Case 6 - Negative number
    num6 = -121
    result6 = is_palindrome_number(num6)
    print(f"\nNumber: {num6}")
    print(f"Is Palindrome: {result6}")
    
    # Test Case 7 - Number with zeros
    num7 = 1001
    result7 = is_palindrome_number(num7)
    print(f"\nNumber: {num7}")
    print(f"Is Palindrome: {result7}")
    
    # Test Case 8 - Non-palindrome
    num8 = 12345
    result8 = is_palindrome_number(num8)
    print(f"\nNumber: {num8}")
    print(f"Is Palindrome: {result8}")
