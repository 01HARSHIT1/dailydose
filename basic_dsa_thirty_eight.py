"""
Basic DSA Problems - One More Fundamental Question
Simple and essential DSA problems for beginners
"""


# Problem: Check if a Number is Circular Prime
# A Circular Prime is a prime number that remains prime when its digits are rotated
# Example: 197 is circular prime because 197, 971, and 719 are all prime
# Note: Single-digit primes (2, 3, 5, 7) are circular primes

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


def rotate_number(n):
    """
    Rotate a number by moving the last digit to the front
    Example: 197 -> 719
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n < 10:
        return n
    
    last_digit = n % 10
    remaining = n // 10
    num_digits = count_digits(n)
    
    # Move last digit to front
    rotated = last_digit * (10 ** (num_digits - 1)) + remaining
    
    return rotated


def get_all_rotations(n):
    """
    Get all rotations of a number
    Time Complexity: O(d * log n) where d is number of digits
    Space Complexity: O(d)
    """
    rotations = []
    num_digits = count_digits(n)
    current = n
    
    for _ in range(num_digits):
        rotations.append(current)
        current = rotate_number(current)
    
    return rotations


def is_circular_prime(n):
    """
    Check if a number is Circular Prime
    A Circular Prime remains prime when its digits are rotated
    Time Complexity: O(d * √n) where d is number of digits
    Space Complexity: O(d)
    """
    if n < 2:
        return False
    
    # Get all rotations
    rotations = get_all_rotations(n)
    
    # Check if all rotations are prime
    for rotation in rotations:
        if not is_prime(rotation):
            return False
    
    return True


def get_circular_primes_in_range(start, end):
    """
    Find all Circular Prime numbers in a given range
    Time Complexity: O((end - start) * d * √n)
    Space Complexity: O(k) where k is the number of Circular Primes
    """
    circular_primes = []
    
    for num in range(start, end + 1):
        if is_circular_prime(num):
            circular_primes.append(num)
    
    return circular_primes


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Check if a Number is Circular Prime")
    print("=" * 60)
    
    # Test Case 1 - Circular Prime 2
    num1 = 2
    result1 = is_circular_prime(num1)
    rotations1 = get_all_rotations(num1)
    print(f"Number: {num1}")
    print(f"Rotations: {rotations1}")
    print(f"Is Circular Prime: {result1}")
    
    # Test Case 2 - Circular Prime 197
    num2 = 197
    result2 = is_circular_prime(num2)
    rotations2 = get_all_rotations(num2)
    print(f"\nNumber: {num2}")
    print(f"Rotations: {rotations2}")
    print(f"All rotations prime: {all(is_prime(r) for r in rotations2)}")
    print(f"Is Circular Prime: {result2}")
    
    # Test Case 3 - Circular Prime 113
    num3 = 113
    result3 = is_circular_prime(num3)
    rotations3 = get_all_rotations(num3)
    print(f"\nNumber: {num3}")
    print(f"Rotations: {rotations3}")
    print(f"All rotations prime: {all(is_prime(r) for r in rotations3)}")
    print(f"Is Circular Prime: {result3}")
    
    # Test Case 4 - Not Circular Prime (19)
    num4 = 19
    result4 = is_circular_prime(num4)
    rotations4 = get_all_rotations(num4)
    print(f"\nNumber: {num4}")
    print(f"Rotations: {rotations4}")
    print(f"All rotations prime: {all(is_prime(r) for r in rotations4)}")
    print(f"Is Circular Prime: {result4}")
    
    # Test Case 5 - Single digit Circular Prime 7
    num5 = 7
    result5 = is_circular_prime(num5)
    rotations5 = get_all_rotations(num5)
    print(f"\nNumber: {num5}")
    print(f"Rotations: {rotations5}")
    print(f"Is Circular Prime: {result5}")
    
    # Test Case 6 - Find Circular Primes in range
    start = 1
    end = 100
    circular_primes = get_circular_primes_in_range(start, end)
    print(f"\nCircular Prime numbers in range [{start}, {end}]:")
    print(circular_primes)
    print(f"Count: {len(circular_primes)}")
    
    # Test Case 7 - Circular Prime 199
    num7 = 199
    result7 = is_circular_prime(num7)
    rotations7 = get_all_rotations(num7)
    print(f"\nNumber: {num7}")
    print(f"Rotations: {rotations7}")
    print(f"All rotations prime: {all(is_prime(r) for r in rotations7)}")
    print(f"Is Circular Prime: {result7}")
