"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if a Number is Pronic/Heteromecic Number
# A Pronic number (also called Heteromecic number) is a number that is the product of two consecutive integers
# Example: 6 = 2 × 3, 12 = 3 × 4, 20 = 4 × 5

def is_pronic_number(n):
    """
    Check if a number is Pronic/Heteromecic number
    A Pronic number is the product of two consecutive integers
    Time Complexity: O(√n)
    Space Complexity: O(1)
    """
    if n < 0:
        return False
    
    # Check if there exists an integer i such that i * (i + 1) == n
    i = 0
    while i * (i + 1) <= n:
        if i * (i + 1) == n:
            return True
        i += 1
    
    return False


def get_pronic_factors(n):
    """
    Get the two consecutive factors if number is Pronic
    Returns tuple (i, i+1) if Pronic, None otherwise
    Time Complexity: O(√n)
    Space Complexity: O(1)
    """
    if n < 0:
        return None
    
    i = 0
    while i * (i + 1) <= n:
        if i * (i + 1) == n:
            return (i, i + 1)
        i += 1
    
    return None


def get_pronic_numbers_in_range(start, end):
    """
    Find all Pronic numbers in a given range
    Time Complexity: O((end - start) * √n)
    Space Complexity: O(k) where k is the number of Pronic numbers
    """
    pronic_numbers = []
    
    for num in range(start, end + 1):
        if is_pronic_number(num):
            pronic_numbers.append(num)
    
    return pronic_numbers


# Problem 2: Check if a Number is Deficient Number
# A Deficient number is a number for which the sum of its proper divisors is less than the number itself
# Example: 8 has proper divisors 1, 2, 4, sum = 7 < 8, so 8 is deficient

def sum_of_proper_divisors(n):
    """
    Calculate sum of proper divisors of a number
    Time Complexity: O(√n)
    Space Complexity: O(1)
    """
    if n <= 1:
        return 0
    
    sum_divisors = 1  # 1 is always a divisor
    
    # Check divisors from 2 to √n
    i = 2
    while i * i <= n:
        if n % i == 0:
            sum_divisors += i
            # Add the corresponding divisor (avoid adding square twice)
            if i != n // i:
                sum_divisors += n // i
        i += 1
    
    return sum_divisors


def is_deficient_number(n):
    """
    Check if a number is deficient number
    Sum of proper divisors is less than the number itself
    Time Complexity: O(√n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return False
    return sum_of_proper_divisors(n) < n


def get_proper_divisors(n):
    """
    Get all proper divisors of a number
    Time Complexity: O(√n)
    Space Complexity: O(√n)
    """
    if n <= 1:
        return []
    
    divisors = [1]
    i = 2
    
    while i * i <= n:
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n // i)
        i += 1
    
    divisors.sort()
    return divisors


def get_deficient_numbers_in_range(start, end):
    """
    Find all Deficient numbers in a given range
    Time Complexity: O((end - start) * √n)
    Space Complexity: O(k) where k is the number of Deficient numbers
    """
    deficient_numbers = []
    
    for num in range(start, end + 1):
        if is_deficient_number(num):
            deficient_numbers.append(num)
    
    return deficient_numbers


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if a Number is Pronic/Heteromecic Number")
    print("=" * 60)
    
    # Test Case 1 - Pronic number 6
    num1 = 6
    result1 = is_pronic_number(num1)
    factors1 = get_pronic_factors(num1)
    print(f"Number: {num1}")
    if factors1:
        print(f"Factors: {factors1[0]} × {factors1[1]} = {num1}")
    print(f"Is Pronic number: {result1}")
    
    # Test Case 2 - Pronic number 12
    num2 = 12
    result2 = is_pronic_number(num2)
    factors2 = get_pronic_factors(num2)
    print(f"\nNumber: {num2}")
    if factors2:
        print(f"Factors: {factors2[0]} × {factors2[1]} = {num2}")
    print(f"Is Pronic number: {result2}")
    
    # Test Case 3 - Not Pronic number
    num3 = 10
    result3 = is_pronic_number(num3)
    factors3 = get_pronic_factors(num3)
    print(f"\nNumber: {num3}")
    print(f"Is Pronic number: {result3}")
    
    # Test Case 4 - Pronic number 0
    num4 = 0
    result4 = is_pronic_number(num4)
    factors4 = get_pronic_factors(num4)
    print(f"\nNumber: {num4}")
    if factors4:
        print(f"Factors: {factors4[0]} × {factors4[1]} = {num4}")
    print(f"Is Pronic number: {result4}")
    
    # Test Case 5 - Find Pronic numbers in range
    start = 0
    end = 50
    pronic_nums = get_pronic_numbers_in_range(start, end)
    print(f"\nPronic numbers in range [{start}, {end}]:")
    print(pronic_nums)
    print(f"Count: {len(pronic_nums)}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Check if a Number is Deficient Number")
    print("=" * 60)
    
    # Test Case 1 - Deficient number 8
    num1 = 8
    result1 = is_deficient_number(num1)
    divisors1 = get_proper_divisors(num1)
    sum1 = sum(divisors1)
    print(f"Number: {num1}")
    print(f"Proper divisors: {divisors1}")
    print(f"Sum of proper divisors: {sum1}")
    print(f"Is deficient: {result1}")
    
    # Test Case 2 - Not deficient (perfect number 6)
    num2 = 6
    result2 = is_deficient_number(num2)
    divisors2 = get_proper_divisors(num2)
    sum2 = sum(divisors2)
    print(f"\nNumber: {num2}")
    print(f"Proper divisors: {divisors2}")
    print(f"Sum of proper divisors: {sum2}")
    print(f"Is deficient: {result2}")
    
    # Test Case 3 - Deficient number 10
    num3 = 10
    result3 = is_deficient_number(num3)
    divisors3 = get_proper_divisors(num3)
    sum3 = sum(divisors3)
    print(f"\nNumber: {num3}")
    print(f"Proper divisors: {divisors3}")
    print(f"Sum of proper divisors: {sum3}")
    print(f"Is deficient: {result3}")
    
    # Test Case 4 - Deficient number 1
    num4 = 1
    result4 = is_deficient_number(num4)
    print(f"\nNumber: {num4}")
    print(f"Is deficient: {result4}")
    
    # Test Case 5 - Find Deficient numbers in range
    start = 1
    end = 30
    deficient_nums = get_deficient_numbers_in_range(start, end)
    print(f"\nDeficient numbers in range [{start}, {end}]:")
    print(deficient_nums)
    print(f"Count: {len(deficient_nums)}")
