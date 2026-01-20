"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Count Digits in a Number
# Count the number of digits in a number

def count_digits(n):
    """
    Count digits using iterative approach
    Time Complexity: O(log n) where log is base 10
    Space Complexity: O(1)
    """
    if n == 0:
        return 1
    
    n = abs(n)  # Handle negative numbers
    count = 0
    
    while n > 0:
        count += 1
        n //= 10
    
    return count


def count_digits_recursive(n):
    """
    Count digits using recursive approach
    Time Complexity: O(log n)
    Space Complexity: O(log n) due to recursion stack
    """
    n = abs(n)  # Handle negative numbers
    if n < 10:
        return 1
    return 1 + count_digits_recursive(n // 10)


def count_digits_log(n):
    """
    Count digits using logarithmic approach
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if n == 0:
        return 1
    import math
    return int(math.log10(abs(n))) + 1


# Problem 2: Check if a Number is Armstrong Number
# An Armstrong number is a number that is equal to the sum of its own digits each raised to the power of the number of digits

def is_armstrong(n):
    """
    Check if a number is Armstrong number
    Time Complexity: O(d) where d is number of digits
    Space Complexity: O(1)
    """
    if n < 0:
        return False
    
    original = n
    num_digits = count_digits(n)
    sum_power = 0
    
    while n > 0:
        digit = n % 10
        sum_power += digit ** num_digits
        n //= 10
    
    return original == sum_power


def find_armstrong_numbers_in_range(start, end):
    """
    Find all Armstrong numbers in a given range
    Time Complexity: O(n * d) where n is range size, d is average digits
    Space Complexity: O(1) excluding output
    """
    armstrong_nums = []
    
    for num in range(start, end + 1):
        if is_armstrong(num):
            armstrong_nums.append(num)
    
    return armstrong_nums


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Count Digits in a Number")
    print("=" * 60)
    
    # Test Case 1
    num1 = 12345
    count1 = count_digits(num1)
    count_rec1 = count_digits_recursive(num1)
    count_log1 = count_digits_log(num1)
    print(f"Number: {num1}")
    print(f"Number of digits (Iterative): {count1}")
    print(f"Number of digits (Recursive): {count_rec1}")
    print(f"Number of digits (Logarithmic): {count_log1}")
    
    # Test Case 2
    num2 = 9876
    count2 = count_digits(num2)
    count_rec2 = count_digits_recursive(num2)
    count_log2 = count_digits_log(num2)
    print(f"\nNumber: {num2}")
    print(f"Number of digits (Iterative): {count2}")
    print(f"Number of digits (Recursive): {count_rec2}")
    print(f"Number of digits (Logarithmic): {count_log2}")
    
    # Test Case 3 - Single digit
    num3 = 5
    count3 = count_digits(num3)
    count_rec3 = count_digits_recursive(num3)
    count_log3 = count_digits_log(num3)
    print(f"\nNumber: {num3}")
    print(f"Number of digits (Iterative): {count3}")
    print(f"Number of digits (Recursive): {count_rec3}")
    print(f"Number of digits (Logarithmic): {count_log3}")
    
    # Test Case 4 - Zero
    num4 = 0
    count4 = count_digits(num4)
    count_rec4 = count_digits_recursive(num4)
    count_log4 = count_digits_log(num4)
    print(f"\nNumber: {num4}")
    print(f"Number of digits (Iterative): {count4}")
    print(f"Number of digits (Recursive): {count_rec4}")
    print(f"Number of digits (Logarithmic): {count_log4}")
    
    # Test Case 5 - Negative number
    num5 = -123
    count5 = count_digits(num5)
    count_rec5 = count_digits_recursive(num5)
    count_log5 = count_digits_log(num5)
    print(f"\nNumber: {num5}")
    print(f"Number of digits (Iterative): {count5}")
    print(f"Number of digits (Recursive): {count_rec5}")
    print(f"Number of digits (Logarithmic): {count_log5}")
    
    # Test Case 6 - Large number
    num6 = 1234567890
    count6 = count_digits(num6)
    count_rec6 = count_digits_recursive(num6)
    count_log6 = count_digits_log(num6)
    print(f"\nNumber: {num6}")
    print(f"Number of digits (Iterative): {count6}")
    print(f"Number of digits (Recursive): {count_rec6}")
    print(f"Number of digits (Logarithmic): {count_log6}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Check if a Number is Armstrong Number")
    print("=" * 60)
    
    # Test Case 1 - Armstrong number (153: 1^3 + 5^3 + 3^3 = 153)
    num7 = 153
    result1 = is_armstrong(num7)
    print(f"Number: {num7}")
    print(f"Is Armstrong: {result1}")
    if result1:
        print(f"Verification: 1³ + 5³ + 3³ = {1**3} + {5**3} + {3**3} = {1**3 + 5**3 + 3**3} = {num7}")
    
    # Test Case 2 - Not Armstrong
    num8 = 123
    result2 = is_armstrong(num8)
    print(f"\nNumber: {num8}")
    print(f"Is Armstrong: {result2}")
    
    # Test Case 3 - Armstrong number (371: 3^3 + 7^3 + 1^3 = 371)
    num9 = 371
    result3 = is_armstrong(num9)
    print(f"\nNumber: {num9}")
    print(f"Is Armstrong: {result3}")
    
    # Test Case 4 - Armstrong number (407: 4^3 + 0^3 + 7^3 = 407)
    num10 = 407
    result4 = is_armstrong(num10)
    print(f"\nNumber: {num10}")
    print(f"Is Armstrong: {result4}")
    
    # Test Case 5 - Single digit (all single digits are Armstrong)
    num11 = 5
    result5 = is_armstrong(num11)
    print(f"\nNumber: {num11}")
    print(f"Is Armstrong: {result5}")
    
    # Test Case 6 - 4-digit Armstrong (1634: 1^4 + 6^4 + 3^4 + 4^4 = 1634)
    num12 = 1634
    result6 = is_armstrong(num12)
    print(f"\nNumber: {num12}")
    print(f"Is Armstrong: {result6}")
    
    # Test Case 7 - Find Armstrong numbers in range
    print(f"\nArmstrong numbers between 100 and 500: {find_armstrong_numbers_in_range(100, 500)}")
