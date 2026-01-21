"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if a Number is Harshad/Niven Number
# A Harshad number (or Niven number) is a number that is divisible by the sum of its digits
# Example: 18 is Harshad because 1 + 8 = 9, and 18 is divisible by 9

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


def is_harshad_number(n):
    """
    Check if a number is Harshad/Niven number
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return False
    
    digit_sum = sum_of_digits(n)
    return n % digit_sum == 0


def get_harshad_numbers_in_range(start, end):
    """
    Find all Harshad numbers in a given range
    Time Complexity: O((end - start) * log n)
    Space Complexity: O(k) where k is the number of Harshad numbers
    """
    harshad_numbers = []
    
    for num in range(start, end + 1):
        if is_harshad_number(num):
            harshad_numbers.append(num)
    
    return harshad_numbers


# Problem 2: Convert Decimal to Octal
# Convert a decimal number to its octal (base 8) representation

def decimal_to_octal_iterative(n):
    """
    Convert decimal to octal using iteration
    Time Complexity: O(log n)
    Space Complexity: O(log n)
    """
    if n == 0:
        return "0"
    
    octal = ""
    num = abs(n)
    
    while num > 0:
        octal = str(num % 8) + octal
        num //= 8
    
    return octal if n >= 0 else "-" + octal


def decimal_to_octal_recursive(n):
    """
    Convert decimal to octal using recursion
    Time Complexity: O(log n)
    Space Complexity: O(log n) due to recursion stack
    """
    if n == 0:
        return "0"
    if abs(n) < 8:
        return str(n) if n >= 0 else "-" + str(-n)
    if n < 0:
        return "-" + decimal_to_octal_recursive(-n)
    
    return decimal_to_octal_recursive(n // 8) + str(n % 8)


def decimal_to_octal_builtin(n):
    """
    Convert decimal to octal using built-in function
    Time Complexity: O(log n)
    Space Complexity: O(log n)
    """
    return oct(n) if n >= 0 else "-" + oct(-n)[2:]


def decimal_to_octal_list(n):
    """
    Convert decimal to octal and return as list of digits
    Time Complexity: O(log n)
    Space Complexity: O(log n)
    """
    if n == 0:
        return [0]
    
    octal_list = []
    num = abs(n)
    
    while num > 0:
        octal_list.insert(0, num % 8)
        num //= 8
    
    return octal_list if n >= 0 else [-1] + octal_list


def octal_to_decimal(octal_str):
    """
    Convert octal string back to decimal (helper function)
    Time Complexity: O(n) where n is length of octal string
    Space Complexity: O(1)
    """
    if not octal_str or octal_str == "0":
        return 0
    
    is_negative = octal_str[0] == '-'
    start = 1 if is_negative else 0
    
    decimal = 0
    power = 0
    
    # Process from right to left
    for i in range(len(octal_str) - 1, start - 1, -1):
        digit = int(octal_str[i])
        if digit < 0 or digit > 7:
            raise ValueError(f"Invalid octal digit: {digit}")
        decimal += digit * (8 ** power)
        power += 1
    
    return -decimal if is_negative else decimal


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if a Number is Harshad/Niven Number")
    print("=" * 60)
    
    # Test Case 1 - Harshad number 18
    num1 = 18
    result1 = is_harshad_number(num1)
    sum1 = sum_of_digits(num1)
    print(f"Number: {num1}")
    print(f"Sum of digits: {sum1}")
    print(f"{num1} ÷ {sum1} = {num1 // sum1}")
    print(f"Is Harshad number: {result1}")
    
    # Test Case 2 - Harshad number 12
    num2 = 12
    result2 = is_harshad_number(num2)
    sum2 = sum_of_digits(num2)
    print(f"\nNumber: {num2}")
    print(f"Sum of digits: {sum2}")
    print(f"{num2} ÷ {sum2} = {num2 // sum2}")
    print(f"Is Harshad number: {result2}")
    
    # Test Case 3 - Not Harshad number
    num3 = 19
    result3 = is_harshad_number(num3)
    sum3 = sum_of_digits(num3)
    print(f"\nNumber: {num3}")
    print(f"Sum of digits: {sum3}")
    print(f"{num3} ÷ {sum3} = {num3 / sum3} (not divisible)")
    print(f"Is Harshad number: {result3}")
    
    # Test Case 4 - Harshad number 1
    num4 = 1
    result4 = is_harshad_number(num4)
    print(f"\nNumber: {num4}")
    print(f"Is Harshad number: {result4}")
    
    # Test Case 5 - Find Harshad numbers in range
    start = 1
    end = 30
    harshad_nums = get_harshad_numbers_in_range(start, end)
    print(f"\nHarshad numbers in range [{start}, {end}]:")
    print(harshad_nums)
    print(f"Count: {len(harshad_nums)}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Convert Decimal to Octal")
    print("=" * 60)
    
    # Test Case 1 - Positive number
    num1 = 64
    result1_iter = decimal_to_octal_iterative(num1)
    result1_rec = decimal_to_octal_recursive(num1)
    result1_builtin = decimal_to_octal_builtin(num1)
    result1_list = decimal_to_octal_list(num1)
    print(f"Decimal: {num1}")
    print(f"Octal (iterative): {result1_iter}")
    print(f"Octal (recursive): {result1_rec}")
    print(f"Octal (built-in): {result1_builtin}")
    print(f"Octal (list): {result1_list}")
    # Verify conversion
    decimal_back = octal_to_decimal(result1_iter)
    print(f"Verification (octal to decimal): {decimal_back}")
    
    # Test Case 2 - Zero
    num2 = 0
    result2 = decimal_to_octal_iterative(num2)
    print(f"\nDecimal: {num2}")
    print(f"Octal: {result2}")
    
    # Test Case 3 - Large number
    num3 = 255
    result3 = decimal_to_octal_iterative(num3)
    print(f"\nDecimal: {num3}")
    print(f"Octal: {result3}")
    print(f"Verification: {octal_to_decimal(result3)}")
    
    # Test Case 4 - Single digit
    num4 = 7
    result4 = decimal_to_octal_iterative(num4)
    print(f"\nDecimal: {num4}")
    print(f"Octal: {result4}")
    
    # Test Case 5 - Negative number
    num5 = -100
    result5 = decimal_to_octal_iterative(num5)
    print(f"\nDecimal: {num5}")
    print(f"Octal: {result5}")
    print(f"Verification: {octal_to_decimal(result5)}")
