"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if a Number is Spy Number
# A Spy number is a number where the sum of its digits equals the product of its digits
# Example: 1124 = 1+1+2+4 = 8 and 1*1*2*4 = 8, so 1124 is a Spy number

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


def product_of_digits(n):
    """
    Calculate product of digits of a number
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    product = 1
    num = abs(n)
    
    # Handle case where number contains 0
    while num > 0:
        digit = num % 10
        product *= digit
        num //= 10
    
    return product


def is_spy_number(n):
    """
    Check if a number is Spy number
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return False
    
    return sum_of_digits(n) == product_of_digits(n)


def get_spy_numbers_in_range(start, end):
    """
    Find all Spy numbers in a given range
    Time Complexity: O((end - start) * log n)
    Space Complexity: O(k) where k is the number of Spy numbers
    """
    spy_numbers = []
    
    for num in range(start, end + 1):
        if is_spy_number(num):
            spy_numbers.append(num)
    
    return spy_numbers


# Problem 2: Convert Hexadecimal to Decimal
# Convert a hexadecimal (base 16) number to its decimal representation

def hexadecimal_to_decimal_iterative(hex_str):
    """
    Convert hexadecimal string to decimal using iteration
    Time Complexity: O(n) where n is length of hex string
    Space Complexity: O(1)
    """
    if not hex_str or hex_str == "0":
        return 0
    
    hex_digits = "0123456789ABCDEF"
    is_negative = hex_str[0] == '-'
    start = 1 if is_negative else 0
    
    decimal = 0
    power = 0
    
    # Process from right to left
    for i in range(len(hex_str) - 1, start - 1, -1):
        char = hex_str[i].upper()
        if char in hex_digits:
            digit_value = hex_digits.index(char)
            decimal += digit_value * (16 ** power)
            power += 1
        else:
            raise ValueError(f"Invalid hexadecimal digit: {char}")
    
    return -decimal if is_negative else decimal


def hexadecimal_to_decimal_recursive(hex_str):
    """
    Convert hexadecimal string to decimal using recursion
    Time Complexity: O(n) where n is length of hex string
    Space Complexity: O(n) due to recursion stack
    """
    hex_digits = "0123456789ABCDEF"
    
    def helper(hex_str, index, power):
        if index < 0 or (index == 0 and hex_str[0] == '-'):
            return 0
        char = hex_str[index].upper()
        if char not in hex_digits:
            raise ValueError(f"Invalid hexadecimal digit: {char}")
        digit_value = hex_digits.index(char)
        return digit_value * (16 ** power) + helper(hex_str, index - 1, power + 1)
    
    if not hex_str or hex_str == "0":
        return 0
    
    is_negative = hex_str[0] == '-'
    start = len(hex_str) - 1
    
    result = helper(hex_str, start, 0)
    return -result if is_negative else result


def hexadecimal_to_decimal_builtin(hex_str):
    """
    Convert hexadecimal string to decimal using built-in function
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not hex_str:
        return 0
    
    is_negative = hex_str[0] == '-'
    hex = hex_str[1:] if is_negative else hex_str
    
    decimal = int(hex, 16)
    return -decimal if is_negative else decimal


def hexadecimal_array_to_decimal(hex_array):
    """
    Convert hexadecimal array (list of characters) to decimal
    Time Complexity: O(n) where n is length of array
    Space Complexity: O(1)
    """
    if not hex_array:
        return 0
    
    hex_digits = "0123456789ABCDEF"
    decimal = 0
    power = len(hex_array) - 1
    
    for char in hex_array:
        char_upper = char.upper()
        if char_upper in hex_digits:
            digit_value = hex_digits.index(char_upper)
            decimal += digit_value * (16 ** power)
            power -= 1
        else:
            raise ValueError(f"Invalid hexadecimal digit: {char}")
    
    return decimal


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if a Number is Spy Number")
    print("=" * 60)
    
    # Test Case 1 - Spy number 1124
    num1 = 1124
    result1 = is_spy_number(num1)
    sum1 = sum_of_digits(num1)
    product1 = product_of_digits(num1)
    print(f"Number: {num1}")
    print(f"Sum of digits: {sum1}")
    print(f"Product of digits: {product1}")
    print(f"Is Spy number: {result1}")
    
    # Test Case 2 - Spy number 22
    num2 = 22
    result2 = is_spy_number(num2)
    sum2 = sum_of_digits(num2)
    product2 = product_of_digits(num2)
    print(f"\nNumber: {num2}")
    print(f"Sum of digits: {sum2}")
    print(f"Product of digits: {product2}")
    print(f"Is Spy number: {result2}")
    
    # Test Case 3 - Not Spy number
    num3 = 123
    result3 = is_spy_number(num3)
    sum3 = sum_of_digits(num3)
    product3 = product_of_digits(num3)
    print(f"\nNumber: {num3}")
    print(f"Sum of digits: {sum3}")
    print(f"Product of digits: {product3}")
    print(f"Is Spy number: {result3}")
    
    # Test Case 4 - Single digit (always Spy)
    num4 = 1
    result4 = is_spy_number(num4)
    print(f"\nNumber: {num4}")
    print(f"Is Spy number: {result4}")
    
    # Test Case 5 - Find Spy numbers in range
    start = 1
    end = 2000
    spy_nums = get_spy_numbers_in_range(start, end)
    print(f"\nSpy numbers in range [{start}, {end}]:")
    print(spy_nums[:20])  # Print first 20
    print(f"Total count: {len(spy_nums)}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Convert Hexadecimal to Decimal")
    print("=" * 60)
    
    # Test Case 1 - Basic hexadecimal
    hex1 = "FF"
    result1_iter = hexadecimal_to_decimal_iterative(hex1)
    result1_rec = hexadecimal_to_decimal_recursive(hex1)
    result1_builtin = hexadecimal_to_decimal_builtin(hex1)
    print(f"Hexadecimal: {hex1}")
    print(f"Decimal (iterative): {result1_iter}")
    print(f"Decimal (recursive): {result1_rec}")
    print(f"Decimal (built-in): {result1_builtin}")
    
    # Test Case 2 - Zero
    hex2 = "0"
    result2 = hexadecimal_to_decimal_iterative(hex2)
    print(f"\nHexadecimal: {hex2}")
    print(f"Decimal: {result2}")
    
    # Test Case 3 - Large hexadecimal
    hex3 = "ABCD"
    result3 = hexadecimal_to_decimal_iterative(hex3)
    print(f"\nHexadecimal: {hex3}")
    print(f"Decimal: {result3}")
    
    # Test Case 4 - Hexadecimal array
    hex4 = ['1', 'A', 'F']
    result4 = hexadecimal_array_to_decimal(hex4)
    print(f"\nHexadecimal (array): {hex4}")
    print(f"Decimal: {result4}")
    
    # Test Case 5 - Lowercase hexadecimal
    hex5 = "abc"
    result5 = hexadecimal_to_decimal_iterative(hex5)
    print(f"\nHexadecimal: {hex5}")
    print(f"Decimal: {result5}")
