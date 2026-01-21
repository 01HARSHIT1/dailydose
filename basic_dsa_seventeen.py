"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Convert Decimal to Binary
# Convert a decimal number to its binary representation

def decimal_to_binary_iterative(n):
    """
    Convert decimal to binary using iteration
    Time Complexity: O(log n)
    Space Complexity: O(log n)
    """
    if n == 0:
        return "0"
    
    binary = ""
    num = abs(n)
    
    while num > 0:
        binary = str(num % 2) + binary
        num //= 2
    
    return binary if n >= 0 else "-" + binary


def decimal_to_binary_recursive(n):
    """
    Convert decimal to binary using recursion
    Time Complexity: O(log n)
    Space Complexity: O(log n) due to recursion stack
    """
    if n == 0:
        return "0"
    if n == 1:
        return "1"
    if n < 0:
        return "-" + decimal_to_binary_recursive(-n)
    
    return decimal_to_binary_recursive(n // 2) + str(n % 2)


def decimal_to_binary_builtin(n):
    """
    Convert decimal to binary using built-in function
    Time Complexity: O(log n)
    Space Complexity: O(log n)
    """
    return bin(n) if n >= 0 else "-" + bin(-n)[2:]


def decimal_to_binary_list(n):
    """
    Convert decimal to binary and return as list of digits
    Time Complexity: O(log n)
    Space Complexity: O(log n)
    """
    if n == 0:
        return [0]
    
    binary_list = []
    num = abs(n)
    
    while num > 0:
        binary_list.insert(0, num % 2)
        num //= 2
    
    return binary_list if n >= 0 else [-1] + binary_list


# Problem 2: Find Sum of Cubes of First N Natural Numbers
# Calculate 1³ + 2³ + 3³ + ... + N³

def sum_of_cubes_iterative(n):
    """
    Find sum of cubes using iteration
    Time Complexity: O(n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return 0
    
    total = 0
    for i in range(1, n + 1):
        total += i * i * i
    return total


def sum_of_cubes_formula(n):
    """
    Find sum of cubes using mathematical formula: [n(n+1)/2]²
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if n <= 0:
        return 0
    return (n * (n + 1) // 2) ** 2


def sum_of_cubes_recursive(n):
    """
    Find sum of cubes using recursion
    Time Complexity: O(n)
    Space Complexity: O(n) due to recursion stack
    """
    if n <= 0:
        return 0
    if n == 1:
        return 1
    return n * n * n + sum_of_cubes_recursive(n - 1)


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Convert Decimal to Binary")
    print("=" * 60)
    
    # Test Case 1 - Positive number
    num1 = 10
    result1_iter = decimal_to_binary_iterative(num1)
    result1_rec = decimal_to_binary_recursive(num1)
    result1_builtin = decimal_to_binary_builtin(num1)
    result1_list = decimal_to_binary_list(num1)
    print(f"Decimal: {num1}")
    print(f"Binary (iterative): {result1_iter}")
    print(f"Binary (recursive): {result1_rec}")
    print(f"Binary (built-in): {result1_builtin}")
    print(f"Binary (list): {result1_list}")
    
    # Test Case 2 - Zero
    num2 = 0
    result2 = decimal_to_binary_iterative(num2)
    print(f"\nDecimal: {num2}")
    print(f"Binary: {result2}")
    
    # Test Case 3 - Negative number
    num3 = -15
    result3 = decimal_to_binary_iterative(num3)
    print(f"\nDecimal: {num3}")
    print(f"Binary: {result3}")
    
    # Test Case 4 - Large number
    num4 = 255
    result4 = decimal_to_binary_iterative(num4)
    print(f"\nDecimal: {num4}")
    print(f"Binary: {result4}")
    
    # Test Case 5 - Single digit
    num5 = 7
    result5 = decimal_to_binary_iterative(num5)
    print(f"\nDecimal: {num5}")
    print(f"Binary: {result5}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Find Sum of Cubes of First N Natural Numbers")
    print("=" * 60)
    
    # Test Case 1
    n1 = 5
    result1_iter = sum_of_cubes_iterative(n1)
    result1_formula = sum_of_cubes_formula(n1)
    result1_rec = sum_of_cubes_recursive(n1)
    print(f"N = {n1}")
    print(f"1³ + 2³ + 3³ + 4³ + 5³ = {result1_iter}")
    print(f"Iterative method: {result1_iter}")
    print(f"Formula method: {result1_formula}")
    print(f"Recursive method: {result1_rec}")
    
    # Test Case 2
    n2 = 10
    result2 = sum_of_cubes_formula(n2)
    print(f"\nN = {n2}")
    print(f"Sum of cubes: {result2}")
    
    # Test Case 3
    n3 = 1
    result3 = sum_of_cubes_formula(n3)
    print(f"\nN = {n3}")
    print(f"Sum of cubes: {result3}")
    
    # Test Case 4
    n4 = 7
    result4 = sum_of_cubes_formula(n4)
    print(f"\nN = {n4}")
    print(f"Sum of cubes: {result4}")
    
    # Test Case 5 - Larger number
    n5 = 20
    result5 = sum_of_cubes_formula(n5)
    print(f"\nN = {n5}")
    print(f"Sum of cubes: {result5}")
    
    # Verification: Formula should equal sum of first n natural numbers squared
    print(f"\nVerification: (1+2+...+{n5})² = {((n5 * (n5 + 1)) // 2) ** 2}")
