"""
Basic DSA Problems - One More Fundamental Question
Simple and essential DSA problems for beginners
"""


# Problem: Check if a Number is Smith Number
# A Smith number is a composite number whose sum of digits equals the sum of digits of its prime factors
# Example: 4 = 2 × 2, sum of digits of 4 = 4, sum of digits of prime factors (2+2) = 4, so 4 is Smith
# Example: 22 = 2 × 11, sum of digits of 22 = 4, sum of digits of prime factors (2+1+1) = 4, so 22 is Smith

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


def is_prime(n):
    """
    Check if a number is prime
    Time Complexity: O(√n)
    Space Complexity: O(1)
    """
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    
    i = 3
    while i * i <= n:
        if n % i == 0:
            return False
        i += 2
    
    return True


def get_prime_factors(n):
    """
    Get all prime factors of a number (with repetition)
    Time Complexity: O(√n)
    Space Complexity: O(log n)
    """
    if n < 2:
        return []
    
    factors = []
    num = abs(n)
    
    # Check for factor 2
    while num % 2 == 0:
        factors.append(2)
        num //= 2
    
    # Check for odd factors
    i = 3
    while i * i <= num:
        while num % i == 0:
            factors.append(i)
            num //= i
        i += 2
    
    # If remaining number is prime
    if num > 1:
        factors.append(num)
    
    return factors


def sum_of_digits_of_factors(factors):
    """
    Calculate sum of digits of all factors
    Time Complexity: O(k * log m) where k is number of factors, m is max factor
    Space Complexity: O(1)
    """
    total = 0
    for factor in factors:
        total += sum_of_digits(factor)
    return total


def is_smith_number(n):
    """
    Check if a number is Smith number
    A Smith number is composite and sum of digits equals sum of digits of prime factors
    Time Complexity: O(√n)
    Space Complexity: O(log n)
    """
    if n < 4:
        return False  # No composite numbers below 4
    
    # Smith numbers must be composite
    if is_prime(n):
        return False
    
    # Get prime factors
    factors = get_prime_factors(n)
    
    # Calculate sum of digits of number
    sum_digits_num = sum_of_digits(n)
    
    # Calculate sum of digits of prime factors
    sum_digits_factors = sum_of_digits_of_factors(factors)
    
    return sum_digits_num == sum_digits_factors


def get_smith_numbers_in_range(start, end):
    """
    Find all Smith numbers in a given range
    Time Complexity: O((end - start) * √n)
    Space Complexity: O(k) where k is the number of Smith numbers
    """
    smith_numbers = []
    
    for num in range(start, end + 1):
        if is_smith_number(num):
            smith_numbers.append(num)
    
    return smith_numbers


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Check if a Number is Smith Number")
    print("=" * 60)
    
    # Test Case 1 - Smith number 4
    num1 = 4
    result1 = is_smith_number(num1)
    factors1 = get_prime_factors(num1)
    sum_digits1 = sum_of_digits(num1)
    sum_factors1 = sum_of_digits_of_factors(factors1)
    print(f"Number: {num1}")
    print(f"Prime factors: {factors1}")
    print(f"Sum of digits of number: {sum_digits1}")
    print(f"Sum of digits of factors: {sum_factors1}")
    print(f"Is Smith number: {result1}")
    
    # Test Case 2 - Smith number 22
    num2 = 22
    result2 = is_smith_number(num2)
    factors2 = get_prime_factors(num2)
    sum_digits2 = sum_of_digits(num2)
    sum_factors2 = sum_of_digits_of_factors(factors2)
    print(f"\nNumber: {num2}")
    print(f"Prime factors: {factors2}")
    print(f"Sum of digits of number: {sum_digits2}")
    print(f"Sum of digits of factors: {sum_factors2}")
    print(f"Is Smith number: {result2}")
    
    # Test Case 3 - Smith number 27
    num3 = 27
    result3 = is_smith_number(num3)
    factors3 = get_prime_factors(num3)
    sum_digits3 = sum_of_digits(num3)
    sum_factors3 = sum_of_digits_of_factors(factors3)
    print(f"\nNumber: {num3}")
    print(f"Prime factors: {factors3}")
    print(f"Sum of digits of number: {sum_digits3}")
    print(f"Sum of digits of factors: {sum_factors3}")
    print(f"Is Smith number: {result3}")
    
    # Test Case 4 - Not Smith number (prime)
    num4 = 7
    result4 = is_smith_number(num4)
    print(f"\nNumber: {num4}")
    print(f"Is Smith number: {result4} (prime numbers are not Smith)")
    
    # Test Case 5 - Not Smith number (composite but not Smith)
    num5 = 8
    result5 = is_smith_number(num5)
    factors5 = get_prime_factors(num5)
    sum_digits5 = sum_of_digits(num5)
    sum_factors5 = sum_of_digits_of_factors(factors5)
    print(f"\nNumber: {num5}")
    print(f"Prime factors: {factors5}")
    print(f"Sum of digits of number: {sum_digits5}")
    print(f"Sum of digits of factors: {sum_factors5}")
    print(f"Is Smith number: {result5}")
    
    # Test Case 6 - Find Smith numbers in range
    start = 1
    end = 100
    smith_nums = get_smith_numbers_in_range(start, end)
    print(f"\nSmith numbers in range [{start}, {end}]:")
    print(smith_nums)
    print(f"Count: {len(smith_nums)}")
    
    # Test Case 7 - Smith number 666
    num7 = 666
    result7 = is_smith_number(num7)
    factors7 = get_prime_factors(num7)
    sum_digits7 = sum_of_digits(num7)
    sum_factors7 = sum_of_digits_of_factors(factors7)
    print(f"\nNumber: {num7}")
    print(f"Prime factors: {factors7}")
    print(f"Sum of digits of number: {sum_digits7}")
    print(f"Sum of digits of factors: {sum_factors7}")
    print(f"Is Smith number: {result7}")
