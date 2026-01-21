"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if a Number is Automorphic
# An automorphic number is a number whose square ends with the number itself
# Example: 5² = 25 (ends with 5), 6² = 36 (ends with 6), 25² = 625 (ends with 25)

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


def is_automorphic_number(n):
    """
    Check if a number is automorphic number
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n < 0:
        return False
    
    square = n * n
    num_digits = count_digits(n)
    
    # Extract last num_digits from square
    divisor = 10 ** num_digits
    last_digits = square % divisor
    
    return last_digits == n


def get_automorphic_numbers_in_range(start, end):
    """
    Find all automorphic numbers in a given range
    Time Complexity: O((end - start) * log n)
    Space Complexity: O(k) where k is the number of automorphic numbers
    """
    automorphic_numbers = []
    
    for num in range(start, end + 1):
        if is_automorphic_number(num):
            automorphic_numbers.append(num)
    
    return automorphic_numbers


# Problem 2: Convert Decimal to Hexadecimal
# Convert a decimal number to its hexadecimal (base 16) representation

def decimal_to_hexadecimal_iterative(n):
    """
    Convert decimal to hexadecimal using iteration
    Time Complexity: O(log n)
    Space Complexity: O(log n)
    """
    if n == 0:
        return "0"
    
    hex_digits = "0123456789ABCDEF"
    hexadecimal = ""
    num = abs(n)
    
    while num > 0:
        hexadecimal = hex_digits[num % 16] + hexadecimal
        num //= 16
    
    return hexadecimal if n >= 0 else "-" + hexadecimal


def decimal_to_hexadecimal_recursive(n):
    """
    Convert decimal to hexadecimal using recursion
    Time Complexity: O(log n)
    Space Complexity: O(log n) due to recursion stack
    """
    hex_digits = "0123456789ABCDEF"
    
    if n == 0:
        return "0"
    if abs(n) < 16:
        result = hex_digits[abs(n)]
        return result if n >= 0 else "-" + result
    if n < 0:
        return "-" + decimal_to_hexadecimal_recursive(-n)
    
    return decimal_to_hexadecimal_recursive(n // 16) + hex_digits[n % 16]


def decimal_to_hexadecimal_builtin(n):
    """
    Convert decimal to hexadecimal using built-in function
    Time Complexity: O(log n)
    Space Complexity: O(log n)
    """
    return hex(n) if n >= 0 else "-" + hex(-n)[2:]


def decimal_to_hexadecimal_list(n):
    """
    Convert decimal to hexadecimal and return as list of characters
    Time Complexity: O(log n)
    Space Complexity: O(log n)
    """
    hex_digits = "0123456789ABCDEF"
    if n == 0:
        return ['0']
    
    hex_list = []
    num = abs(n)
    
    while num > 0:
        hex_list.insert(0, hex_digits[num % 16])
        num //= 16
    
    return hex_list if n >= 0 else ['-'] + hex_list


def hexadecimal_to_decimal(hex_str):
    """
    Convert hexadecimal string back to decimal (helper function)
    Time Complexity: O(n) where n is length of hex string
    Space Complexity: O(1)
    """
    if not hex_str or hex_str == "0":
        return 0
    
    is_negative = hex_str[0] == '-'
    start = 1 if is_negative else 0
    
    decimal = 0
    power = 0
    hex_digits = "0123456789ABCDEF"
    
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


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if a Number is Automorphic")
    print("=" * 60)
    
    # Test Case 1 - Automorphic number 5
    num1 = 5
    result1 = is_automorphic_number(num1)
    square1 = num1 * num1
    print(f"Number: {num1}")
    print(f"Square: {square1}")
    print(f"Is automorphic: {result1}")
    
    # Test Case 2 - Automorphic number 6
    num2 = 6
    result2 = is_automorphic_number(num2)
    square2 = num2 * num2
    print(f"\nNumber: {num2}")
    print(f"Square: {square2}")
    print(f"Is automorphic: {result2}")
    
    # Test Case 3 - Automorphic number 25
    num3 = 25
    result3 = is_automorphic_number(num3)
    square3 = num3 * num3
    print(f"\nNumber: {num3}")
    print(f"Square: {square3}")
    print(f"Is automorphic: {result3}")
    
    # Test Case 4 - Not automorphic number
    num4 = 7
    result4 = is_automorphic_number(num4)
    square4 = num4 * num4
    print(f"\nNumber: {num4}")
    print(f"Square: {square4}")
    print(f"Is automorphic: {result4}")
    
    # Test Case 5 - Find automorphic numbers in range
    start = 1
    end = 100
    automorphic_nums = get_automorphic_numbers_in_range(start, end)
    print(f"\nAutomorphic numbers in range [{start}, {end}]:")
    print(automorphic_nums)
    print(f"Count: {len(automorphic_nums)}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Convert Decimal to Hexadecimal")
    print("=" * 60)
    
    # Test Case 1 - Positive number
    num1 = 255
    result1_iter = decimal_to_hexadecimal_iterative(num1)
    result1_rec = decimal_to_hexadecimal_recursive(num1)
    result1_builtin = decimal_to_hexadecimal_builtin(num1)
    result1_list = decimal_to_hexadecimal_list(num1)
    print(f"Decimal: {num1}")
    print(f"Hexadecimal (iterative): {result1_iter}")
    print(f"Hexadecimal (recursive): {result1_rec}")
    print(f"Hexadecimal (built-in): {result1_builtin}")
    print(f"Hexadecimal (list): {''.join(result1_list)}")
    # Verify conversion
    decimal_back = hexadecimal_to_decimal(result1_iter)
    print(f"Verification (hex to decimal): {decimal_back}")
    
    # Test Case 2 - Zero
    num2 = 0
    result2 = decimal_to_hexadecimal_iterative(num2)
    print(f"\nDecimal: {num2}")
    print(f"Hexadecimal: {result2}")
    
    # Test Case 3 - Large number
    num3 = 4095
    result3 = decimal_to_hexadecimal_iterative(num3)
    print(f"\nDecimal: {num3}")
    print(f"Hexadecimal: {result3}")
    print(f"Verification: {hexadecimal_to_decimal(result3)}")
    
    # Test Case 4 - Number with letters
    num4 = 10
    result4 = decimal_to_hexadecimal_iterative(num4)
    print(f"\nDecimal: {num4}")
    print(f"Hexadecimal: {result4}")
    
    # Test Case 5 - Negative number
    num5 = -256
    result5 = decimal_to_hexadecimal_iterative(num5)
    print(f"\nDecimal: {num5}")
    print(f"Hexadecimal: {result5}")
    print(f"Verification: {hexadecimal_to_decimal(result5)}")
