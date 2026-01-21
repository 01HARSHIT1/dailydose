"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if a Number is Kaprekar Number
# A Kaprekar number is a number whose square, when split into two parts and added, gives the original number
# Example: 45² = 2025, split as 20 and 25, 20 + 25 = 45
# Example: 9² = 81, split as 8 and 1, 8 + 1 = 9

def count_digits(n):
    """
    Count number of digits in a number
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n == 0:
        return 1
    count = 0
    num = abs(n)
    while num > 0:
        count += 1
        num //= 10
    return count


def is_kaprekar_number(n):
    """
    Check if a number is Kaprekar number
    Time Complexity: O(log n²) = O(log n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return False
    if n == 1:
        return True  # 1² = 1, 0 + 1 = 1
    
    square = n * n
    num_digits = count_digits(square)
    
    # Try splitting at different positions
    for split_pos in range(1, num_digits):
        divisor = 10 ** split_pos
        
        # Split the square into two parts
        right_part = square % divisor
        left_part = square // divisor
        
        # Check if sum equals original number
        if left_part + right_part == n and right_part > 0:
            return True
    
    return False


def get_kaprekar_split(n):
    """
    Get the split of square that makes it Kaprekar number
    Returns tuple (left_part, right_part) if Kaprekar, None otherwise
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return None
    if n == 1:
        return (0, 1)
    
    square = n * n
    num_digits = count_digits(square)
    
    for split_pos in range(1, num_digits):
        divisor = 10 ** split_pos
        
        right_part = square % divisor
        left_part = square // divisor
        
        if left_part + right_part == n and right_part > 0:
            return (left_part, right_part)
    
    return None


def get_kaprekar_numbers_in_range(start, end):
    """
    Find all Kaprekar numbers in a given range
    Time Complexity: O((end - start) * log n)
    Space Complexity: O(k) where k is the number of Kaprekar numbers
    """
    kaprekar_numbers = []
    
    for num in range(start, end + 1):
        if is_kaprekar_number(num):
            kaprekar_numbers.append(num)
    
    return kaprekar_numbers


# Problem 2: Find nth Triangular Number
# A triangular number is the number of dots that can be arranged in an equilateral triangle
# Formula: T(n) = n(n+1)/2
# Example: T(4) = 1 + 2 + 3 + 4 = 10 (dots arranged in triangle)

def nth_triangular_number_formula(n):
    """
    Find nth triangular number using formula
    T(n) = n(n+1)/2
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if n < 0:
        raise ValueError("n must be non-negative")
    return n * (n + 1) // 2


def nth_triangular_number_iterative(n):
    """
    Find nth triangular number using iteration
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n < 0:
        raise ValueError("n must be non-negative")
    
    total = 0
    for i in range(1, n + 1):
        total += i
    return total


def nth_triangular_number_recursive(n):
    """
    Find nth triangular number using recursion
    Time Complexity: O(n)
    Space Complexity: O(n) due to recursion stack
    """
    if n < 0:
        raise ValueError("n must be non-negative")
    if n == 0:
        return 0
    return n + nth_triangular_number_recursive(n - 1)


def get_triangular_numbers_in_range(start, end):
    """
    Find all triangular numbers in a given range
    Time Complexity: O((end - start) * 1) = O(end - start) using formula
    Space Complexity: O(k) where k is the number of triangular numbers
    """
    triangular_numbers = []
    
    for num in range(start, end + 1):
        # Check if number is triangular by solving n(n+1)/2 = num
        # This gives us a quadratic equation: n² + n - 2*num = 0
        # n = (-1 + sqrt(1 + 8*num)) / 2
        import math
        discriminant = 1 + 8 * num
        if discriminant >= 0:
            n = (-1 + math.sqrt(discriminant)) / 2
            if n >= 0 and abs(n - round(n)) < 1e-9:
                triangular_numbers.append(num)
    
    return triangular_numbers


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if a Number is Kaprekar Number")
    print("=" * 60)
    
    # Test Case 1 - Kaprekar number 9
    num1 = 9
    result1 = is_kaprekar_number(num1)
    split1 = get_kaprekar_split(num1)
    square1 = num1 * num1
    print(f"Number: {num1}")
    print(f"Square: {square1}")
    if split1:
        print(f"Split: {split1[0]} + {split1[1]} = {split1[0] + split1[1]}")
    print(f"Is Kaprekar number: {result1}")
    
    # Test Case 2 - Kaprekar number 45
    num2 = 45
    result2 = is_kaprekar_number(num2)
    split2 = get_kaprekar_split(num2)
    square2 = num2 * num2
    print(f"\nNumber: {num2}")
    print(f"Square: {square2}")
    if split2:
        print(f"Split: {split2[0]} + {split2[1]} = {split2[0] + split2[1]}")
    print(f"Is Kaprekar number: {result2}")
    
    # Test Case 3 - Kaprekar number 55
    num3 = 55
    result3 = is_kaprekar_number(num3)
    split3 = get_kaprekar_split(num3)
    square3 = num3 * num3
    print(f"\nNumber: {num3}")
    print(f"Square: {square3}")
    if split3:
        print(f"Split: {split3[0]} + {split3[1]} = {split3[0] + split3[1]}")
    print(f"Is Kaprekar number: {result3}")
    
    # Test Case 4 - Not Kaprekar number
    num4 = 10
    result4 = is_kaprekar_number(num4)
    print(f"\nNumber: {num4}")
    print(f"Is Kaprekar number: {result4}")
    
    # Test Case 5 - Find Kaprekar numbers in range
    start = 1
    end = 100
    kaprekar_nums = get_kaprekar_numbers_in_range(start, end)
    print(f"\nKaprekar numbers in range [{start}, {end}]:")
    print(kaprekar_nums)
    print(f"Count: {len(kaprekar_nums)}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Find nth Triangular Number")
    print("=" * 60)
    
    # Test Case 1 - 4th triangular number
    n1 = 4
    result1_formula = nth_triangular_number_formula(n1)
    result1_iter = nth_triangular_number_iterative(n1)
    result1_rec = nth_triangular_number_recursive(n1)
    print(f"n = {n1}")
    print(f"Triangular number (formula): {result1_formula}")
    print(f"Triangular number (iterative): {result1_iter}")
    print(f"Triangular number (recursive): {result1_rec}")
    print(f"Pattern: 1 + 2 + 3 + 4 = {result1_formula}")
    
    # Test Case 2 - 10th triangular number
    n2 = 10
    result2 = nth_triangular_number_formula(n2)
    print(f"\nn = {n2}")
    print(f"10th triangular number: {result2}")
    
    # Test Case 3 - 0th triangular number
    n3 = 0
    result3 = nth_triangular_number_formula(n3)
    print(f"\nn = {n3}")
    print(f"0th triangular number: {result3}")
    
    # Test Case 4 - Large triangular number
    n4 = 100
    result4 = nth_triangular_number_formula(n4)
    print(f"\nn = {n4}")
    print(f"100th triangular number: {result4}")
    
    # Test Case 5 - Find triangular numbers in range
    start = 1
    end = 50
    triangular_nums = get_triangular_numbers_in_range(start, end)
    print(f"\nTriangular numbers in range [{start}, {end}]:")
    print(triangular_nums)
    print(f"Count: {len(triangular_nums)}")
