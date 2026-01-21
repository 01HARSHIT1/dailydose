"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if a Number is Abundant Number
# An abundant number is a number for which the sum of its proper divisors is greater than the number itself
# Example: 12 has proper divisors 1, 2, 3, 4, 6, sum = 16 > 12, so 12 is abundant

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


def is_abundant_number(n):
    """
    Check if a number is abundant number
    Time Complexity: O(√n)
    Space Complexity: O(1)
    """
    if n <= 0:
        return False
    return sum_of_proper_divisors(n) > n


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


# Problem 2: Find All Prime Numbers in a Range
# Find all prime numbers between two given numbers using Sieve of Eratosthenes

def sieve_of_eratosthenes(n):
    """
    Find all prime numbers up to n using Sieve of Eratosthenes
    Time Complexity: O(n log log n)
    Space Complexity: O(n)
    """
    if n < 2:
        return []
    
    # Create boolean array, initially all True
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False
    
    # Mark multiples of primes as False
    i = 2
    while i * i <= n:
        if is_prime[i]:
            # Mark all multiples of i as non-prime
            for j in range(i * i, n + 1, i):
                is_prime[j] = False
        i += 1
    
    # Collect all prime numbers
    primes = [num for num in range(2, n + 1) if is_prime[num]]
    return primes


def primes_in_range(start, end):
    """
    Find all prime numbers in a given range [start, end]
    Time Complexity: O(end log log end) for sieve + O(end - start) for filtering
    Space Complexity: O(end)
    """
    if end < 2 or start > end:
        return []
    
    # Adjust start to be at least 2
    start = max(2, start)
    
    # Use sieve to find all primes up to end
    all_primes = sieve_of_eratosthenes(end)
    
    # Filter primes in the range [start, end]
    primes_in_range_list = [p for p in all_primes if p >= start]
    return primes_in_range_list


def is_prime_simple(n):
    """
    Simple prime check for a single number
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


def count_primes_in_range(start, end):
    """
    Count prime numbers in a given range
    Time Complexity: O(end log log end)
    Space Complexity: O(end)
    """
    primes = primes_in_range(start, end)
    return len(primes)


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if a Number is Abundant Number")
    print("=" * 60)
    
    # Test Case 1 - Abundant number 12
    num1 = 12
    result1 = is_abundant_number(num1)
    divisors1 = get_proper_divisors(num1)
    sum1 = sum(divisors1)
    print(f"Number: {num1}")
    print(f"Proper divisors: {divisors1}")
    print(f"Sum of proper divisors: {sum1}")
    print(f"Is abundant: {result1}")
    
    # Test Case 2 - Not abundant number
    num2 = 10
    result2 = is_abundant_number(num2)
    divisors2 = get_proper_divisors(num2)
    sum2 = sum(divisors2)
    print(f"\nNumber: {num2}")
    print(f"Proper divisors: {divisors2}")
    print(f"Sum of proper divisors: {sum2}")
    print(f"Is abundant: {result2}")
    
    # Test Case 3 - Abundant number 18
    num3 = 18
    result3 = is_abundant_number(num3)
    divisors3 = get_proper_divisors(num3)
    sum3 = sum(divisors3)
    print(f"\nNumber: {num3}")
    print(f"Proper divisors: {divisors3}")
    print(f"Sum of proper divisors: {sum3}")
    print(f"Is abundant: {result3}")
    
    # Test Case 4 - Perfect number (not abundant)
    num4 = 6
    result4 = is_abundant_number(num4)
    divisors4 = get_proper_divisors(num4)
    sum4 = sum(divisors4)
    print(f"\nNumber: {num4}")
    print(f"Proper divisors: {divisors4}")
    print(f"Sum of proper divisors: {sum4}")
    print(f"Is abundant: {result4}")
    
    # Test Case 5 - Deficient number (not abundant)
    num5 = 8
    result5 = is_abundant_number(num5)
    divisors5 = get_proper_divisors(num5)
    sum5 = sum(divisors5)
    print(f"\nNumber: {num5}")
    print(f"Proper divisors: {divisors5}")
    print(f"Sum of proper divisors: {sum5}")
    print(f"Is abundant: {result5}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Find All Prime Numbers in a Range")
    print("=" * 60)
    
    # Test Case 1 - Primes up to 30
    n1 = 30
    primes1 = sieve_of_eratosthenes(n1)
    print(f"Prime numbers up to {n1}:")
    print(primes1)
    print(f"Count: {len(primes1)}")
    
    # Test Case 2 - Primes in range [10, 50]
    start2 = 10
    end2 = 50
    primes2 = primes_in_range(start2, end2)
    print(f"\nPrime numbers in range [{start2}, {end2}]:")
    print(primes2)
    print(f"Count: {len(primes2)}")
    
    # Test Case 3 - Primes in range [1, 20]
    start3 = 1
    end3 = 20
    primes3 = primes_in_range(start3, end3)
    print(f"\nPrime numbers in range [{start3}, {end3}]:")
    print(primes3)
    print(f"Count: {len(primes3)}")
    
    # Test Case 4 - Count primes in range
    start4 = 2
    end4 = 100
    count4 = count_primes_in_range(start4, end4)
    print(f"\nNumber of primes in range [{start4}, {end4}]: {count4}")
    
    # Test Case 5 - Primes up to 100
    n5 = 100
    primes5 = sieve_of_eratosthenes(n5)
    print(f"\nPrime numbers up to {n5}:")
    print(primes5)
    print(f"Count: {len(primes5)}")
