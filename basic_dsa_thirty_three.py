"""
Basic DSA Problems - One More Fundamental Question
Simple and essential DSA problems for beginners
"""


# Problem: Find nth Prime Number
# Find the nth prime number in the sequence of prime numbers
# Example: 1st prime = 2, 2nd prime = 3, 3rd prime = 5, 4th prime = 7, 5th prime = 11

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


def nth_prime_brute_force(n):
    """
    Find nth prime number using brute force
    Time Complexity: O(n * √n)
    Space Complexity: O(1)
    """
    if n <= 0:
        raise ValueError("n must be positive")
    
    if n == 1:
        return 2
    
    count = 1
    num = 3
    
    while count < n:
        if is_prime(num):
            count += 1
            if count == n:
                return num
        num += 2  # Check only odd numbers (except 2)
    
    return num - 2


def nth_prime_sieve_optimized(n):
    """
    Find nth prime number using optimized approach with Sieve of Eratosthenes
    Time Complexity: O(n log log n) for sieve
    Space Complexity: O(n)
    """
    if n <= 0:
        raise ValueError("n must be positive")
    
    if n == 1:
        return 2
    
    # Estimate upper bound: n * log(n) + n * log(log(n)) for n > 6
    if n <= 6:
        primes = [2, 3, 5, 7, 11, 13]
        return primes[n - 1]
    
    import math
    upper_bound = int(n * math.log(n) + n * math.log(math.log(n)))
    if upper_bound < 20:
        upper_bound = 20
    
    # Sieve of Eratosthenes
    is_prime_list = [True] * (upper_bound + 1)
    is_prime_list[0] = is_prime_list[1] = False
    
    for i in range(2, int(math.sqrt(upper_bound)) + 1):
        if is_prime_list[i]:
            for j in range(i * i, upper_bound + 1, i):
                is_prime_list[j] = False
    
    # Collect primes
    primes = []
    for i in range(2, upper_bound + 1):
        if is_prime_list[i]:
            primes.append(i)
            if len(primes) == n:
                return i
    
    # If not enough primes found, extend search
    return nth_prime_brute_force(n)


def get_first_n_primes(n):
    """
    Get list of first n prime numbers
    Time Complexity: O(n * √n)
    Space Complexity: O(n)
    """
    if n <= 0:
        return []
    
    primes = []
    num = 2
    
    while len(primes) < n:
        if is_prime(num):
            primes.append(num)
        num += 1
    
    return primes


def get_primes_in_range(start, end):
    """
    Get all prime numbers in a given range
    Time Complexity: O((end - start) * √n)
    Space Complexity: O(k) where k is the number of primes
    """
    primes = []
    
    for num in range(start, end + 1):
        if is_prime(num):
            primes.append(num)
    
    return primes


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Find nth Prime Number")
    print("=" * 60)
    
    # Test Case 1 - 1st prime
    n1 = 1
    result1 = nth_prime_brute_force(n1)
    print(f"n = {n1}")
    print(f"{n1}st prime number: {result1}")
    
    # Test Case 2 - 5th prime
    n2 = 5
    result2 = nth_prime_brute_force(n2)
    result2_sieve = nth_prime_sieve_optimized(n2)
    print(f"\nn = {n2}")
    print(f"{n2}th prime number (brute force): {result2}")
    print(f"{n2}th prime number (sieve): {result2_sieve}")
    
    # Test Case 3 - 10th prime
    n3 = 10
    result3 = nth_prime_brute_force(n3)
    result3_sieve = nth_prime_sieve_optimized(n3)
    print(f"\nn = {n3}")
    print(f"{n3}th prime number (brute force): {result3}")
    print(f"{n3}th prime number (sieve): {result3_sieve}")
    
    # Test Case 4 - First 10 primes
    n4 = 10
    primes_list = get_first_n_primes(n4)
    print(f"\nFirst {n4} prime numbers:")
    print(primes_list)
    
    # Test Case 5 - 20th prime
    n5 = 20
    result5 = nth_prime_brute_force(n5)
    print(f"\nn = {n5}")
    print(f"{n5}th prime number: {result5}")
    
    # Test Case 6 - Primes in range
    start = 10
    end = 50
    primes_range = get_primes_in_range(start, end)
    print(f"\nPrime numbers in range [{start}, {end}]:")
    print(primes_range)
    print(f"Count: {len(primes_range)}")
    
    # Test Case 7 - 100th prime
    n7 = 100
    result7 = nth_prime_sieve_optimized(n7)
    print(f"\nn = {n7}")
    print(f"{n7}th prime number: {result7}")
