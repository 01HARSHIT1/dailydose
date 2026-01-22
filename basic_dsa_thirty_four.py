"""
Basic DSA Problems - One More Fundamental Question
Simple and essential DSA problems for beginners
"""


# Problem: Check if Two Numbers are Twin Primes
# Twin primes are pairs of prime numbers that differ by 2
# Example: (3, 5), (5, 7), (11, 13), (17, 19) are twin prime pairs

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


def are_twin_primes(a, b):
    """
    Check if two numbers are twin primes
    Twin primes are pairs of primes that differ by exactly 2
    Time Complexity: O(√a + √b)
    Space Complexity: O(1)
    """
    # Check if both are prime
    if not is_prime(a) or not is_prime(b):
        return False
    
    # Check if they differ by 2
    return abs(a - b) == 2


def get_twin_prime_pairs_in_range(start, end):
    """
    Find all twin prime pairs in a given range
    Time Complexity: O((end - start) * √n)
    Space Complexity: O(k) where k is the number of twin prime pairs
    """
    twin_pairs = []
    
    for num in range(start, end):
        if is_prime(num) and is_prime(num + 2) and (num + 2) <= end:
            twin_pairs.append((num, num + 2))
    
    return twin_pairs


def get_all_twin_primes_up_to(n):
    """
    Get all twin prime pairs up to n
    Time Complexity: O(n * √n)
    Space Complexity: O(k) where k is the number of twin prime pairs
    """
    twin_pairs = []
    
    # Start from 3 (first twin prime pair is (3, 5))
    for num in range(3, n - 1):
        if is_prime(num) and is_prime(num + 2):
            twin_pairs.append((num, num + 2))
    
    return twin_pairs


def count_twin_primes_in_range(start, end):
    """
    Count number of twin prime pairs in a given range
    Time Complexity: O((end - start) * √n)
    Space Complexity: O(1)
    """
    count = 0
    
    for num in range(start, end):
        if is_prime(num) and is_prime(num + 2) and (num + 2) <= end:
            count += 1
    
    return count


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Check if Two Numbers are Twin Primes")
    print("=" * 60)
    
    # Test Case 1 - Twin primes (3, 5)
    a1, b1 = 3, 5
    result1 = are_twin_primes(a1, b1)
    print(f"Numbers: ({a1}, {b1})")
    print(f"Are twin primes: {result1}")
    
    # Test Case 2 - Twin primes (5, 7)
    a2, b2 = 5, 7
    result2 = are_twin_primes(a2, b2)
    print(f"\nNumbers: ({a2}, {b2})")
    print(f"Are twin primes: {result2}")
    
    # Test Case 3 - Not twin primes (3, 7)
    a3, b3 = 3, 7
    result3 = are_twin_primes(a3, b3)
    print(f"\nNumbers: ({a3}, {b3})")
    print(f"Are twin primes: {result3}")
    
    # Test Case 4 - Not twin primes (4, 6) - not primes
    a4, b4 = 4, 6
    result4 = are_twin_primes(a4, b4)
    print(f"\nNumbers: ({a4}, {b4})")
    print(f"Are twin primes: {result4}")
    
    # Test Case 5 - Twin primes (11, 13)
    a5, b5 = 11, 13
    result5 = are_twin_primes(a5, b5)
    print(f"\nNumbers: ({a5}, {b5})")
    print(f"Are twin primes: {result5}")
    
    # Test Case 6 - Find twin prime pairs in range
    start = 1
    end = 50
    twin_pairs = get_twin_prime_pairs_in_range(start, end)
    print(f"\nTwin prime pairs in range [{start}, {end}]:")
    for pair in twin_pairs:
        print(f"({pair[0]}, {pair[1]})", end=" ")
    print(f"\nCount: {len(twin_pairs)}")
    
    # Test Case 7 - All twin primes up to 100
    n7 = 100
    all_twin_pairs = get_all_twin_primes_up_to(n7)
    print(f"\nAll twin prime pairs up to {n7}:")
    for i, pair in enumerate(all_twin_pairs):
        if i > 0 and i % 5 == 0:
            print()
        print(f"({pair[0]}, {pair[1]})", end=" ")
    print(f"\nTotal count: {len(all_twin_pairs)}")
