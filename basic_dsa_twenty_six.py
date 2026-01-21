"""
Basic DSA Problems - Two More Fundamental Questions
Simple and essential DSA problems for beginners
"""


# Problem 1: Check if a Number is Evil Number
# An Evil number is a number that has an even number of 1s in its binary representation
# Example: 3 in binary is 11 (has 2 ones, which is even), so 3 is Evil

def count_ones_in_binary(n):
    """
    Count number of 1s in binary representation
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    count = 0
    num = abs(n)
    
    while num > 0:
        if num % 2 == 1:
            count += 1
        num //= 2
    
    return count


def is_evil_number(n):
    """
    Check if a number is Evil number (even number of 1s in binary)
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n < 0:
        n = abs(n)
    
    ones_count = count_ones_in_binary(n)
    return ones_count % 2 == 0


def is_evil_number_bitwise(n):
    """
    Check if a number is Evil number using bitwise operations
    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    if n < 0:
        n = abs(n)
    
    count = 0
    while n > 0:
        count += n & 1  # Check if last bit is 1
        n >>= 1  # Right shift
    
    return count % 2 == 0


def get_evil_numbers_in_range(start, end):
    """
    Find all Evil numbers in a given range
    Time Complexity: O((end - start) * log n)
    Space Complexity: O(k) where k is the number of Evil numbers
    """
    evil_numbers = []
    
    for num in range(start, end + 1):
        if is_evil_number(num):
            evil_numbers.append(num)
    
    return evil_numbers


# Problem 2: Calculate Simple Interest
# Simple Interest = (Principal × Rate × Time) / 100

def calculate_simple_interest(principal, rate, time):
    """
    Calculate simple interest
    Simple Interest = (Principal × Rate × Time) / 100
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if principal < 0 or rate < 0 or time < 0:
        raise ValueError("Principal, rate, and time must be non-negative")
    
    return (principal * rate * time) / 100


def calculate_amount_simple_interest(principal, rate, time):
    """
    Calculate total amount with simple interest
    Amount = Principal + Simple Interest
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    interest = calculate_simple_interest(principal, rate, time)
    return principal + interest


def calculate_principal_from_interest(interest, rate, time):
    """
    Calculate principal from simple interest
    Principal = (Interest × 100) / (Rate × Time)
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if rate == 0 or time == 0:
        raise ValueError("Rate and time cannot be zero")
    
    if interest < 0 or rate < 0 or time < 0:
        raise ValueError("Interest, rate, and time must be non-negative")
    
    return (interest * 100) / (rate * time)


def calculate_time_from_interest(principal, interest, rate):
    """
    Calculate time from simple interest
    Time = (Interest × 100) / (Principal × Rate)
    Time Complexity: O(1)
    Space Complexity: O(1)
    """
    if principal == 0 or rate == 0:
        raise ValueError("Principal and rate cannot be zero")
    
    if principal < 0 or interest < 0 or rate < 0:
        raise ValueError("Principal, interest, and rate must be non-negative")
    
    return (interest * 100) / (principal * rate)


# Test cases
if __name__ == "__main__":
    print("=" * 60)
    print("Problem 1: Check if a Number is Evil Number")
    print("=" * 60)
    
    # Test Case 1 - Evil number 3
    num1 = 3
    result1 = is_evil_number(num1)
    result1_bitwise = is_evil_number_bitwise(num1)
    binary1 = bin(num1)[2:]
    ones1 = count_ones_in_binary(num1)
    print(f"Number: {num1}")
    print(f"Binary: {binary1}")
    print(f"Number of 1s: {ones1}")
    print(f"Is Evil number: {result1}")
    print(f"Is Evil number (bitwise): {result1_bitwise}")
    
    # Test Case 2 - Not Evil number 5
    num2 = 5
    result2 = is_evil_number(num2)
    binary2 = bin(num2)[2:]
    ones2 = count_ones_in_binary(num2)
    print(f"\nNumber: {num2}")
    print(f"Binary: {binary2}")
    print(f"Number of 1s: {ones2}")
    print(f"Is Evil number: {result2}")
    
    # Test Case 3 - Evil number 9
    num3 = 9
    result3 = is_evil_number(num3)
    binary3 = bin(num3)[2:]
    ones3 = count_ones_in_binary(num3)
    print(f"\nNumber: {num3}")
    print(f"Binary: {binary3}")
    print(f"Number of 1s: {ones3}")
    print(f"Is Evil number: {result3}")
    
    # Test Case 4 - Zero
    num4 = 0
    result4 = is_evil_number(num4)
    binary4 = bin(num4)[2:]
    ones4 = count_ones_in_binary(num4)
    print(f"\nNumber: {num4}")
    print(f"Binary: {binary4}")
    print(f"Number of 1s: {ones4}")
    print(f"Is Evil number: {result4}")
    
    # Test Case 5 - Find Evil numbers in range
    start = 1
    end = 20
    evil_nums = get_evil_numbers_in_range(start, end)
    print(f"\nEvil numbers in range [{start}, {end}]:")
    print(evil_nums)
    print(f"Count: {len(evil_nums)}")
    
    print("\n" + "=" * 60)
    print("Problem 2: Calculate Simple Interest")
    print("=" * 60)
    
    # Test Case 1 - Basic simple interest
    principal1 = 10000
    rate1 = 5
    time1 = 2
    interest1 = calculate_simple_interest(principal1, rate1, time1)
    amount1 = calculate_amount_simple_interest(principal1, rate1, time1)
    print(f"Principal: ₹{principal1}")
    print(f"Rate: {rate1}% per annum")
    print(f"Time: {time1} years")
    print(f"Simple Interest: ₹{interest1}")
    print(f"Total Amount: ₹{amount1}")
    
    # Test Case 2 - Different values
    principal2 = 5000
    rate2 = 7.5
    time2 = 3
    interest2 = calculate_simple_interest(principal2, rate2, time2)
    amount2 = calculate_amount_simple_interest(principal2, rate2, time2)
    print(f"\nPrincipal: ₹{principal2}")
    print(f"Rate: {rate2}% per annum")
    print(f"Time: {time2} years")
    print(f"Simple Interest: ₹{interest2}")
    print(f"Total Amount: ₹{amount2}")
    
    # Test Case 3 - Calculate principal from interest
    interest3 = 500
    rate3 = 5
    time3 = 2
    principal3 = calculate_principal_from_interest(interest3, rate3, time3)
    print(f"\nInterest: ₹{interest3}")
    print(f"Rate: {rate3}% per annum")
    print(f"Time: {time3} years")
    print(f"Principal: ₹{principal3}")
    
    # Test Case 4 - Calculate time from interest
    principal4 = 10000
    interest4 = 1500
    rate4 = 5
    time4 = calculate_time_from_interest(principal4, interest4, rate4)
    print(f"\nPrincipal: ₹{principal4}")
    print(f"Interest: ₹{interest4}")
    print(f"Rate: {rate4}% per annum")
    print(f"Time: {time4} years")
    
    # Test Case 5 - Zero interest
    principal5 = 10000
    rate5 = 0
    time5 = 5
    interest5 = calculate_simple_interest(principal5, rate5, time5)
    print(f"\nPrincipal: ₹{principal5}")
    print(f"Rate: {rate5}% per annum")
    print(f"Time: {time5} years")
    print(f"Simple Interest: ₹{interest5}")
