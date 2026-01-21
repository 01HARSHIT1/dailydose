"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if a Number is Strong Number
# A strong number is a number whose sum of factorial of digits equals the number itself
# Example: 145 = 1! + 4! + 5! = 1 + 24 + 120 = 145

def factorial(n):
    """
    Calculate factorial of a number
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n <= 1:
        return 1
    result = 1
    for i in range(2, n + 1):
        result *= i
    return result


def is_strong_number(n):
    """
    Check if a number is strong number
    Time Complexity: O(d * k) where d is number of digits, k is average digit value
    Space Complexity: O(1)
    """
    if n <= 0:
        return False
    
    original = n
    sum_factorial = 0
    
    while n > 0:
        digit = n % 10
        sum_factorial += factorial(digit)
        n //= 10
    
    return sum_factorial == original


def get_digit_factorials(n):
    """
    Get list of factorials of each digit
    Time Complexity: O(d * k) where d is number of digits
    Space Complexity: O(d)
    """
    if n <= 0:
        return []
    
    factorials = []
    temp = n
    
    while temp > 0:
        digit = temp % 10
        factorials.insert(0, factorial(digit))
        temp //= 10
    
    return factorials


# Problem 2: Convert Binary to Decimal
# Convert a binary number to its decimal representation

def binary_to_decimal_iterative(binary_str):
    """
    Convert binary string to decimal using iteration
    Time Complexity: O(n) where n is length of binary string
    Space Complexity: O(1)
    """
    if not binary_str or binary_str == "0":
        return 0
    
    is_negative = binary_str[0] == '-'
    start = 1 if is_negative else 0
    
    decimal = 0
    power = 0
    
    # Process from right to left (least significant bit to most)
    for i in range(len(binary_str) - 1, start - 1, -1):
        if binary_str[i] == '1':
            decimal += 2 ** power
        elif binary_str[i] != '0':
            raise ValueError(f"Invalid binary digit: {binary_str[i]}")
        power += 1
    
    return -decimal if is_negative else decimal


def binary_to_decimal_recursive(binary_str):
    """
    Convert binary string to decimal using recursion
    Time Complexity: O(n) where n is length of binary string
    Space Complexity: O(n) due to recursion stack
    """
    def helper(binary, index, power):
        if index < 0 or (index == 0 and binary[0] == '-'):
            return 0
        if binary[index] == '1':
            return (2 ** power) + helper(binary, index - 1, power + 1)
        elif binary[index] == '0':
            return helper(binary, index - 1, power + 1)
        else:
            raise ValueError(f"Invalid binary digit: {binary[index]}")
    
    if not binary_str or binary_str == "0":
        return 0
    
    is_negative = binary_str[0] == '-'
    start = len(binary_str) - 1
    
    result = helper(binary_str, start, 0)
    return -result if is_negative else result


def binary_to_decimal_builtin(binary_str):
    """
    Convert binary string to decimal using built-in function
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not binary_str:
        return 0
    
    is_negative = binary_str[0] == '-'
    binary = binary_str[1:] if is_negative else binary_str
    
    decimal = int(binary, 2)
    return -decimal if is_negative else decimal


def binary_array_to_decimal(binary_array):
    """
    Convert binary array to decimal
    Time Complexity: O(n) where n is length of array
    Space Complexity: O(1)
    """
    if not binary_array:
        return 0
    
    decimal = 0
    power = len(binary_array) - 1
    
    for digit in binary_array:
        if digit != 0 and digit != 1:
            raise ValueError(f"Invalid binary digit: {digit}")
        decimal += digit * (2 ** power)
        power -= 1
    
    return decimal


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if a Number is Strong Number")
    print("=" * 60)
    
    # Test Case 1 - Strong number 145
    num1 = 145
    result1 = is_strong_number(num1)
    factorials1 = get_digit_factorials(num1)
    print(f"Number: {num1}")
    print(f"Digit factorials: {factorials1}")
    print(f"Sum of factorials: {sum(factorials1)}")
    print(f"Is strong number: {result1}")
    
    # Test Case 2 - Not strong number
    num2 = 123
    result2 = is_strong_number(num2)
    factorials2 = get_digit_factorials(num2)
    print(f"\nNumber: {num2}")
    print(f"Digit factorials: {factorials2}")
    print(f"Sum of factorials: {sum(factorials2)}")
    print(f"Is strong number: {result2}")
    
    # Test Case 3 - Strong number 1
    num3 = 1
    result3 = is_strong_number(num3)
    print(f"\nNumber: {num3}")
    print(f"Is strong number: {result3}")
    
    # Test Case 4 - Strong number 2
    num4 = 2
    result4 = is_strong_number(num4)
    print(f"\nNumber: {num4}")
    print(f"Is strong number: {result4}")
    
    # Test Case 5 - Not strong number
    num5 = 10
    result5 = is_strong_number(num5)
    factorials5 = get_digit_factorials(num5)
    print(f"\nNumber: {num5}")
    print(f"Digit factorials: {factorials5}")
    print(f"Sum of factorials: {sum(factorials5)}")
    print(f"Is strong number: {result5}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Convert Binary to Decimal")
    print("=" * 60)
    
    # Test Case 1 - Basic binary
    binary1 = "1010"
    result1_iter = binary_to_decimal_iterative(binary1)
    result1_rec = binary_to_decimal_recursive(binary1)
    result1_builtin = binary_to_decimal_builtin(binary1)
    print(f"Binary: {binary1}")
    print(f"Decimal (iterative): {result1_iter}")
    print(f"Decimal (recursive): {result1_rec}")
    print(f"Decimal (built-in): {result1_builtin}")
    
    # Test Case 2 - Zero
    binary2 = "0"
    result2 = binary_to_decimal_iterative(binary2)
    print(f"\nBinary: {binary2}")
    print(f"Decimal: {result2}")
    
    # Test Case 3 - Large binary
    binary3 = "11111111"
    result3 = binary_to_decimal_iterative(binary3)
    print(f"\nBinary: {binary3}")
    print(f"Decimal: {result3}")
    
    # Test Case 4 - Binary array
    binary4 = [1, 0, 1, 1, 0, 1]
    result4 = binary_array_to_decimal(binary4)
    print(f"\nBinary (array): {binary4}")
    print(f"Decimal: {result4}")
    
    # Test Case 5 - Single bit
    binary5 = "1"
    result5 = binary_to_decimal_iterative(binary5)
    print(f"\nBinary: {binary5}")
    print(f"Decimal: {result5}")
