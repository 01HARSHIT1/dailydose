"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if a Number is Happy Number
# A happy number is a number which eventually reaches 1 when replaced by the sum of the square of each digit
# Example: 19 is happy: 1² + 9² = 82, 8² + 2² = 68, 6² + 8² = 100, 1² + 0² + 0² = 1

def sum_of_squares_of_digits(n):
    """
    Calculate sum of squares of digits
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    total = 0
    num = abs(n)
    
    while num > 0:
        digit = num % 10
        total += digit * digit
        num //= 10
    
    return total


def is_happy_number(n):
    """
    Check if a number is Happy number
    A happy number eventually reaches 1 when repeatedly replaced by sum of squares of digits
    Time Complexity: O(log n) per iteration, but can be O(k) where k is cycle length
    Space Complexity: O(k) where k is the number of distinct values in cycle
    """
    if n <= 0:
        return False
    
    seen = set()
    current = n
    
    while current != 1 and current not in seen:
        seen.add(current)
        current = sum_of_squares_of_digits(current)
    
    return current == 1


def get_happy_sequence(n):
    """
    Get the sequence of numbers until it reaches 1 or detects a cycle
    Time Complexity: O(k) where k is the length of sequence
    Space Complexity: O(k)
    """
    if n <= 0:
        return []
    
    sequence = [n]
    seen = set()
    current = n
    
    while current != 1 and current not in seen:
        seen.add(current)
        current = sum_of_squares_of_digits(current)
        sequence.append(current)
    
    return sequence


def get_happy_numbers_in_range(start, end):
    """
    Find all Happy numbers in a given range
    Time Complexity: O((end - start) * k) where k is average cycle length
    Space Complexity: O(m) where m is the number of Happy numbers
    """
    happy_numbers = []
    
    for num in range(start, end + 1):
        if is_happy_number(num):
            happy_numbers.append(num)
    
    return happy_numbers


# Problem 2: Find nth Fibonacci Number
# Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21, ...
# F(0) = 0, F(1) = 1, F(n) = F(n-1) + F(n-2)

def nth_fibonacci_iterative(n):
    """
    Find nth Fibonacci number using iteration
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n < 0:
        raise ValueError("n must be non-negative")
    if n == 0:
        return 0
    if n == 1:
        return 1
    
    a, b = 0, 1
    for i in range(2, n + 1):
        a, b = b, a + b
    
    return b


def nth_fibonacci_recursive(n):
    """
    Find nth Fibonacci number using recursion
    Time Complexity: O(2^n) - exponential
    Space Complexity: O(n) due to recursion stack
    """
    if n < 0:
        raise ValueError("n must be non-negative")
    if n <= 1:
        return n
    
    return nth_fibonacci_recursive(n - 1) + nth_fibonacci_recursive(n - 2)


def nth_fibonacci_memoization(n, memo=None):
    """
    Find nth Fibonacci number using memoization (top-down DP)
    Time Complexity: O(n)
    Space Complexity: O(n)
    """
    if memo is None:
        memo = {}
    
    if n < 0:
        raise ValueError("n must be non-negative")
    if n <= 1:
        return n
    
    if n in memo:
        return memo[n]
    
    memo[n] = nth_fibonacci_memoization(n - 1, memo) + nth_fibonacci_memoization(n - 2, memo)
    return memo[n]


def nth_fibonacci_formula(n):
    """
    Find nth Fibonacci number using Binet's formula
    F(n) = (φ^n - ψ^n) / √5, where φ = (1+√5)/2 and ψ = (1-√5)/2
    Time Complexity: O(1) (but limited by floating point precision)
    Space Complexity: O(1)
    """
    if n < 0:
        raise ValueError("n must be non-negative")
    if n <= 1:
        return n
    
    import math
    sqrt5 = math.sqrt(5)
    phi = (1 + sqrt5) / 2
    psi = (1 - sqrt5) / 2
    
    return round((phi ** n - psi ** n) / sqrt5)


def nth_fibonacci_matrix(n):
    """
    Find nth Fibonacci number using matrix exponentiation
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n < 0:
        raise ValueError("n must be non-negative")
    if n <= 1:
        return n
    
    def matrix_multiply(A, B):
        """Multiply two 2x2 matrices"""
        return [
            [A[0][0] * B[0][0] + A[0][1] * B[1][0], A[0][0] * B[0][1] + A[0][1] * B[1][1]],
            [A[1][0] * B[0][0] + A[1][1] * B[1][0], A[1][0] * B[0][1] + A[1][1] * B[1][1]]
        ]
    
    def matrix_power(matrix, power):
        """Raise matrix to power using binary exponentiation"""
        if power == 1:
            return matrix
        
        if power % 2 == 0:
            half = matrix_power(matrix, power // 2)
            return matrix_multiply(half, half)
        else:
            return matrix_multiply(matrix, matrix_power(matrix, power - 1))
    
    # Fibonacci matrix: [[1, 1], [1, 0]]
    fib_matrix = [[1, 1], [1, 0]]
    result_matrix = matrix_power(fib_matrix, n)
    
    return result_matrix[0][1]


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if a Number is Happy Number")
    print("=" * 60)
    
    # Test Case 1 - Happy number 19
    num1 = 19
    result1 = is_happy_number(num1)
    sequence1 = get_happy_sequence(num1)
    print(f"Number: {num1}")
    print(f"Sequence: {sequence1}")
    print(f"Is Happy number: {result1}")
    
    # Test Case 2 - Happy number 7
    num2 = 7
    result2 = is_happy_number(num2)
    sequence2 = get_happy_sequence(num2)
    print(f"\nNumber: {num2}")
    print(f"Sequence: {sequence2}")
    print(f"Is Happy number: {result2}")
    
    # Test Case 3 - Not Happy number 4
    num3 = 4
    result3 = is_happy_number(num3)
    sequence3 = get_happy_sequence(num3)
    print(f"\nNumber: {num3}")
    print(f"Sequence: {sequence3}")
    print(f"Is Happy number: {result3}")
    
    # Test Case 4 - Single digit happy
    num4 = 1
    result4 = is_happy_number(num4)
    sequence4 = get_happy_sequence(num4)
    print(f"\nNumber: {num4}")
    print(f"Sequence: {sequence4}")
    print(f"Is Happy number: {result4}")
    
    # Test Case 5 - Find Happy numbers in range
    start = 1
    end = 50
    happy_nums = get_happy_numbers_in_range(start, end)
    print(f"\nHappy numbers in range [{start}, {end}]:")
    print(happy_nums)
    print(f"Count: {len(happy_nums)}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Find nth Fibonacci Number")
    print("=" * 60)
    
    # Test Case 1 - 10th Fibonacci number
    n1 = 10
    result1_iter = nth_fibonacci_iterative(n1)
    result1_memo = nth_fibonacci_memoization(n1)
    result1_formula = nth_fibonacci_formula(n1)
    result1_matrix = nth_fibonacci_matrix(n1)
    print(f"n = {n1}")
    print(f"Fibonacci (iterative): {result1_iter}")
    print(f"Fibonacci (memoization): {result1_memo}")
    print(f"Fibonacci (formula): {result1_formula}")
    print(f"Fibonacci (matrix): {result1_matrix}")
    
    # Test Case 2 - 5th Fibonacci number
    n2 = 5
    result2_iter = nth_fibonacci_iterative(n2)
    result2_rec = nth_fibonacci_recursive(n2)
    print(f"\nn = {n2}")
    print(f"Fibonacci (iterative): {result2_iter}")
    print(f"Fibonacci (recursive): {result2_rec}")
    
    # Test Case 3 - 0th Fibonacci number
    n3 = 0
    result3 = nth_fibonacci_iterative(n3)
    print(f"\nn = {n3}")
    print(f"Fibonacci: {result3}")
    
    # Test Case 4 - 1st Fibonacci number
    n4 = 1
    result4 = nth_fibonacci_iterative(n4)
    print(f"\nn = {n4}")
    print(f"Fibonacci: {result4}")
    
    # Test Case 5 - Larger Fibonacci number
    n5 = 20
    result5_iter = nth_fibonacci_iterative(n5)
    result5_matrix = nth_fibonacci_matrix(n5)
    print(f"\nn = {n5}")
    print(f"Fibonacci (iterative): {result5_iter}")
    print(f"Fibonacci (matrix): {result5_matrix}")
