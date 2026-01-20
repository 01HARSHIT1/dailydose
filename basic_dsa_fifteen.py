"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if Number is Positive, Negative, or Zero
# Determine whether a number is positive, negative, or zero

def check_number_sign(n):
    """
    Check if number is positive, negative, or zero
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if n > 0:
        return "Positive"
    elif n < 0:
        return "Negative"
    else:
        return "Zero"


# Problem 2: Print Multiplication Table
# Print multiplication table for a given number

def print_multiplication_table(n, limit=10):
    """
    Print multiplication table for a number
    Time Complexity: O(limit)
    Space Complexity: O(1)
    """
    print(f"Multiplication table of {n}:")
    for i in range(1, limit + 1):
        print(f"{n} x {i} = {n * i}")


def get_multiplication_table(n, limit=10):
    """
    Get multiplication table as a list
    Time Complexity: O(limit)
    Space Complexity: O(limit)
    """
    table = []
    for i in range(1, limit + 1):
        table.append(f"{n} x {i} = {n * i}")
    return table


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if Number is Positive, Negative, or Zero")
    print("=" * 60)
    
    # Test Case 1 - Positive number
    num1 = 15
    result1 = check_number_sign(num1)
    print(f"Number: {num1}")
    print(f"Sign: {result1}")
    
    # Test Case 2 - Negative number
    num2 = -10
    result2 = check_number_sign(num2)
    print(f"\nNumber: {num2}")
    print(f"Sign: {result2}")
    
    # Test Case 3 - Zero
    num3 = 0
    result3 = check_number_sign(num3)
    print(f"\nNumber: {num3}")
    print(f"Sign: {result3}")
    
    # Test Case 4 - Large positive
    num4 = 1000
    result4 = check_number_sign(num4)
    print(f"\nNumber: {num4}")
    print(f"Sign: {result4}")
    
    # Test Case 5 - Large negative
    num5 = -500
    result5 = check_number_sign(num5)
    print(f"\nNumber: {num5}")
    print(f"Sign: {result5}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Print Multiplication Table")
    print("=" * 60)
    
    # Test Case 1
    num6 = 5
    print_multiplication_table(num6, 10)
    
    # Test Case 2
    print("\n")
    num7 = 7
    table1 = get_multiplication_table(num7, 12)
    print(f"Multiplication table of {num7}:")
    for row in table1:
        print(row)
    
    # Test Case 3 - Zero
    print("\n")
    num8 = 0
    print_multiplication_table(num8, 5)
    
    # Test Case 4 - Negative number
    print("\n")
    num9 = -3
    print_multiplication_table(num9, 5)
    
    # Test Case 5 - Custom limit
    print("\n")
    num10 = 9
    print_multiplication_table(num10, 5)
