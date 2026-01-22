"""
Basic DSA Problems - One More Fundamental Question
Simple and essential DSA problems for beginners
"""


# Problem: Check if a Number is Emirp
# An Emirp is a prime number that when reversed is also a prime number (and different from the original)
# Example: 13 is Emirp because 13 is prime and 31 (reversed) is also prime
# Note: Palindromic primes like 11, 131 are NOT Emirp because reversed number is same

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


def reverse_number(n):
    """
    Reverse a number
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    reversed_num = 0
    num = abs(n)
    
    while num > 0:
        reversed_num = reversed_num * 10 + num % 10
        num //= 10
    
    return -reversed_num if n < 0 else reversed_num


def is_emirp(n):
    """
    Check if a number is Emirp
    An Emirp is a prime that when reversed is also prime and different from original
    Time Complexity: O(√n)
    Space Complexity: O(1)
    """
    if n < 2:
        return False
    
    # Check if number is prime
    if not is_prime(n):
        return False
    
    # Reverse the number
    reversed_n = reverse_number(n)
    
    # Check if reversed number is different and also prime
    if reversed_n == n:
        return False  # Palindromic primes are not Emirp
    
    return is_prime(reversed_n)


def get_emirp_numbers_in_range(start, end):
    """
    Find all Emirp numbers in a given range
    Time Complexity: O((end - start) * √n)
    Space Complexity: O(k) where k is the number of Emirp numbers
    """
    emirp_numbers = []
    
    for num in range(start, end + 1):
        if is_emirp(num):
            emirp_numbers.append(num)
    
    return emirp_numbers


def get_emirp_pair(n):
    """
    Get the Emirp pair (original, reversed) if number is Emirp
    Returns tuple (n, reversed_n) if Emirp, None otherwise
    Time Complexity: O(√n)
    Space Complexity: O(1)
    """
    if not is_emirp(n):
        return None
    
    reversed_n = reverse_number(n)
    return (n, reversed_n)


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem: Check if a Number is Emirp")
    print("=" * 60)
    
    # Test Case 1 - Emirp number 13
    num1 = 13
    result1 = is_emirp(num1)
    reversed1 = reverse_number(num1)
    pair1 = get_emirp_pair(num1)
    print(f"Number: {num1}")
    print(f"Reversed: {reversed1}")
    print(f"Is Emirp: {result1}")
    if pair1:
        print(f"Emirp pair: {pair1}")
    
    # Test Case 2 - Emirp number 17
    num2 = 17
    result2 = is_emirp(num2)
    reversed2 = reverse_number(num2)
    pair2 = get_emirp_pair(num2)
    print(f"\nNumber: {num2}")
    print(f"Reversed: {reversed2}")
    print(f"Is Emirp: {result2}")
    if pair2:
        print(f"Emirp pair: {pair2}")
    
    # Test Case 3 - Not Emirp (palindromic prime 11)
    num3 = 11
    result3 = is_emirp(num3)
    reversed3 = reverse_number(num3)
    print(f"\nNumber: {num3}")
    print(f"Reversed: {reversed3}")
    print(f"Is Emirp: {result3} (palindromic prime, not Emirp)")
    
    # Test Case 4 - Not Emirp (not prime)
    num4 = 15
    result4 = is_emirp(num4)
    print(f"\nNumber: {num4}")
    print(f"Is Emirp: {result4} (not prime)")
    
    # Test Case 5 - Emirp number 37
    num5 = 37
    result5 = is_emirp(num5)
    reversed5 = reverse_number(num5)
    pair5 = get_emirp_pair(num5)
    print(f"\nNumber: {num5}")
    print(f"Reversed: {reversed5}")
    print(f"Is Emirp: {result5}")
    if pair5:
        print(f"Emirp pair: {pair5}")
    
    # Test Case 6 - Find Emirp numbers in range
    start = 1
    end = 100
    emirp_nums = get_emirp_numbers_in_range(start, end)
    print(f"\nEmirp numbers in range [{start}, {end}]:")
    print(emirp_nums)
    print(f"Count: {len(emirp_nums)}")
    
    # Test Case 7 - Emirp number 79
    num7 = 79
    result7 = is_emirp(num7)
    reversed7 = reverse_number(num7)
    pair7 = get_emirp_pair(num7)
    print(f"\nNumber: {num7}")
    print(f"Reversed: {reversed7}")
    print(f"Is Emirp: {result7}")
    if pair7:
        print(f"Emirp pair: {pair7}")
