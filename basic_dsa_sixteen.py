"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if a Number is Perfect Number
# A perfect number is a positive integer that is equal to the sum of its proper divisors
# Example: 6 = 1 + 2 + 3, 28 = 1 + 2 + 4 + 7 + 14

def is_perfect_number(n):
    """
    Check if a number is perfect number
    Time Complexity: O(√n)
    Space Complexity: O(1)
    """
    if n <= 1:
        return False
    
    sum_divisors = 1  # 1 is always a divisor
    
    # Check divisors from 2 to √n
    i = 2
    while i * i <= n:
        if n % i == 0:
            sum_divisors += i
            # Add the corresponding divisor (avoid adding square twice)
            if i != n // i:
                sum_divisors += n // i
        i += 1
    
    return sum_divisors == n


def get_proper_divisors(n):
    """
    Get all proper divisors of a number (excluding the number itself)
    Time Complexity: O(√n)
    Space Complexity: O(√n)
    """
    if n <= 1:
        return []
    
    divisors = [1]
    i = 2
    
    while i * i <= n:
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n // i)
        i += 1
    
    divisors.sort()
    return divisors


# Problem 2: Find Sum of Squares of First N Natural Numbers
# Calculate 1² + 2² + 3² + ... + N²

def sum_of_squares_iterative(n):
    """
    Find sum of squares using iteration
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return 0
    
    total = 0
    for i in range(1, n + 1):
        total += i * i
    return total


def sum_of_squares_formula(n):
    """
    Find sum of squares using mathematical formula: n(n+1)(2n+1)/6
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if n <= 0:
        return 0
    return n * (n + 1) * (2 * n + 1) // 6


def sum_of_squares_recursive(n):
    """
    Find sum of squares using recursion
    Time Complexity: O(n)
    Space Complexity: O(n) due to recursion stack
    """
    if n <= 0:
        return 0
    if n == 1:
        return 1
    return n * n + sum_of_squares_recursive(n - 1)


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if a Number is Perfect Number")
    print("=" * 60)
    
    # Test Case 1 - Perfect number 6
    num1 = 6
    result1 = is_perfect_number(num1)
    divisors1 = get_proper_divisors(num1)
    print(f"Number: {num1}")
    print(f"Proper divisors: {divisors1}")
    print(f"Sum of divisors: {sum(divisors1)}")
    print(f"Is perfect number: {result1}")
    
    # Test Case 2 - Perfect number 28
    num2 = 28
    result2 = is_perfect_number(num2)
    divisors2 = get_proper_divisors(num2)
    print(f"\nNumber: {num2}")
    print(f"Proper divisors: {divisors2}")
    print(f"Sum of divisors: {sum(divisors2)}")
    print(f"Is perfect number: {result2}")
    
    # Test Case 3 - Not perfect number
    num3 = 10
    result3 = is_perfect_number(num3)
    divisors3 = get_proper_divisors(num3)
    print(f"\nNumber: {num3}")
    print(f"Proper divisors: {divisors3}")
    print(f"Sum of divisors: {sum(divisors3)}")
    print(f"Is perfect number: {result3}")
    
    # Test Case 4 - Perfect number 496
    num4 = 496
    result4 = is_perfect_number(num4)
    print(f"\nNumber: {num4}")
    print(f"Is perfect number: {result4}")
    
    # Test Case 5 - Not perfect number
    num5 = 1
    result5 = is_perfect_number(num5)
    print(f"\nNumber: {num5}")
    print(f"Is perfect number: {result5}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Find Sum of Squares of First N Natural Numbers")
    print("=" * 60)
    
    # Test Case 1
    n1 = 5
    result1_iter = sum_of_squares_iterative(n1)
    result1_formula = sum_of_squares_formula(n1)
    result1_rec = sum_of_squares_recursive(n1)
    print(f"N = {n1}")
    print(f"1² + 2² + 3² + 4² + 5² = {result1_iter}")
    print(f"Iterative method: {result1_iter}")
    print(f"Formula method: {result1_formula}")
    print(f"Recursive method: {result1_rec}")
    
    # Test Case 2
    n2 = 10
    result2 = sum_of_squares_formula(n2)
    print(f"\nN = {n2}")
    print(f"Sum of squares: {result2}")
    
    # Test Case 3
    n3 = 1
    result3 = sum_of_squares_formula(n3)
    print(f"\nN = {n3}")
    print(f"Sum of squares: {result3}")
    
    # Test Case 4
    n4 = 20
    result4 = sum_of_squares_formula(n4)
    print(f"\nN = {n4}")
    print(f"Sum of squares: {result4}")
    
    # Test Case 5 - Large number
    n5 = 100
    result5 = sum_of_squares_formula(n5)
    print(f"\nN = {n5}")
    print(f"Sum of squares: {result5}")
