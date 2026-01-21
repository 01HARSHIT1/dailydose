"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if a Number is Duck Number
# A Duck number is a number that contains at least one zero, but should not start with zero
# Example: 102, 1020 are Duck numbers, but 012, 0123 are not

def is_duck_number(n):
    """
    Check if a number is Duck number
    A Duck number contains at least one zero but doesn't start with zero
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return False
    
    num_str = str(n)
    
    # Check if it starts with zero
    if num_str[0] == '0':
        return False
    
    # Check if it contains at least one zero
    return '0' in num_str


def is_duck_number_iterative(n):
    """
    Check if a number is Duck number using iterative approach
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return False
    
    has_zero = False
    first_digit = True
    
    while n > 0:
        digit = n % 10
        if digit == 0:
            has_zero = True
        n //= 10
        first_digit = False
    
    return has_zero


def get_duck_numbers_in_range(start, end):
    """
    Find all Duck numbers in a given range
    Time Complexity: O((end - start) * log n)
    Space Complexity: O(k) where k is the number of Duck numbers
    """
    duck_numbers = []
    
    for num in range(start, end + 1):
        if is_duck_number(num):
            duck_numbers.append(num)
    
    return duck_numbers


# Problem 2: Check if a Number is Neon Number
# A Neon number is a number where the sum of digits of the square of the number equals the number itself
# Example: 9² = 81, and 8 + 1 = 9, so 9 is a Neon number

def sum_of_digits(n):
    """
    Calculate sum of digits of a number
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    total = 0
    num = abs(n)
    
    while num > 0:
        total += num % 10
        num //= 10
    
    return total


def is_neon_number(n):
    """
    Check if a number is Neon number
    Sum of digits of square equals the number itself
    Time Complexity: O(log n²) = O(log n) (assuming log n² ≈ 2*log n)
    Space Complexity: O(1)
    """
    if n < 0:
        return False
    
    square = n * n
    sum_of_square_digits = sum_of_digits(square)
    
    return sum_of_square_digits == n


def get_neon_numbers_in_range(start, end):
    """
    Find all Neon numbers in a given range
    Time Complexity: O((end - start) * log n)
    Space Complexity: O(k) where k is the number of Neon numbers
    """
    neon_numbers = []
    
    for num in range(start, end + 1):
        if is_neon_number(num):
            neon_numbers.append(num)
    
    return neon_numbers


def get_square_digits_sum(n):
    """
    Get the sum of digits of square of a number
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    square = n * n
    return sum_of_digits(square)


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if a Number is Duck Number")
    print("=" * 60)
    
    # Test Case 1 - Duck number 102
    num1 = 102
    result1 = is_duck_number(num1)
    result1_iter = is_duck_number_iterative(num1)
    print(f"Number: {num1}")
    print(f"Is Duck number: {result1}")
    print(f"Is Duck number (iterative): {result1_iter}")
    
    # Test Case 2 - Duck number 1020
    num2 = 1020
    result2 = is_duck_number(num2)
    print(f"\nNumber: {num2}")
    print(f"Is Duck number: {result2}")
    
    # Test Case 3 - Not Duck number (no zero)
    num3 = 123
    result3 = is_duck_number(num3)
    print(f"\nNumber: {num3}")
    print(f"Is Duck number: {result3}")
    
    # Test Case 4 - Single digit (not Duck as no zero)
    num4 = 5
    result4 = is_duck_number(num4)
    print(f"\nNumber: {num4}")
    print(f"Is Duck number: {result4}")
    
    # Test Case 5 - Find Duck numbers in range
    start = 100
    end = 200
    duck_nums = get_duck_numbers_in_range(start, end)
    print(f"\nDuck numbers in range [{start}, {end}]:")
    print(duck_nums[:15])  # Print first 15
    print(f"Total count: {len(duck_nums)}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Check if a Number is Neon Number")
    print("=" * 60)
    
    # Test Case 1 - Neon number 9
    num1 = 9
    result1 = is_neon_number(num1)
    square1 = num1 * num1
    sum1 = get_square_digits_sum(num1)
    print(f"Number: {num1}")
    print(f"Square: {square1}")
    print(f"Sum of digits of square: {sum1}")
    print(f"Is Neon number: {result1}")
    
    # Test Case 2 - Not Neon number
    num2 = 12
    result2 = is_neon_number(num2)
    square2 = num2 * num2
    sum2 = get_square_digits_sum(num2)
    print(f"\nNumber: {num2}")
    print(f"Square: {square2}")
    print(f"Sum of digits of square: {sum2}")
    print(f"Is Neon number: {result2}")
    
    # Test Case 3 - Single digit Neon
    num3 = 1
    result3 = is_neon_number(num3)
    square3 = num3 * num3
    sum3 = get_square_digits_sum(num3)
    print(f"\nNumber: {num3}")
    print(f"Square: {square3}")
    print(f"Sum of digits of square: {sum3}")
    print(f"Is Neon number: {result3}")
    
    # Test Case 4 - Zero
    num4 = 0
    result4 = is_neon_number(num4)
    print(f"\nNumber: {num4}")
    print(f"Is Neon number: {result4}")
    
    # Test Case 5 - Find Neon numbers in range
    start = 0
    end = 1000
    neon_nums = get_neon_numbers_in_range(start, end)
    print(f"\nNeon numbers in range [{start}, {end}]:")
    print(neon_nums)
    print(f"Count: {len(neon_nums)}")
