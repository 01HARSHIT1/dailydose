"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if a Number is Disarium Number
# A Disarium number is a number where the sum of its digits raised to their respective positions equals the number itself
# Example: 135 = 1^1 + 3^2 + 5^3 = 1 + 9 + 125 = 135

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


def is_disarium_number(n):
    """
    Check if a number is Disarium number
    Time Complexity: O(d * log n) where d is number of digits
    Space Complexity: O(1)
    """
    if n <= 0:
        return False
    
    original = n
    num_digits = count_digits(n)
    sum_powers = 0
    
    # Process digits from right to left
    position = num_digits
    while n > 0:
        digit = n % 10
        sum_powers += digit ** position
        position -= 1
        n //= 10
    
    return sum_powers == original


def get_disarium_numbers_in_range(start, end):
    """
    Find all Disarium numbers in a given range
    Time Complexity: O((end - start) * d * log n)
    Space Complexity: O(k) where k is the number of Disarium numbers
    """
    disarium_numbers = []
    
    for num in range(start, end + 1):
        if is_disarium_number(num):
            disarium_numbers.append(num)
    
    return disarium_numbers


def get_digit_powers_sum(n):
    """
    Get the sum of digits raised to their positions
    Time Complexity: O(d * log n) where d is number of digits
    Space Complexity: O(1)
    """
    if n <= 0:
        return 0
    
    num_digits = count_digits(n)
    sum_powers = 0
    position = num_digits
    
    while n > 0:
        digit = n % 10
        sum_powers += digit ** position
        position -= 1
        n //= 10
    
    return sum_powers


# Problem 2: Convert Octal to Decimal
# Convert an octal (base 8) number to its decimal representation

def octal_to_decimal_iterative(octal_str):
    """
    Convert octal string to decimal using iteration
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


def octal_to_decimal_recursive(octal_str):
    """
    Convert octal string to decimal using recursion
    Time Complexity: O(n) where n is length of octal string
    Space Complexity: O(n) due to recursion stack
    """
    def helper(octal, index, power):
        if index < 0 or (index == 0 and octal[0] == '-'):
            return 0
        digit = int(octal[index])
        if digit < 0 or digit > 7:
            raise ValueError(f"Invalid octal digit: {digit}")
        return digit * (8 ** power) + helper(octal, index - 1, power + 1)
    
    if not octal_str or octal_str == "0":
        return 0
    
    is_negative = octal_str[0] == '-'
    start = len(octal_str) - 1
    
    result = helper(octal_str, start, 0)
    return -result if is_negative else result


def octal_to_decimal_builtin(octal_str):
    """
    Convert octal string to decimal using built-in function
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if not octal_str:
        return 0
    
    is_negative = octal_str[0] == '-'
    octal = octal_str[1:] if is_negative else octal_str
    
    decimal = int(octal, 8)
    return -decimal if is_negative else decimal


def octal_array_to_decimal(octal_array):
    """
    Convert octal array to decimal
    Time Complexity: O(n) where n is length of array
    Space Complexity: O(1)
    """
    if not octal_array:
        return 0
    
    decimal = 0
    power = len(octal_array) - 1
    
    for digit in octal_array:
        if digit < 0 or digit > 7:
            raise ValueError(f"Invalid octal digit: {digit}")
        decimal += digit * (8 ** power)
        power -= 1
    
    return decimal


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if a Number is Disarium Number")
    print("=" * 60)
    
    # Test Case 1 - Disarium number 135
    num1 = 135
    result1 = is_disarium_number(num1)
    sum1 = get_digit_powers_sum(num1)
    print(f"Number: {num1}")
    print(f"Sum of digits raised to positions: {sum1}")
    print(f"Is Disarium number: {result1}")
    
    # Test Case 2 - Disarium number 89
    num2 = 89
    result2 = is_disarium_number(num2)
    sum2 = get_digit_powers_sum(num2)
    print(f"\nNumber: {num2}")
    print(f"Sum of digits raised to positions: {sum2}")
    print(f"Is Disarium number: {result2}")
    
    # Test Case 3 - Not Disarium number
    num3 = 123
    result3 = is_disarium_number(num3)
    sum3 = get_digit_powers_sum(num3)
    print(f"\nNumber: {num3}")
    print(f"Sum of digits raised to positions: {sum3}")
    print(f"Is Disarium number: {result3}")
    
    # Test Case 4 - Single digit Disarium
    num4 = 1
    result4 = is_disarium_number(num4)
    print(f"\nNumber: {num4}")
    print(f"Is Disarium number: {result4}")
    
    # Test Case 5 - Find Disarium numbers in range
    start = 1
    end = 200
    disarium_nums = get_disarium_numbers_in_range(start, end)
    print(f"\nDisarium numbers in range [{start}, {end}]:")
    print(disarium_nums)
    print(f"Count: {len(disarium_nums)}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Convert Octal to Decimal")
    print("=" * 60)
    
    # Test Case 1 - Basic octal
    octal1 = "123"
    result1_iter = octal_to_decimal_iterative(octal1)
    result1_rec = octal_to_decimal_recursive(octal1)
    result1_builtin = octal_to_decimal_builtin(octal1)
    print(f"Octal: {octal1}")
    print(f"Decimal (iterative): {result1_iter}")
    print(f"Decimal (recursive): {result1_rec}")
    print(f"Decimal (built-in): {result1_builtin}")
    
    # Test Case 2 - Zero
    octal2 = "0"
    result2 = octal_to_decimal_iterative(octal2)
    print(f"\nOctal: {octal2}")
    print(f"Decimal: {result2}")
    
    # Test Case 3 - Large octal
    octal3 = "377"
    result3 = octal_to_decimal_iterative(octal3)
    print(f"\nOctal: {octal3}")
    print(f"Decimal: {result3}")
    
    # Test Case 4 - Octal array
    octal4 = [1, 2, 7]
    result4 = octal_array_to_decimal(octal4)
    print(f"\nOctal (array): {octal4}")
    print(f"Decimal: {result4}")
    
    # Test Case 5 - Single digit
    octal5 = "7"
    result5 = octal_to_decimal_iterative(octal5)
    print(f"\nOctal: {octal5}")
    print(f"Decimal: {result5}")
